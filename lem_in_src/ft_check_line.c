/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:48:49 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 22:35:45 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	check_s_or_e(char *s)
{
	int		a;
	char	*t;

	a = 0;
	if (s[0] == '#')
	{
		if (s[1] == '#')
		{
			t = ft_strccpy(&s[2], '\n', 1);
			if (ft_strccmp(t, "start\n", '\n') == 1)
				a = 1;
			else if (ft_strccmp(t, "end\n", '\n') == 1)
				a = 2;
			free(t);
		}
		if (a == 0)
			a = 4;
	}
	return (a);
}

static int	checkcheck(char *str, int start, int end, int fourmi)
{
	int		a;
	int		b;

	a = ft_is_int(str, '\n', 1);
	if (a == 1 && fourmi == 0)
		return (3);
	else if (a == 1 && fourmi != 0)
		return (0);
	b = check_s_or_e(str);
	if (b == 1 && (start == 1 || fourmi == 0))
		return (0);
	else if (b == 2 && (end == 1 || fourmi == 0))
		return (0);
	return (b);
}

static int	check_room(char *str, int a, int b)
{
	while (str[a] != '\n' && str[a] != '\0')
	{
		if (str[a] == ' ')
			b++;
		a++;
	}
	if (b != 2)
		return (0);
	a = 0;
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	while (str[a] != ' ' && str[a] != '\n' && str[a] != '\0')
	{
		if (str[a] < 32 || str[a] == '-')
			return (0);
		a++;
	}
	a++;
	if (ft_is_int(&str[a], ' ', 1) == 0)
		return (0);
	a = a + ft_strclen(&str[a], ' ') + 1;
	if (ft_is_int(&str[a], '\n', 1) == 0)
		return (0);
	return (1);
}

static int	check_link(char *str)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (str[a] != '\n' && str[a] != '\0')
	{
		if (str[a] <= 32)
			return (0);
		if (str[a] == '-')
			if (a > 0 && str[a - 1] != '\n' && str[a + 1] != '\n'
					&& str[a + 1] != '\0' && str[a + 1] != 'L'
					&& str[a + 1] != '#')
				b++;
		a++;
	}
	if (b == 1)
		return (1);
	return (0);
}

int			check_line(char *str, int start, int end, int fourmi)
{
	int		a;
	int		b;

	a = ft_strlen(str) - 1;
	while (a > 0 && str[a - 1] != '\n')
		a--;
	if (str[a] == 'L')
		return (0);
	b = checkcheck(&str[a], start, end, fourmi);
	if (b != 0)
		return (b);
	if (check_room(&str[a], 0, 0) == 1 && fourmi != 0)
		return (5);
	if (check_link(&str[a]) == 1 && fourmi != 0)
		return (6);
	return (0);
}
