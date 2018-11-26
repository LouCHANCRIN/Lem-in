/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:08:35 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 13:25:25 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		select_good_path(t_path *path, t_path *tmp, int a, int b)
{
	while (path && path->next)
	{
		tmp = path->next;
		while (tmp && (a = 1))
		{
			while (a < path->lenght - 1)
			{
				b = 1;
				while (b < tmp->lenght - 1)
				{
					if (path->road[a] == tmp->road[b])
					{
						if (path->lenght > tmp->lenght)
							path->lenght = -1;
						else
							tmp->lenght = -1;
					}
					b++;
				}
				a++;
			}
			tmp = tmp->next;
		}
		path = path->next;
	}
}

static t_path	*last_path(t_path *path)
{
	while (path && path->next)
		path = path->next;
	return (path);
}

static t_path	*check_path(t_plist *l, t_plist *b_list, t_path *p, int len)
{
	int		a;

	a = 0;
	p = last_path(p);
	p->road = fill_tab(p->road, l->salle, len);
	if (l->end == 1)
	{
		p->next = create_path(p->road, len);
		p = p->next;
		p->road = rm_last_number(p->road, len);
		return (p);
	}
	while (a < l->nb_lien)
	{
		if (check_if_possible(p->road, l->lien[a], len) == 1)
			p = check_path(find_room(b_list, l->lien[a]), b_list, p, len);
		a++;
	}
	if (check_tab(p->road, ft_end(b_list), len) == 1)
	{
		p->next = create_path(p->road, len);
		p = p->next;
	}
	p->road = rm_last_number(p->road, len);
	return (p);
}

t_path			*algo(t_plist *list, t_plist *b_list, int a, int len)
{
	int		c;
	int		*tab;
	t_path	*path;
	t_path	*b_path;

	c = 0;
	len = list_lenght(b_list);
	if (!(tab = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (c < len)
	{
		tab[c] = -1;
		c++;
	}
	path = create_path(tab, len);
	b_path = path;
	free(tab);
	while (list && list->start != 1)
		list = list->next;
	list->fourmi = a;
	check_path(list, b_list, path, len);
	path_len(path, len);
	select_good_path(path, path, 0, 0);
	return (b_path);
}
