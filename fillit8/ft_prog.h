/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:54:10 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/26 15:34:29 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROG_H
# define FT_PROG_H
typedef	struct		s_coor
{
	int				y1;
	int				x1;
	int				y2;
	int				x2;
	int				y3;
	int				x3;
}					t_coor;
typedef	struct		s_forme
{
	char			**tab;
	char			myl;
	size_t			xaxis;
	size_t			yaxis;
	t_coor			*cmps;
	struct s_forme	*prev;
	struct s_forme	*next;
}					t_forme;
t_forme				*alpha_swap(int lettre, t_forme *elem);
int					backy_tracky(char **nt, t_forme *p, t_forme *head, int pos);
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
void				ft_lstprint(t_forme **alst);
void				pos_tetriminos(t_forme *ptr, char **newtab, int pos,
	int size);
int					optimal_tab_size(int nbr_tetri);
int					square_checks(char *s, int line, int col,
	t_forme **ptr_lst);
void				tab_corrector(t_forme *ptr, char **tab);
int					tab_checker(t_forme *ptr, char **tab);
t_forme		*tetri_compos(int a, t_forme *p);

#endif
