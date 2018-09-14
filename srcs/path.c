/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:55:45 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/14 12:57:14 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*ft_firstroom(char *begin)
{
	int		i;
	char	*tmp;

	tmp = (char*)malloc(sizeof(char*) * 10);
	i = 0;
	while (begin[i] != '-')
	{
		tmp[i] = begin[i];
		i++;
	}
	return (tmp);
}

char	*ft_lastroom(const char *end)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char*)malloc(sizeof(char*) * 10);
	j = 0;
	i = ft_strlen(end) - 1;
	while (end[i] != '-' && end[i])
		i--;
	i++;
	while (end[i])
	{
		tmp[j] = end[i];
		j++;
		i++;
	}
	return (tmp);
}

void	ft_possiblecont(char **begin, t_lemin map, char **path)
{
	int		j;
	char	*last;
	char	*start;

	j = 0;
	while (map.links[j])
	{
		last = ft_lastroom(*begin);
		start = ft_firstroom(map.links[j]);
		if (ft_strcmp(last, start) == 0)
		{
			*path = ft_strjoin(*path, " ");
			*path = ft_strjoin(*path, map.links[j]);
			*begin = map.links[j];
			return ;
		}
		free((void*)last);
		free((void*)start);
		j++;
	}
}

void	ft_possible(char *begin, t_lemin map)
{
	char	*path;
	int		j;
	char	*start;
	char	*end;
	int		i;

	i = 0;
	start = ft_firstroom(begin);
	if (ft_strcmp(start, map.start) != 0)
		return ;
	path = begin;
	while (map.links[i])
	{
		j = 0;
		ft_possiblecont(&begin, map, &path);
		end = ft_lastroom(path);
		if (ft_strcmp(end, map.end) == 0)
		{
			ft_print(path, map);
			exit(0);
		}
		i++;
	}
}

void	ft_findpath(t_lemin map)
{
	int i;

	i = 0;
	while (map.links[i])
	{
		ft_possible(map.links[i], map);
		i++;
	}
	ft_freesplit((void**)map.links);
	ft_putstr_fd("Error : No Possible Path\n", 2);
}
