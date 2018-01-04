/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_tetrim_plateau.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:07:35 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/20 20:07:37 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	affiche_t_tetrim(t_tetriminos *t)
{
	size_t i;

	i = 0;
	while (i < 4)
		ft_putendl(t->t[i++]);
	ft_putchar('\n');
}

void	affiche_plateau(t_plateau *plateau)
{
	int i;

	i = 0;
	while (i < plateau->taille)
		ft_putendl(plateau->p[i++]);
}

void	affiche_tab_int(int *tab)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("]:");
		ft_putnbr(tab[i++]);
		ft_putchar('\n');
	}
}
