/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:10:22 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/10 19:01:08 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int		check_room_link(char *str, int a, int d)
{
	char	*tmp;

	tmp = NULL;
	while (str[a] != '\n' && str[a] != '\0')
	{
		if (str[a] == '#')
		{
			tmp = ft_strccpy(&str[a + 2], '\n', 1);
			if ((ft_strcmp("start\n", tmp) == 0 && (d = 3))
					|| (ft_strcmp("end\n", tmp) == 0 && (d = 4)))
			{
				free(tmp);
				d = check_sup_start_end(str, a, d);
				return (d);
			}
			free(tmp);
			return (0);
		}
		if (str[a] == ' ')
			return (1);
		else if (str[a] == '-')
			return (2);
		a++;
	}
	return (0);
}

static t_check	*create_room(char *str, int a, t_check *check, int b)
{
	t_plist	*list;

	while (check->list && check->list->next)
		check->list = check->list->next;
	check->list->next = ft_newroom(check->list, str, a, b);
	list = check->b_list;
	if (ft_check_new_room(check->list, list) == 0)
	{
		check->a = 0;
		return (check);
	}
	check->list = check->list->next;
	if (check_name_coor(check->b_list) == 0)
	{
		check->a = 0;
		return (check);
	}
	check->a = 1;
	return (check);
}

static t_plist	*c_link(t_plist *b_list, t_plist *list, char *c, char *d)
{
	int		a;
	t_plist	*tmp;

	a = -1;
	tmp = list;
	while (list && ft_strcmp(list->nom, c) != 0)
		list = list->next;
	while (tmp && ft_strcmp(tmp->nom, d) != 0)
		tmp = tmp->next;
	if (!tmp || !list)
		return (NULL);
	if (ft_strcmp(list->nom, c) != 0 || ft_strcmp(tmp->nom, d) != 0)
		return (NULL);
	if (!list->lien)
		list->lien = ft_initlien(tmp->salle, nb_rooms(b_list));
	else
		list->lien[list->nb_lien] = tmp->salle;
	while (a++ && a < list->nb_lien)
		if (tmp->salle == list->lien[a])
		{
			list->lien[list->nb_lien] = -1;
			list->nb_lien--;
		}
	list->nb_lien++;
	return (b_list);
}

static t_check	*ft_link(t_check *check, char *str, int a)
{
	int		b;
	char	*tmp;
	char	*tmp2;

	b = 0;
	while (str[a + b] != '-')
		b++;
	tmp = ft_strccpy(&str[a], '-', 0);
	tmp2 = ft_strccpy(&str[a + b + 1], '\n', 0);
	check->list = c_link(check->b_list, check->b_list, tmp, tmp2);
	if (check->list == NULL)
	{
		check->a = 0;
		free(tmp);
		free(tmp2);
		return (check);
	}
	check->list = c_link(check->b_list, check->list, tmp2, tmp);
	free(tmp);
	free(tmp2);
	return (check);
}

t_check			*ft_parsing(char *str, t_check *check, int a, int c)
{
	int		b;

	b = 0;
	while (str[a] != '\0' && check->a != 0 && b != -1)
	{
		b = check_room_link(str, a, 0);
		if (b == 1 || b == 3 || b == 4)
		{
			if (!check->list && check->a != 0)
			{
				check->list = ft_newroom(check->list, str, a, c);
				check->b_list = check->list;
			}
			else if (check->a != 0)
				check = create_room(str, a, check, c);
			while (str[a] == '#')
				a = a + ft_strclen(&str[a], '\n') + 1;
			c++;
		}
		else if (b == 2)
			check = ft_link(check, str, a);
		a = a + ft_strclen(&str[a], '\n') + 1;
	}
	check->str = a;
	return (check);
}
