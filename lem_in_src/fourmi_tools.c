/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmi_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:54:39 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 21:19:58 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_fourmi	*new_fourmi(int fourmi, int start)
{
	t_fourmi	*f;

	if (!(f = (t_fourmi*)malloc(sizeof(t_fourmi))))
		return (NULL);
	f->x = fourmi;
	f->nb_road = 0;
	f->step = 0;
	f->room = start;
	f->next = NULL;
	return (f);
}

void		mv_all(t_fourmi *fourmi, t_path *path, t_plist *list, int x)
{
	t_fourmi	*b_fourmi;
	t_path		*b_path;

	b_path = path;
	b_fourmi = fourmi;
	list = find_room(list, path->road[1]);
	while (fourmi)
	{
		if (fourmi->next)
			affiche_fourmi(list, fourmi->x, path->road[1], 0);
		else
			affiche_fourmi(list, fourmi->x, path->road[1], 1);
		fourmi = fourmi->next;
	}
	free_list_fourmi(b_fourmi);
	free_list_path(b_path);
	if (x == 1)
		bonus_tours(1);
}

int			check_if_done(t_fourmi *fourmi, int end)
{
	end = 0;
	while (fourmi)
	{
		if (fourmi->nb_road != -1)
			return (0);
		fourmi = fourmi->next;
	}
	return (1);
}

t_path		*find_path(t_path *path, int road)
{
	while (path)
	{
		if (road == path->nom)
			return (path);
		path = path->next;
	}
	return (path);
}

void		ret_error(t_path *path, t_fourmi *fourmi)
{
	write(1, "ERROR\n", 6);
	free_list_fourmi(fourmi);
	free_list_path(path);
}
