/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:55:45 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/10 14:58:26 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char    *ft_firstroom(char *begin)
{
	int     i;
	char    *tmp;

	tmp = (char*)malloc(sizeof(char*) * 10);
	i = 0;
	while (begin[i] != '-')
	{
		tmp[i] = begin[i];
		i++;
	}
	return (tmp);
}

char    *ft_lastroom(const char *end)
{
	int		i;
	int		j;
	char    *tmp;

	tmp = (char*)malloc(sizeof(char*) * 10);
	j = 0;
	i = 0;
	while (end[i] != '-')
		i++;
	i++;
	while (end[i])
	{
		tmp[j] = end[i];
		j++;
		i++;
	}
	return (tmp);
}

void ft_print(t_moves *best, t_lemin map)
{
	int		i;
	int		j;
	char	**rooms;

	rooms = ft_strsplit(best->path, ' ');
	i = 1;
	while (i <= map.ants)
	{
		j = 0;
		while (rooms[j])
		{
			ft_putchar('L');
			ft_putnbr(i);
			ft_putchar('-');
			ft_putendl(ft_lastroom(rooms[j]));
			j++;
		}
		i++;
	}
}

void ft_possible(char *begin, t_lemin map, t_moves **head)
{
	char	*path;
	int		j;
	char	*last;
	char	*start;

	start = ft_firstroom(begin);
	if (ft_strcmp(start, map.start) != 0)
		return;
	path = begin;
	j = 0;
	while (map.links[j])
	{
		last = ft_lastroom(begin) ;
		start = ft_firstroom(map.links[j]);
		if (ft_strcmp(last, start) == 0)
		{
			path = ft_strjoin(path, " ");
			path = ft_strjoin(path, map.links[j]);
			begin = map.links[j];
		}
		j++;
	}
	//if(ft_lastroom(begin) == map.end)
	ft_add_node(head, path);
}

void ft_findpath(t_lemin map)
{
	t_moves *head;
	t_moves *best;

	head = NULL;
	int i;
	i = 0;
	while (map.links[i])
	{
		ft_possible(map.links[i], map, &head);
		i++;
	}
	ft_rate(head);
	best = ft_best(head);
	ft_print(best, map);
}
