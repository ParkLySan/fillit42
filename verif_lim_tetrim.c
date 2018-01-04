/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_lim_tetrim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:59:11 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/20 17:59:13 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	f_nb_lim(t_tetrim t, int i, int j)
{
	size_t nb_lim;

	nb_lim = 0;
	if (i + 1 < 4 && t[i + 1][j] == '#')
		nb_lim++;
	if (j + 1 < 4 && t[i][j + 1] == '#')
		nb_lim++;
	if (i - 1 >= 0 && t[i - 1][j] == '#')
		nb_lim++;
	if (j - 1 >= 0 && t[i][j - 1] == '#')
		nb_lim++;
	return (nb_lim);
}

size_t	ret_and_set(int *origin, int orig2, size_t nb_lim)
{
	*origin = orig2;
	return (nb_lim);
}

void	set_i_j(int *i, int *j, int i2, int j2)
{
	*i = i2;
	*j = j2;
}

size_t	compte(t_tetrim t, int *i, int *j)
{
	size_t cpt;
	size_t i2;
	size_t j2;

	*i = -1;
	cpt = 0;
	i2 = 0;
	while (i2 < 4)
	{
		j2 = 0;
		while (j2 < 4)
		{
			if (t[i2][j2] == '#')
			{
				if (*i == -1 && (f_nb_lim(t, i2, j2) == 1 || cpt == 3))
					set_i_j(i, j, i2, j2);
				cpt++;
			}
			j2++;
		}
		i2++;
	}
	return (cpt);
}

size_t	f_nb_lim_origin(t_tetrim t, int i, int j, int *origin)
{
	size_t	nb_lim;
	int		orig2;

	nb_lim = 0;
	if (i + 1 < 4 && t[i + 1][j] == '#' && *origin != -10)
	{
		orig2 = 10;
		nb_lim++;
	}
	if (j + 1 < 4 && t[i][j + 1] == '#' && *origin != -1)
	{
		orig2 = 1;
		nb_lim++;
	}
	if (i - 1 >= 0 && t[i - 1][j] == '#' && *origin != 10)
	{
		orig2 = -10;
		nb_lim++;
	}
	if (j - 1 >= 0 && t[i][j - 1] == '#' && *origin != 1)
	{
		orig2 = -1;
		nb_lim++;
	}
	return (ret_and_set(origin, orig2, nb_lim));
}
