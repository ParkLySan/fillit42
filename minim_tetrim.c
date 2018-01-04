/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minim_tetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:59:48 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/21 18:32:48 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			minimise(int *tab)
{
	size_t i;

	i = 0;
	while (i < 4 && tab[i] != 0)
		i++;
	if (i == 4)
	{
		i = 0;
		while (i < 4)
			tab[i++]--;
		return (minimise(tab));
	}
}

void			minim_i(t_tetrim t, int *tab)
{
	size_t	i;
	size_t	j;
	size_t	cpt;

	i = 0;
	cpt = 0;
	while (i < 4 && cpt < 4)
	{
		j = 0;
		while (j < 4 && cpt < 4)
		{
			if (t[i][j] == '#')
				tab[cpt++] = i;
			j++;
		}
		i++;
	}
	minimise(tab);
}

void			minim_j(t_tetrim t, int *tab)
{
	size_t	i;
	size_t	j;
	size_t	cpt;

	i = 0;
	cpt = 0;
	while (i < 4 && cpt < 4)
	{
		j = 0;
		while (j < 4 && cpt < 4)
		{
			if (t[i][j] == '#')
				tab[cpt++] = j;
			j++;
		}
		i++;
	}
	minimise(tab);
}

void			clear(t_tetrim t)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			t[i][j++] = '.';
		i++;
	}
}

t_tetriminos	*minim(t_tetrim t)
{
	t_tetriminos	*t_final;
	int				*new_i;
	int				*new_j;
	size_t			cpt;

	t_final = malloc(sizeof(t_tetriminos));
	new_i = malloc(sizeof(int) * 4);
	new_j = malloc(sizeof(int) * 4);
	if (!new_i || !new_j || !t_final)
		return (NULL);
	cpt = 0;
	minim_i(t, new_i);
	minim_j(t, new_j);
	clear(t);
	while (cpt < 4)
	{
		t[new_i[cpt]][new_j[cpt]] = g_char;
		cpt++;
	}
	t_final->i = new_i;
	t_final->j = new_j;
	t_final->t = t;
	t_final->c = g_char++;
	return (t_final);
}
