/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmi_tools3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:05:36 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 20:48:23 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			check_if_path(t_path *path)
{
	int		a;

	a = 0;
	while (path)
	{
		if (path->lenght == 2)
			return (-1);
		if (path->lenght > 2)
			a++;
		path = path->next;
	}
	return (a);
}

t_fourmi	*unused_fourmi(t_fourmi *fourmi)
{
	while (fourmi)
	{
		if (fourmi->nb_road == 0)
			return (fourmi);
		fourmi = fourmi->next;
	}
	return (fourmi);
}
