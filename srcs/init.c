/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:56:47 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/11 15:04:14 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		ft_getnumber(void)
{
	char	*line;
	int		ret;
	int		ants;

	ret = 1;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(0, &line);
		ft_putendl(line);
		if (!ret)
			break ;
		ants = ft_atoi(line);
		if (ft_intlen(ants) == (int)ft_strlen(line))
			return (ants);
		ft_putstr(line);
		free(line);
	}
	return (0);
}

char	*ft_start(void)
{
	char	*line;
	int		ret;
	int		i;
	char	*str;

	i = 0;
	ret = 1;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(0, &line);
		ft_putendl(line);
		if (ft_strcmp(line, "##start") == 0)
		{
			ret = get_next_line(0, &line);
			if (ret)
			{
				ft_putendl(line);
				i = ft_findchar(' ', line);
				str = ft_strsub(line, 0, i);
				free(line);
				return (str);
			}
		}
		free(line);
	}
	return (NULL);
}

char	*ft_end(void)
{
	char	*line;
	int		ret;
	int		i;
	char	*str;

	i = 1;
	ret = 1;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(0, &line);
		ft_putendl(line);
		if (ft_strcmp(line, "##end") == 0)
		{
			ret = get_next_line(0, &line);
			if (ret)
			{
				ft_putendl(line);
				i = ft_findchar(' ', line);
				str = ft_strsub(line, 0, i);
				free(line);
				return (str);
			}
		}
		free(line);
	}
	return (NULL);
}

char	**ft_links(void)
{
	char	*line;
	int		ret;
	int		i;
	char	**links;

	line = NULL;
	ret = 1;
	i = 0;
	links = malloc(sizeof(char*) * 2000);
	while (ret)
	{
		ret = get_next_line(0, &line);
		if (!ret)
			break ;
		if (ft_findchar('-', line))
			links[i++] = ft_strdup(line);
		ft_putendl(line);
		free(line);
	}
	return (i > 0 ? links : NULL);
}
