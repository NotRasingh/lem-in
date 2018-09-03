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

    if (begin[0] != map.start)
        return;
    path = begin;
        j = 0;
        while (map.links[j])
        {
            printf("FIRST : << %s >>\nLAST : << %s >>\n",ft_lastroom(begin), ft_firstroom(map.links[j]));
            if (ft_lastroom(begin) == ft_firstroom(map.links[j]))
            {
                printf("DAMN\n");
                path = ft_strjoin(path, " ");
                path = ft_strjoin(path, begin);
                begin = map.links[j];
            }
            j++;
        }
 //   if (ft_atoi(ft_lastroom(begin)) == map.end)
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
    ft_print(best);
}