/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:06:24 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/10 19:18:35 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	free_list_next(t_plist *list)
{
	if (!list || !list->next)
		return ;
	free(list->next->nom);
	free(list->next->lien);
	free(list->next);
	list->next = NULL;
}

int			ft_check_new_room(t_plist *room, t_plist *list)
{
	while (list && list->next)
	{
		if (ft_strcmp(list->nom, room->next->nom) == 0)
		{
			free_list_next(room);
			return (0);
		}
		list = list->next;
	}
	return (1);
}

int			check_sup_start_end(char *str, int a, int d)
{
	char	*tmp;

	while (str[a] == '#' && str[a] != '\0')
	{
		a = a + ft_strclen(&str[a], '\n') + 1;
		if (str[a] != '\0' && str[a + 1] == '#')
		{
			tmp = ft_strccpy(&str[a + 2], '\n', 1);
			if (ft_strcmp("start\n", tmp) != 0 || ft_strcmp("end\n", tmp) != 0)
			{
				free(tmp);
				return (-1);
			}
			free(tmp);
		}
		else
			while (str[a] != '\n' && str[a] != '\0')
			{
				if (str[a] == ' ')
					return (d);
				a++;
			}
	}
	return (-1);
}
