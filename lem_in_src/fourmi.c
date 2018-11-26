/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:46:50 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 21:34:38 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	check_if_fourmi_left(t_fourmi *fourmi)
{
	while (fourmi)
	{
		if (fourmi->nb_road > 0)
			return (1);
		fourmi = fourmi->next;
	}
	return (0);
}

static void	mv_placed_fourmi(t_fourmi *fourmi, t_path *b_path, t_plist *list)
{
	int		a;
	t_path	*path;

	while (fourmi)
	{
		a = 1;
		if (fourmi->nb_road > 0)
		{
			path = find_path(b_path, fourmi->nb_road);
			fourmi->step++;
			if (fourmi->next && check_if_fourmi_left(fourmi->next) == 1)
				a = 0;
			if (fourmi->nb_road > 0)
				affiche_fourmi(list, fourmi->x, path->road[fourmi->step], a);
			if (fourmi->step == path->lenght - 1)
				fourmi->nb_road = -1;
		}
		fourmi = fourmi->next;
	}
}

static int	select_path(t_path *path, t_fourmi *fourmi, int nb_f, int a)
{
	t_path		*next;
	t_fourmi	*b_fourmi;

	b_fourmi = fourmi;
	fourmi = unused_fourmi(b_fourmi);
	while (path && fourmi)
	{
		if (!fourmi)
			return (a - nb_f);
		next = path->next;
		if (!next)
		{
			fourmi->nb_road = path->nom;
			nb_f--;
		}
		else if (nb_f + next->lenght >= path->lenght)
		{
			fourmi->nb_road = path->nom;
			fourmi = fourmi->next;
			nb_f--;
		}
		path = path->next;
	}
	return (a - nb_f);
}

static int	mv_fourmi2(t_path *path, t_fourmi *fourmi, t_plist *l, int nb_f)
{
	int			end;
	int			nb_tours;

	end = ft_end(l);
	nb_tours = 0;
	while (check_if_done(fourmi, end) == 0)
	{
		if (nb_f > 0)
			nb_f = nb_f - select_path(path, fourmi, nb_f, nb_f);
		mv_placed_fourmi(fourmi, path, l);
		nb_tours++;
	}
	free_list_path(path);
	free_list_fourmi(fourmi);
	return (nb_tours);
}

void		mv_fourmi(t_path *path, t_plist *b_list, t_bonus *b, char *str)
{
	int			a;
	int			x;
	int			tours;
	int			nb_fourmi;
	t_fourmi	*fourmi;

	a = 0;
	nb_fourmi = b->nb_fourmi;
	if (check_nb_path(path, path) <= 0 && free_bonus(b) == 1)
		return ;
	else
		fourmi = new_fourmi(1, path->road[0]);
	fourmi = init_fourmi(fourmi, fourmi, nb_fourmi, path->road[0]);
	a = check_if_path(path);
	if (a == 0 && free_bonus(b) == 1)
		return (ret_error(path, fourmi));
	x = bonus(path, b_list, b, str);
	if (a == -1)
		return (mv_all(fourmi, path, b_list, x));
	tours = mv_fourmi2(path, fourmi, b_list, nb_fourmi);
	if (x == 1)
		bonus_tours(tours);
}
