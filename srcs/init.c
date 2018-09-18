/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:56:47 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/18 10:28:14 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemin		ft_addline(char *line, t_lemin map)
{
	int	i;

	i = 0;
	while (map.text[i])
		i++;
	map.text[i] = ft_strdup(line);
	return (map);
}

t_lemin		ft_getnumber(t_lemin map)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while ((ret = get_next_line(0, &line)))
	{
		map = ft_addline(line, map);
		map.ants = ft_atoi(line);
		if (ft_intlen(map.ants) == (int)ft_strlen(line))
			return (map);
		free(line);
	}
	map.ants = 0;
	return (map);
}

t_lemin		ft_start(t_lemin map)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	line = NULL;
	while ((ret = get_next_line(0, &line)))
	{
		map = ft_addline(line, map);
		if (ft_strcmp(line, "##start") == 0)
		{
			ret = get_next_line(0, &line);
			if (ret)
			{
				map = ft_addline(line, map);
				i = ft_findchar(' ', line);
				map.start = ft_strsub(line, 0, i);
				return (map);
			}
		}
	}
	map.start = NULL;
	return (map);
}

t_lemin		ft_end(t_lemin map)
{
	char	*line;
	int		ret;
	int		i;

	i = 1;
	line = NULL;
	while ((ret = get_next_line(0, &line)))
	{
		map = ft_addline(line, map);
		if (ft_strcmp(line, "##end") == 0)
		{
			ret = get_next_line(0, &line);
			if (ret)
			{
				map = ft_addline(line, map);
				i = ft_findchar(' ', line);
				map.end = ft_strsub(line, 0, i);
				return (map);
			}
		}
	}
	map.end = NULL;
	return (map);
}

t_lemin		ft_links(t_lemin map)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	i = 0;
	map.links = malloc(sizeof(char*) * 2000);
	while ((ret = get_next_line(0, &line)))
	{
		if (!ret)
			break ;
		if (ft_findchar('-', line))
			map.links[i++] = ft_strdup(line);
		map = ft_addline(line, map);
		free(line);
	}
	if (i == 0)
		map.links = NULL;
	return (map);
}
