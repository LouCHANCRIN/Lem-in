/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 21:43:38 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 22:04:10 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		affiche_len(int len)
{
	write(1, "longueur = ", 11);
	ft_putnbr(len);
	write(1, ", ", 2);
}

void		bonus_tours(int tours)
{
	write(1, "\nNombre de tours : ", 19);
	ft_putnbr(tours);
	if (tours == 1)
		write(1, " tour\n", 6);
	else
		write(1, " tours\n", 7);
}
