/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:48:01 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/20 21:27:35 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int nb)
{
	unsigned int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

void		clear_plateau(t_plateau *plateau)
{
	int	i;
	int	j;

	i = 0;
	while (i < plateau->taille)
	{
		j = 0;
		while (j < plateau->taille)
			plateau->p[i][j++] = '.';
		plateau->p[i][j] = 0;
		i++;
	}
}

void		supprimer_plateau(t_plateau *plateau)
{
	int i;

	i = 0;
	while (i < plateau->taille)
		free(plateau->p[i++]);
	free(plateau->p);
	free(plateau);
}

t_plateau	*creer_plateau(int taille)
{
	int			i;
	t_plateau	*plateau;

	i = 0;
	plateau = malloc(sizeof(plateau));
	if (!plateau)
		return (NULL);
	plateau->p = (char **)malloc(sizeof(char *) * taille);
	if (!plateau->p)
		return (NULL);
	while (i < taille)
		plateau->p[i++] = (char *)malloc(taille + 1);
	plateau->taille = taille;
	clear_plateau(plateau);
	return (plateau);
}
