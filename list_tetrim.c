/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:59:36 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/20 18:10:38 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list_tetr	*creer_liste(t_tetriminos *t)
{
	t_list_tetr *elem;

	elem = malloc(sizeof(t_tetriminos));
	if (!elem)
		return (NULL);
	elem->tetr = t;
	elem->precedant = NULL;
	elem->suivant = NULL;
	return (elem);
}

t_list_tetr	*ajouter_elem(t_list_tetr *list, t_tetriminos *t)
{
	t_list_tetr *new;
	t_list_tetr *parcours;

	new = creer_liste(t);
	if (!new)
		return (NULL);
	parcours = list;
	while (parcours->suivant)
		parcours = parcours->suivant;
	parcours->suivant = new;
	new->precedant = parcours;
	return (list);
}

void		affiche_liste(t_list_tetr *list)
{
	while (list)
	{
		affiche_t_tetrim(list->tetr);
		list = list->suivant;
	}
}

size_t		compte_t_tetrim(t_list_tetr *list)
{
	size_t i;

	i = 0;
	while (list)
	{
		i++;
		list = list->suivant;
	}
	return (i);
}

void		supprimer_liste(t_list_tetr *list)
{
	t_list_tetr	*tmp;

	while (list)
	{
		tmp = list->suivant;
		libere_tetriminos(list->tetr);
		free(list);
		list = tmp;
	}
}
