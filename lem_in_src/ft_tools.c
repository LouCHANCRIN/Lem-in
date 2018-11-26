/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:41:25 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 13:28:57 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_end(t_plist *list)
{
	if (list && list->next)
		while (list)
		{
			if (list->end == 1)
				return (list->salle);
			list = list->next;
		}
	return (-1);
}

int			ft_strccmp(const char *s1, const char *s2, char c)
{
	int		a;

	a = 0;
	while (s1[a] == s2[a] && s1[a] != '\0' && s1[a] != c)
		a++;
	if (s1[a] == s2[a])
		return (1);
	return (0);
}

static int	ft_s_or_e(char *str, int b)
{
	while (str[b] != '\n' && str[b] != '\0')
	{
		if (str[b] == '#' && str[b + 1] == '#')
		{
			if (ft_strccmp(&str[b + 2], "start\n", '\n') == 1)
				return (1);
			if (ft_strccmp(&str[b + 2], "end\n", '\n') == 1)
				return (2);
		}
		b++;
	}
	return (0);
}

static int	ft_x_y(char *str, int a, int b)
{
	a = a + ft_strclen(&str[a], ' ');
	if (b == 2)
		a = a + ft_strclen(&str[a + 1], ' ') + 1;
	return (ft_atoi(&str[a]));
}

t_plist		*ft_newroom(t_plist *list, char *str, int a, int b)
{
	if (!(list = (t_plist*)malloc(sizeof(t_plist))))
		return (NULL);
	list->salle = b;
	list->start = (ft_s_or_e(str, a) == 1) ? 1 : 0;
	list->end = (ft_s_or_e(str, a) == 2) ? 1 : 0;
	while (str[a] == '#')
		a = a + ft_strclen(&str[a], '\n') + 1;
	b = ft_strclen(&str[a], ' ');
	if (!(list->nom = (char*)malloc(sizeof(char) * (b + 1))))
		return (NULL);
	list->nom = ft_strncpy(list->nom, &str[a], b);
	b = 0;
	while (list->nom[b] != '\0')
		b++;
	list->fourmi = 0;
	list->nb_lien = 0;
	list->lien = NULL;
	list->next = NULL;
	list->x = ft_x_y(str, a, 1);
	list->y = ft_x_y(str, a, 2);
	return (list);
}
