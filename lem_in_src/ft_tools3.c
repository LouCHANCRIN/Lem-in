/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:35:51 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 22:46:02 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		ft_is_int(char *s, char c, int signe)
{
	int			a;
	long long	b;

	a = signe;
	b = ft_atoll(s);
	if (signe == 1)
		if (s[0] != '-' && s[0] != '+' && !(s[0] >= 48 && s[0] <= 57))
			return (0);
	while (s[a] != '\0' && s[a] != c)
	{
		if (!(s[a] >= 48 && s[a] <= 57))
			return (0);
		a++;
	}
	if (s[a] == c || s[a] == '\0')
		if ((b < -2147483648 || b > 2147483647) || a > 11
				|| (ft_strlen(s) > 1 && (s[0] == '+' || s[0] == '-')
					&& !(s[1] >= 48 && s[1] <= 57)))
			return (0);
	if (s[0] == '-')
		return (-1);
	return (1);
}

int		check_tab(int *tab, int end, int lenght)
{
	int		a;

	a = 0;
	while (a < lenght)
	{
		if (tab[a] == end)
			return (1);
		if (tab[a] == -1)
			return (0);
		a++;
	}
	return (0);
}

int		list_lenght(t_plist *list)
{
	int		a;

	a = 0;
	while (list && list->next)
	{
		list = list->next;
		a++;
	}
	return (a + 1);
}

int		free_bonus(t_bonus *bonus)
{
	free(bonus);
	return (1);
}

t_bonus	*set_bonus(int nb_fourmi, int ac, char **av)
{
	t_bonus	*bonus;

	if (!(bonus = (t_bonus*)malloc(sizeof(t_bonus))))
		return (NULL);
	bonus->best = 0;
	bonus->chemin = 0;
	bonus->lenght = 0;
	bonus->nb_path = 0;
	bonus->nb_fourmi = nb_fourmi;
	bonus->ac = ac;
	bonus->av = av;
	bonus->next = NULL;
	return (bonus);
}
