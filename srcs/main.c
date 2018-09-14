/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:38:25 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/14 12:55:16 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"


void    ft_print(char *path, t_lemin map)
{
    int     i;
    int     j;
    char    **rooms;

    ft_putarr(map.text);
    rooms = ft_strsplit(path, ' ');
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

int		ft_findchar(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

t_lemin	ft_initcont(t_lemin map)
{
	map = ft_end(map);
	if (!(map.end))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	map = ft_links(map);
	if (!(map.links))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	return (map);
}

t_lemin	ft_init(void)
{
	t_lemin	map;

	map.text = (char**)malloc(2000);
	map = ft_getnumber(map);
	if (map.ants == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	map = ft_start(map);
	if (map.start == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	map = ft_initcont(map);
	return (map);
}

int		main(void)
{
	t_lemin map;

	map = ft_init();
	ft_findpath(map);
	return (0);
}
