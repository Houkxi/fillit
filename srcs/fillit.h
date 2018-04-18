/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:54:10 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 13:48:47 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef	struct		s_forme
{
	char			**tab;
	char			myl;
	size_t			xaxis;
	size_t			yaxis;
	struct s_forme	*next;
}					t_forme;
typedef	struct		s_coor
{
	int				y;
	int				x;
	int				a1;
	int				b1;
	int				i;
}					t_coor;
t_forme				*alpha_swap(int lettre, t_forme *elem);
int					backy_tracky(char **nt, t_forme *p, int sz, int pos);
int					check_tetri(char *str, int start);
int					check_posabilty_o(t_forme *ptr, t_coor co, char **tab,
	char **newtab);
int					check_posabilty(t_forme *ptr, int pos, int i, char **newt);
int					chk_all_psblty(t_forme *ptr, int size, int pos,
	char **newt);
t_forme				*coor_search(int test, t_forme *elem);
void				ft_lstadd_end(t_forme **alst, t_forme *new);
t_forme				*ft_lstdel_f(int test, t_forme *elem);
t_forme				*ft_lstmapi_f(t_forme *lst,
	t_forme *(*f)(int i, t_forme *elem), int i);
t_forme				*ft_lstnew_re(char **content);
void				pos_tetriminos(t_forme *ptr, char **newtab, int pos,
	int size);
int					optimal_tab_size(int nbr_tetri);
t_coor				struct_cre(int pos, int size);
int					square_checks(char *s, int line, int col,
	t_forme **ptr_lst);
void				tab_corrector(t_forme *ptr, char **tab);
int					tab_checker(t_forme *ptr, char **tab);
void				ft_lst_print(t_forme *alst);

#endif
