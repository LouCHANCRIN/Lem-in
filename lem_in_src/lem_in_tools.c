/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 12:51:27 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/10 19:18:30 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_norme	*init_norme(void)
{
	t_norme	*norme;

	if (!(norme = (t_norme*)malloc(sizeof(t_norme))))
		return (NULL);
	norme->a = 0;
	norme->b = 0;
	norme->check = 0;
	norme->fourmi = 0;
	norme->start = 0;
	norme->end = 0;
	norme->next = NULL;
	return (norme);
}

t_check	*init_check(void)
{
	t_check	*check;

	if (!(check = (t_check*)malloc(sizeof(t_check))))
		return (NULL);
	check->a = 1;
	check->str = 0;
	check->list = NULL;
	check->b_list = NULL;
	return (check);
}

int		error_string(char *str, t_check *check)
{
	if (str)
		free(str);
	if (check)
		free(check);
	write(1, "ERROR\n", 6);
	return (0);
}

int		free_str(char *str)
{
	free(str);
	return (0);
}

int		error_list(char *str, t_plist *list)
{
	if (str)
		free(str);
	ft_free_list(list);
	write(1, "ERROR\n", 6);
	return (0);
}
