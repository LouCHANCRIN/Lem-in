/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmi_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:13:27 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 20:45:41 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		free_list_fourmi(t_fourmi *fourmi)
{
	t_fourmi	*tmp;

	while (fourmi)
	{
		tmp = fourmi;
		fourmi = fourmi->next;
		free(tmp);
	}
}

void		free_list_path(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		free(tmp->road);
		free(tmp);
	}
}

int			check_nb_path(t_path *path, t_path *b_path)
{
	int		a;

	a = 0;
	while (path)
	{
		if (path->lenght > 1)
			a++;
		path = path->next;
	}
	if (a == 0)
	{
		write(1, "ERROR\n", 6);
		free_list_path(b_path);
	}
	return (a);
}

t_fourmi	*init_fourmi(t_fourmi *fourmi, t_fourmi *b_fourmi, int f, int s)
{
	int		a;

	a = 2;
	while (a <= f)
	{
		fourmi->next = new_fourmi(a, s);
		fourmi = fourmi->next;
		a++;
	}
	return (b_fourmi);
}

void		affiche_fourmi(t_plist *list, int fourmi, int salle, int last_char)
{
	list = find_room(list, salle);
	write(1, "L", 1);
	ft_putnbr(fourmi);
	write(1, "-", 1);
	write(1, list->nom, ft_strlen(list->nom));
	if (last_char == 0)
		write(1, " ", 1);
	else
		write(1, "\n", 1);
}
