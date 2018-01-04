/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:15:18 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/20 21:28:50 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim		new_t_tetrim(void)
{
	size_t		i;
	t_tetrim	new;

	i = 0;
	new = (t_tetrim)malloc(sizeof(char *) * 4);
	if (!new)
		return (NULL);
	while (i < 4)
	{
		new[i++] = (char *)malloc(4);
		if (!new[i - 1])
			return (NULL);
	}
	return (new);
}

t_tetriminos	*libere(t_tetrim t)
{
	size_t i;

	i = 0;
	while (i < 4)
		free(t[i++]);
	free(t);
	return (NULL);
}

char			*ft_strncpy_cust(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		l;

	l = n;
	i = 0;
	while (*src && *src != '\n' && l--)
	{
		if (*src != '.' && *src != '#')
			return (NULL);
		dest[i++] = *(src++);
	}
	if (l != 0)
		return (NULL);
	return (dest);
}

t_tetriminos	*lire_t_tetrim(int fd)
{
	int				y;
	t_tetrim		new;
	t_tetriminos	*new_final;
	char			buff[5];

	y = 0;
	new = new_t_tetrim();
	while (y < 4 && read(fd, buff, 5))
	{
		if (!ft_strncpy_cust(new[y++], buff, 4))
			return (libere(new));
	}
	if (y == 0)
		g_fin = 1;
	if (read(fd, buff, 1) || y != 4)
	{
		if (buff[0] != '\n' || y != 4)
			return (libere(new));
	}
	new_final = verif_minim(new);
	if (!new_final)
		libere(new);
	return (new_final);
}
