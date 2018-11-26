/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:31:47 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/10 19:01:51 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			check_if_start_end(t_plist *list)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (list)
	{
		if (list->start == 1)
			start++;
		if (list->end == 1)
			end++;
		list = list->next;
	}
	if (start != 1 || end != 1)
		return (0);
	return (1);
}

int			free_list_print_error(t_plist *list)
{
	ft_free_list(list);
	write(1, "ERROR\n", 6);
	return (1);
}

char		*check_str(char *str, t_check *check)
{
	int		a;
	char	*tmp;

	a = check->str - 2;
	if (check->a == 0)
	{
		while (a > 0 && str[a] != '\n')
			a--;
		if (a == 0)
		{
			free(str);
			return (NULL);
		}
		if (!(tmp = (char*)malloc(sizeof(char) * (a + 2))))
			return (NULL);
		tmp = ft_strncpy(tmp, str, (size_t)a + 1);
		free(str);
		free(check);
		return (tmp);
	}
	free(check);
	return (str);
}
