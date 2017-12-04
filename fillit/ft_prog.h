/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:54:10 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/04 20:06:38 by mmanley          ###   ########.fr       */
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

t_forme	*alpha_swap(int lettre, t_forme *elem);
int		check_tetri(char *str, int start);
t_forme	*coor_search(int test, t_forme *elem);
void	ft_lstadd_end(t_forme **alst, t_forme *new);
t_forme	*ft_lstmapi(t_forme *lst, t_forme *(*f)(int i, t_forme *elem), int i);
t_forme	*ft_lstnew_re(char **content, size_t content_size);
void	ft_lst_print(t_forme **alst);
int		square_checker(char *s, int line, int col, int nbr);
int		square_checks(char *s, int line, int col, t_forme **ptr_lst);
int		whole_file_checking(char *str, int size);

#endif
