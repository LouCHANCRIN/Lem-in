/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:39:07 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/10 19:18:33 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_nb_fourmi(char *str)
{
	int		a;

	a = 0;
	if (!str)
		return (-1);
	while (str[a] == '#')
		a = a + ft_strclen(&str[a], '\n') + 1;
	if (str[a] == '\0' || (!(str[a] >= 48 && str[a] <= 57)
				&& str[a] != '+' && str[a] != '-'))
		return (-1);
	return (ft_atoi(&str[a]));
}

static char	*ft_rm_last_row(char *str, t_norme *norme)
{
	int		a;
	int		b;
	char	*tmp;

	a = 0;
	b = ft_strlen(str) - 2;
	tmp = NULL;
	if (b > 0)
	{
		while (str[b] != '\n' && b > 0)
			b--;
		if (b == 0)
		{
			free(norme);
			free(str);
			return (NULL);
		}
		if (!(tmp = (char*)malloc(sizeof(char) * (b + 2))))
			return (NULL);
		tmp = ft_strncpy(tmp, str, (size_t)b + 1);
	}
	free(str);
	free(norme);
	return (tmp);
}

static char	*error_get_file(char *str, t_norme *norme)
{
	free(norme);
	free(str);
	return (NULL);
}

static char	*get_file(char *str, t_norme *n)
{
	char	buf[2];

	while ((n->a = read(0, buf, 1)) > 0 && str)
	{
		n->check = -1;
		buf[n->a] = '\0';
		str = ft_strjoinfree(str, buf);
		if (buf[n->a - 1] == '\0')
			return (error_get_file(str, n));
		if (buf[n->a - 1] == '\n' && str)
			n->check = check_line(str, n->start, n->end, n->fourmi);
		if (n->check == 1)
			n->start = 1;
		else if (n->check == 2)
			n->end = 1;
		else if (n->check == 3)
			n->fourmi = 1;
		else if (n->check == 6 && n->b != 1)
			n->b = 1;
		else if (n->check == 0 || (n->b == 1 && n->check != 6 && n->check != -1
					&& n->check != 4))
			return (ft_rm_last_row(str, n));
	}
	free(n);
	return (str);
}

int			main(int ac, char **av)
{
	int		a;
	char	*str;
	t_plist	*list;
	t_check	*check;
	t_path	*path;

	list = NULL;
	check = init_check();
	if (!(str = (char*)malloc(sizeof(char))))
		return (0);
	str[0] = '\0';
	str = get_file(str, init_norme());
	a = ft_nb_fourmi(str);
	if (!str || str[0] == '\n' || a <= 0)
		return (error_string(str, check));
	check = ft_parsing(str, check, 0, 0);
	list = check->b_list;
	if (!(str = check_str(str, check)))
		return (free_list_print_error(list));
	if (!list || list->fourmi == -1 || a <= 0 || check_if_start_end(list) != 1)
		return (error_list(str, list));
	path = algo(list, list, a, 0);
	path = rm_wrong_path(path);
	mv_fourmi(path, list, set_bonus(a, ac, av), str);
	return (ft_free_list(list) + free_str(str));
}
