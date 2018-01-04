/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:30:46 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/21 18:38:29 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_boolean	cp_possible(t_plateau *plateau, int i, int j, t_list_tetr *elem)
{
	size_t		cpt;
	int			new_i;
	int			new_j;

	cpt = 0;
	while (cpt < 4)
	{
		new_i = i + elem->tetr->i[cpt];
		new_j = j + elem->tetr->j[cpt];
		if (new_i >= plateau->taille || new_j >= plateau->taille ||
			plateau->p[new_i][new_j] != '.')
			return (FALSE);
		cpt++;
	}
	return (TRUE);
}

void		cp_dans_plateau(t_plateau *plateau, int i, int j, t_list_tetr *elem)
{
	size_t cpt;

	cpt = 0;
	while (cpt < 4)
	{
		plateau->p[i + elem->tetr->i[cpt]][j + elem->tetr->j[cpt]] =
		elem->tetr->c;
		cpt++;
	}
}

void		rm_dans_plateau(t_plateau *plateau, t_list_tetr *elem,
	int *i_pos, int *j_pos)
{
	size_t	cpt;
	int		i;
	int		j;

	*i_pos = -1;
	cpt = 0;
	i = 0;
	while (i < plateau->taille && cpt < 4)
	{
		j = 0;
		while (j < plateau->taille && cpt < 4)
		{
			if (plateau->p[i][j] == elem->tetr->c)
			{
				plateau->p[i][j] = '.';
				cpt++;
				if (*i_pos == -1)
				{
					*i_pos = i;
					*j_pos = j + 1;
				}
			}
			j++;
		}
		i++;
	}
}

t_boolean	place_tetriminos(t_plateau *plateau,
	t_list_tetr *elem, int i, int j)
{
	while (i < plateau->taille)
	{
		while (j < plateau->taille)
		{
			if (cp_possible(plateau, i, j, elem))
			{
				cp_dans_plateau(plateau, i, j, elem);
				return (TRUE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (FALSE);
}

t_boolean	resoud_tetris(t_plateau *plateau, t_list_tetr *list)
{
	t_list_tetr	*parcours;
	int			i;
	int			j;

	i = 0;
	j = 0;
	parcours = list;
	while (parcours)
	{
		if (place_tetriminos(plateau, parcours, i, j))
		{
			i = 0;
			j = 0;
			parcours = parcours->suivant;
		}
		else
		{
			parcours = parcours->precedant;
			if (!parcours)
				return (FALSE);
			rm_dans_plateau(plateau, parcours, &i, &j);
		}
	}
	return (TRUE);
}
