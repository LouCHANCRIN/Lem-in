/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:28:22 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 19:56:12 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			path_len(t_path *path, int len)
{
	int		a;
	int		b;

	b = 1;
	while (path)
	{
		a = 0;
		while (a < len && path->road[a] != -1)
			a++;
		path->lenght = a;
		path->nom = b;
		path = path->next;
		b++;
	}
}

t_path			*create_path(int *tab, int lenght)
{
	int		a;
	t_path	*path;

	a = 0;
	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	if (!(path->road = (int*)malloc(sizeof(int) * lenght)))
		return (NULL);
	while (a < lenght)
	{
		path->road[a] = tab[a];
		a++;
	}
	path->lenght = lenght;
	path->next = NULL;
	return (path);
}

static t_path	*sort_path(t_path *b_path, t_path *path, int a, int b)
{
	int		*swap;
	t_path	*tmp;

	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			if (tmp->lenght < path->lenght)
			{
				swap = path->road;
				a = path->lenght;
				path->road = tmp->road;
				path->lenght = tmp->lenght;
				tmp->road = swap;
				tmp->lenght = a;
			}
			tmp = tmp->next;
		}
		path->nom = b;
		b++;
		path = path->next;
	}
	return (b_path);
}

t_path			*rm_wrong_path(t_path *path)
{
	t_path	*tmp;
	t_path	*b_path;

	while (path && path->lenght < 2)
	{
		tmp = path;
		path = path->next;
		free(tmp->road);
		free(tmp);
	}
	b_path = path;
	while (path && path->next)
	{
		if (path->next && path->next->lenght < 2)
		{
			tmp = path->next;
			path->next = tmp->next;
			free(tmp->road);
			free(tmp);
		}
		else
			path = path->next;
	}
	b_path = sort_path(b_path, b_path, 0, 1);
	return (b_path);
}
