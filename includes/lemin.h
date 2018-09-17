/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:55:30 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/17 10:20:11 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct		s_lemin
{
	int				ants;
	char			*start;
	char			*end;
	char			**links;
	char			**text;
}					t_lemin;

char				*ft_firstroom(char *begin);
char				*ft_lastroom(const char *end);
void				ft_possiblecont(char **begin, t_lemin map, char **path);
void				ft_print(char *path, t_lemin map);
int					ft_findchar(char c, char *str);
t_lemin				ft_init();
void				ft_possible(char *begin, t_lemin map);
void				ft_findpath(t_lemin map);
t_lemin				ft_getnumber();
t_lemin				ft_start();
t_lemin				ft_end();
t_lemin				ft_links();
#endif
