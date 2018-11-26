/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:44:08 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/10 19:01:43 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_free_list(t_plist *list)
{
	t_plist	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->lien);
		free(list->nom);
		free(list);
		list = tmp;
	}
	return (0);
}

int			*ft_initlien(int c, int lenght)
{
	int		a;
	int		*tab;

	a = 1;
	if (!(tab = (int*)malloc(sizeof(int) * lenght)))
		return (NULL);
	tab[0] = c;
	while (a < lenght)
	{
		tab[a] = -1;
		a++;
	}
	return (tab);
}

int			nb_rooms(t_plist *list)
{
	int		a;

	a = 0;
	while (list)
	{
		a++;
		list = list->next;
	}
	return (a);
}

char		*ft_strccpy(char *str, char c, int b)
{
	int		a;
	char	*tmp;

	a = 0;
	while (str[a] != c && str[a] != '\0')
		a++;
	if (!(tmp = (char*)malloc(sizeof(char) * (a + 1 + b))))
		return (NULL);
	a = 0;
	while (str[a] != c && str[a] != '\0')
	{
		tmp[a] = str[a];
		a++;
	}
	tmp[a] = str[a];
	tmp[a + b] = '\0';
	return (tmp);
}

int			check_name_coor(t_plist *list)
{
	t_plist	*tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (ft_strcmp(tmp->nom, list->nom) == 0
					|| (list->x == tmp->x && list->y == tmp->y))
				return (0);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (1);
}
