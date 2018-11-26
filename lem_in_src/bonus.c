/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:48:27 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/10 20:20:57 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	affiche_nb_path(t_path *path)
{
	int		a;

	a = 0;
	while (path)
	{
		a++;
		path = path->next;
	}
	ft_putnbr(a);
	if (a == 1)
		write(1, " chemin\n\n", 9);
	else
		write(1, " chemins\n\n", 10);
}

static void	affiche_all_path(t_path *path, t_plist *list, int len)
{
	int		a;
	t_plist	*b_list;

	b_list = list;
	while (path)
	{
		write(1, "     ", 5);
		a = 0;
		if (len == 1)
			affiche_len(path->lenght);
		while (a < path->lenght)
		{
			list = find_room(b_list, path->road[a]);
			write(1, list->nom, ft_strlen(list->nom));
			if (a + 1 == path->lenght)
				write(1, "\n", 1);
			else
				write(1, "->", 2);
			a++;
		}
		path = path->next;
	}
	write(1, "\n", 1);
}

static void	affiche_best_path(t_path *path, t_plist *list, int len)
{
	int		a;
	t_plist	*b_list;

	a = 0;
	b_list = list;
	write(1, "     ", 5);
	if (path)
	{
		if (len == 1)
			affiche_len(path->lenght);
		while (a < path->lenght)
		{
			list = find_room(b_list, path->road[a]);
			write(1, list->nom, ft_strlen(list->nom));
			if (a + 1 == path->lenght)
				write(1, "\n", 1);
			else
				write(1, "->", 2);
			a++;
		}
	}
	write(1, "\n", 1);
}

static void	bonus2(t_path *path, t_plist *list, t_bonus *bonus)
{
	if (bonus->chemin == 1)
	{
		write(1, "Chemins:\n", 9);
		affiche_all_path(path, list, bonus->lenght);
	}
	if (bonus->best == 1)
	{
		write(1, "Meilleur chemin:\n", 17);
		affiche_best_path(path, list, bonus->lenght);
	}
	if (bonus->nb_path == 1)
	{
		write(1, "Nombre de chemins : ", 20);
		affiche_nb_path(path);
	}
}

int			bonus(t_path *path, t_plist *list, t_bonus *bonus, char *str)
{
	int		a;
	int		tour;

	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	a = 1;
	tour = 0;
	while (a < bonus->ac)
	{
		if (bonus->best == 0 && ft_strcmp(bonus->av[a], "-b") == 0)
			bonus->best++;
		if (bonus->lenght == 0 && ft_strcmp(bonus->av[a], "-l") == 0)
			bonus->lenght++;
		if (bonus->chemin == 0 && ft_strcmp(bonus->av[a], "-c") == 0)
			bonus->chemin++;
		if (tour == 0 && ft_strcmp(bonus->av[a], "-t") == 0)
			tour++;
		if (bonus->nb_path == 0 && ft_strcmp(bonus->av[a], "-n") == 0)
			bonus->nb_path++;
		a++;
	}
	bonus2(path, list, bonus);
	free(bonus);
	return (tour);
}
