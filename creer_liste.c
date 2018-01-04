/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creer_liste.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:06:31 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/20 21:32:43 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list_tetr	*creer_liste_de_fd(int fd)
{
	t_tetriminos	*new;
	t_list_tetr		*list;

	list = NULL;
	while ((new = lire_t_tetrim(fd)))
	{
		if (!list)
		{
			if (!(list = creer_liste(new)))
				return (NULL);
		}
		else
		{
			if (!(list = ajouter_elem(list, new)))
				return (NULL);
		}
	}
	if (!new && g_fin == 0)
	{
		ft_putstr("error\n");
		supprimer_liste(list);
		return (NULL);
	}
	return (list);
}
