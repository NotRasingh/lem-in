/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:38:25 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/11 15:06:26 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>
int ft_findchar(char c, char *str)
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

t_lemin ft_init(void)
{
//    char *line;
//    int ret;
//    int i;
	t_lemin	map;
/*	int	j;

	i = 0;
    line = NULL;
	map.links = malloc(sizeof(char *) * 2000);*/
	if (!(map.ants = ft_getnumber()))
	{
		ft_putstr_fd("ERROR: NO ANTS\n", 2);
		exit(0);
	}
	if (!(map.start = ft_start()) || !(map.end = ft_end()))
	{
		ft_putstr_fd("ERROR: NO MANDATORY COMMENTS\n", 2);
		exit(0);
	}
	if (!(map.links = ft_links()))
	{
		ft_putstr_fd("ERROR: NO ROOMS LINKED\n", 2);
		exit(0);
	}
/*	printf("ANTS: %d\n",map.ants);
	printf("START : <%s>\n END : <%s>\n", map.start, map.end);
	ft_putendl("BEGIN");
	ft_putarr(map.links);
	ft_putendl("END");
    ret = get_next_line(0, &line);
    if (ft_strlen(line) == 1 && ft_isdigit(line[0]))
        map.ants = ft_atoi(line);
    while (ret)
    {
		j = 0;
        if (ft_strcmp(line, "##start") == 0)
        {
            ret = get_next_line(0, &line);
        }
        else if (ft_strcmp(line, "##end") == 0)
        {
            ret = get_next_line(0, &line);
            map.end = line[0];
        }
        else if (ft_findchar('-', line) == 1)
        {
            map.links[i++] = line;
            ret = get_next_line(0, &line);
        }
        else
            ret = get_next_line(0, &line);
		if (ret)
			ft_putstr(line);
		ft_putchar('\n');
    }
*/  return (map);
}

int main(void)
{
    t_lemin map;

    map = ft_init();
    ft_findpath(map);
	sleep(50);
    return (0);
}
