/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:54:10 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/01 16:45:31 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROG_H
# define FT_PROG_H

typedef	struct		s_forme
{
	char			**tab;
	size_t			content_size;
	struct s_forme	*next;
}					t_forme;

int		whole_file_checking(char *str, int size);
int		square_checker(char *s, int line, int col);
int		square_checks(char *s, int line, int col);
void	ft_tabcpy(char **tab, char **t);
void	ft_lstadd_end(t_forme **alst, t_forme *new);
t_forme	*ft_lstnew_re(char **content, size_t content_size);

#endif
