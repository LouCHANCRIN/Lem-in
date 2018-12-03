/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:58:38 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/09 13:28:48 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

char	*ft_strjoinfree(char *s, char *t)
{
	int		a;
	int		b;
	char	*r;

	if (s == NULL || t == NULL)
		return (NULL);
	if (!(r = (char*)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(t) + 1))))
		return (NULL);
	a = 0;
	b = 0;
	while (s[a] != '\0')
	{
		r[a] = s[a];
		a++;
	}
	while (t[b] != '\0')
	{
		r[a + b] = t[b];
		b++;
	}
	r[a + b] = '\0';
	free(s);
	return (r);
}