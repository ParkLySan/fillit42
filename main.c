/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:02:41 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/21 18:32:10 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	resoud_complet_tetris(int fd)
{
	t_plateau	*plateau;
	t_list_tetr	*list;
	int			taille;

	list = creer_liste_de_fd(fd);
	if (!list)
		return (0);
	if (compte_t_tetrim(list) > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	taille = ft_sqrt(compte_t_tetrim(list) * 4);
	plateau = creer_plateau(taille++);
	while (!resoud_tetris(plateau, list))
	{
		supprimer_plateau(plateau);
		plateau = creer_plateau(taille++);
	}
	affiche_plateau(plateau);
	supprimer_liste(list);
	supprimer_plateau(plateau);
	return (0);
}

int	main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <fichier>\n");
		return (0);
	}
	g_fin = 0;
	g_char = 'A';
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("erreur ouverture");
		return (0);
	}
	return (resoud_complet_tetris(fd));
}
