/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:39:47 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/10 19:10:14 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

typedef struct		s_bonus
{
	int				best;
	int				lenght;
	int				chemin;
	int				nb_path;
	int				nb_fourmi;
	int				ac;
	char			**av;
	struct s_bonus	*next;
}					t_bonus;

typedef struct		s_norme
{
	int				a;
	int				b;
	int				check;
	int				fourmi;
	int				start;
	int				end;
	struct s_norme	*next;
}					t_norme;

typedef struct		s_fourmi
{
	int				x;
	int				nb_road;
	int				step;
	int				room;
	struct s_fourmi	*next;
}					t_fourmi;

typedef struct		s_plist
{
	char			*nom;
	int				salle;
	int				x;
	int				y;
	int				*lien;
	int				nb_lien;
	int				fourmi;
	int				start;
	int				end;
	struct s_plist	*next;
}					t_plist;

typedef struct		s_path
{
	int				nom;
	int				*road;
	int				lenght;
	struct s_path	*next;
}					t_path;

typedef struct		s_check
{
	int				a;
	int				str;
	struct s_plist	*list;
	struct s_plist	*b_list;
}					t_check;

int					bonus(t_path *path, t_plist *list, t_bonus *bonus, char *s);
int					check_if_start_end(t_plist *list);
int					check_nb_path(t_path *path, t_path *b_path);
int					check_sup_start_end(char *str, int a, int d);
int					check_if_done(t_fourmi *fourmi, int end);
int					*rm_last_number(int *tab, int lenght);
int					*fill_tab(int *tab, int salle, int lenght);
int					check_if_possible(int *tab, int lien, int lenght);
int					error_string(char *str, t_check *check);
int					error_list(char *str, t_plist *list);
int					list_lenght(t_plist *list);
int					ft_is_int(char *s, char c, int signe);
int					check_line(char *str, int start, int end, int fourmi);
int					ft_end(t_plist *list);
int					nb_rooms(t_plist *list);
int					room_link(char *str, int a);
int					ft_putstri(const char *str);
int					*ft_initlien(int c, int lenght);
int					check_tab(int *tab, int end, int lenght);
int					check_name_coor(t_plist *b_list);
int					ft_strccmp(const char *s1, const char *s2, char c);
int					ft_check_new_room(t_plist *room, t_plist *list);
int					free_str(char *str);
int					ft_free_list(t_plist *list);
int					check_if_path(t_path *path);
int					free_bonus(t_bonus *bonus);
int					free_list_print_error(t_plist *list);
char				*check_str(char *str, t_check *check);
char				*ft_strccpy(char *str, char c, int b);
char				*ft_strjoinfree(char *s, char *s2);
void				affiche_len(int len);
void				bonus_tours(int tours);
void				free_list_path(t_path *path);
void				free_list_fourmi(t_fourmi *fourmi);
void				mv_all(t_fourmi *f, t_path *path, t_plist *l, int x);
void				affiche_fourmi(t_plist *list, int f, int salle, int l_char);
void				mv_fourmi(t_path *path, t_plist *b_l, t_bonus *b, char *s);
void				ret_error(t_path *path, t_fourmi *fourmi);
void				path_len(t_path *path, int len);
t_norme				*init_norme(void);
t_check				*init_check(void);
t_plist				*find_room(t_plist *list, int salle);
t_check				*ft_parsing(char *str, t_check *check, int a, int c);
t_plist				*ft_newroom(t_plist *list, char *str, int a, int b);
t_path				*rm_wrong_path(t_path *path);
t_path				*find_path(t_path *path, int road);
t_path				*create_path(int *tab, int lenght);
t_path				*algo(t_plist *list, t_plist *b_list, int a, int b);
t_fourmi			*init_fourmi(t_fourmi *fou, t_fourmi *b_fou, int f, int s);
t_fourmi			*new_fourmi(int fourmi, int start);
t_fourmi			*unused_fourmi(t_fourmi *fourmi);
t_bonus				*set_bonus(int nb_fourmi, int ac, char **av);
#endif
