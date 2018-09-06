#include "../includes/lemin.h"
#include <stdio.h>

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
    int i;
    int j;
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
void ft_print(t_moves *best)
{
    char **tewt;

    tewt = ft_strsplit(best->path, ' ');
    ft_putarr(tewt);
}

void ft_possible(char *begin, t_lemin map, t_moves **head)
{
    char *path;
    int j;
	char	*last;
	char	*start;
    if (begin[0] != map.start)
        return;
    path = begin;
        j = 0;
        while (map.links[j])
        {
            printf("FIRST : << %s >>\nLAST : << %s >>",ft_lastroom(begin), ft_firstroom(map.links[j]));
            last = ft_lastroom(begin) ;
			start = ft_firstroom(map.links[j]);
			if (ft_strcmp(last, start) == 0)
            {
                printf("DAMN\n");
                path = ft_strjoin(path, " ");
                path = ft_strjoin(path, map.links[j]);
                begin = map.links[j];
            }
			else
			{
				printf("STRCMP : <  %d  >\n_______________________________________________\n", ft_strcmp(last, start));
			}
            j++;
        }
//		if ((ft_atoi(ft_lastroom(begin))) == map.end)
			printf("\n\n\n\nPATH : %s", path);
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
		printf("\n\n\n_______________________________________NEXT:");
        i++;
    }
    ft_rate(head);
    best = ft_best(head);
    ft_print(best);
}
