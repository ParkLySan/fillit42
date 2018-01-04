/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_minim_tetrim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:00:01 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/20 21:29:20 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t			avance_t_tetrim(int lim, int origin, int *i, int *j)
{
	size_t ajout;

	ajout = 1;
	if (lim == 2)
		ajout++;
	if (origin == 10)
		(*i)++;
	if (origin == 1)
		(*j)++;
	if (origin == -10)
		(*i)--;
	if (origin == -1)
		(*j)--;
	return (ajout);
}

void			libere_tetriminos(t_tetriminos *t)
{
	libere(t->t);
	free(t->i);
	free(t->j);
	free(t);
}

t_tetriminos	*verif_minim(t_tetrim t)
{
	int		i;
	int		j;
	int		origin;
	size_t	cpt;
	size_t	lim;

	if (compte(t, &i, &j) != 4)
		return (NULL);
	origin = 0;
	cpt = 0;
	while (cpt < 3)
	{
		if ((lim = f_nb_lim_origin(t, i, j, &origin)) >= 1)
			cpt += avance_t_tetrim(lim, origin, &i, &j);
		else
			return (NULL);
	}
	return (minim(t));
}
