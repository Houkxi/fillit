/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:54:10 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/19 16:45:51 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROG_H
# define FT_PROG_H

typedef	struct		s_forme
{
	char			**tab;
	char			myl;
	size_t			xaxis;
	size_t			yaxis;
	size_t			content_size;
	struct s_forme	*prev;
	struct s_forme	*next;
}					t_forme;
typedef	struct		s_coor
{
	int				y;
	int				x;
}					t_coor;
t_forme				*alpha_swap(int lettre, t_forme *elem);
int					backy_tracky(char **newtab, t_forme **ptr_lst, int position,
	int size);
int					check_tetri(char *str, int start);
int					check_posabilty_o(t_forme *ptr, t_coor co, char **tab,
	char **newtab);
int					check_posabilty(t_forme *ptr, int position, char **tab,
	char **newtab);
int			chk_all_psblty(t_forme *ptr, int size, char **tab, char **newt);
t_forme				*coor_search(int test, t_forme *elem);
void				ft_lstadd_end(t_forme **alst, t_forme *new);
t_forme				*ft_lstmapi_f(t_forme *lst,
	t_forme *(*f)(int i, t_forme *elem), int i);
t_forme				*ft_lstnew_re(char **content, size_t content_size);
void				ft_lstprint(t_forme **alst);
int					pos_tetriminos(t_forme *ptr, char **newtab, int pos,
	int size);
int					square_checks(char *s, int line, int col,
	t_forme **ptr_lst);
void				tab_corrector(t_forme *ptr, char **tab);
int					tab_checker(t_forme *ptr, char **tab);

#endif
