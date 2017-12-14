/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:54:10 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/14 19:29:51 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROG_H
# define FT_PROG_H

typedef	struct		s_forme
{
	char			**tab;
	char			myletter;
	size_t			xaxis;
	size_t			yaxis;
	size_t			content_size;
	struct s_forme	*next;
}					t_forme;
typedef	struct		s_coor
{
	int y;
	int x;
}					t_coor;
typedef	struct		bs_coor
{
	t_coor	sec_elem;
	t_coor	third_elem;
	t_coor	fourth_elem;
}					b_coor;
t_forme	*alpha_swap(int lettre, t_forme *elem);
char	**backy_tracky(char **newtab, t_forme **ptr_lst, int position, int size);
//char		**backtrack_debut(t_forme **ptr_lst, int sizex, int sizey);
int		check_tetri(char *str, int start);
b_coor	*check_pos_possible(t_forme *ptr, b_coor *new_ptv);
int		check_posabilty_test(t_forme *ptr, int position, char **tab, char **newtab);
int		check_posabilty(t_forme *ptr, t_coor co, char **tab, char **newtab);
t_forme	*coor_search(int test, t_forme *elem);
void	ft_lstadd_end(t_forme **alst, t_forme *new);
b_coor	*ft_all_pos(t_forme *ptr, b_coor *saver);
t_forme	*ft_lstmapi_f(t_forme *lst, t_forme *(*f)(int i, t_forme *elem), int i);
t_forme	*ft_lstnew_re(char **content, size_t content_size);
void	ft_lst_print(t_forme **alst);
char	**backy_tracky(char **newtab, t_forme **ptr, int position, int size);
int		pos_tetriminos(t_forme *ptr, char **newtab, t_coor co);
int		square_checker(char *s, int line, int col, int nbr);
int		square_checks(char *s, int line, int col, t_forme **ptr_lst);
t_coor	*tab_x_search(t_forme *elem);
t_coor	*tab_y_search(t_forme *elem);
int		tab_x_size(char **tab);
int		tab_y_size(char **tab);
int		dot_x_size(char **tab);
int		dot_y_size(char **tab);
void	tab_corrector(t_forme *ptr, char **tab);
int		is_size_good(char **tab, int size, char **newtab);
int		whole_file_checking(char *str, int size);

#endif
