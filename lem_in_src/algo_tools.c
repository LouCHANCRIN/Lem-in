/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:08:35 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 13:26:54 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		*fill_tab(int *tab, int salle, int lenght)
{
	int		a;

	a = 0;
	while (tab[a] != -1 && a < lenght)
		a++;
	tab[a] = salle;
	return (tab);
}

t_plist	*find_room(t_plist *list, int salle)
{
	while (list && list->next)
	{
		if (list->salle == salle)
			return (list);
		list = list->next;
	}
	return (list);
}

int		*rm_last_number(int *tab, int lenght)
{
	int		a;

	a = 0;
	while (a < lenght && tab[a] != -1)
		a++;
	if (a > 0)
		tab[a - 1] = -1;
	return (tab);
}

int		check_if_possible(int *tab, int lien, int len)
{
	int		a;

	a = 0;
	while (a < len)
	{
		if (tab[a] == lien)
			return (-1);
		a++;
	}
	return (1);
}
