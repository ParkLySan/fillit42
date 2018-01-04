/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:16:05 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/21 18:31:00 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TRUE 1
# define FALSE 0

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int						g_fin;
char					g_char;

typedef char			** t_tetrim;

typedef unsigned char	t_boolean;

typedef struct			s_plateau
{
	char				**p;
	int					taille;
}						t_plateau;

typedef struct			s_tetriminos
{
	t_tetrim			t;
	char				c;
	int					*i;
	int					*j;
}						t_tetriminos;

typedef struct			s_ltetr
{
	t_tetriminos		*tetr;
	struct s_ltetr		*suivant;
	struct s_ltetr		*precedant;
}						t_list_tetr;

size_t					f_nb_lim(t_tetrim t, int i, int j);
size_t					f_nb_lim_origin(t_tetrim t, int i, int j, int *origin);
t_tetriminos			*lire_t_tetrim(int fd);
t_tetriminos			*verif_minim(t_tetrim t);
t_tetriminos			*minim(t_tetrim t);
t_tetriminos			*libere(t_tetrim t);
void					libere_tetriminos(t_tetriminos *t);
size_t					compte(t_tetrim t, int *i, int *j);
void					affiche_t_tetrim(t_tetriminos *t);
void					affiche_tab_int(int *tab);

t_boolean				resoud_tetris(t_plateau *plateau, t_list_tetr *list);

void					affiche_plateau(t_plateau *plateau);
int						ft_sqrt(int nb);
t_plateau				*creer_plateau(int taille);
void					supprimer_plateau(t_plateau *plateau);

t_list_tetr				*creer_liste_de_fd(int fd);

t_list_tetr				*creer_liste(t_tetriminos *t);
t_list_tetr				*ajouter_elem(t_list_tetr *list, t_tetriminos *t);
size_t					compte_t_tetrim(t_list_tetr *list);
void					supprimer_liste(t_list_tetr *list);
void					affiche_liste(t_list_tetr *list);

#endif
