#include "../includes/lemin.h"

int ft_findchar(char c, char *str)
{
    int i;

    i = 0;

    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
t_lemin ft_init(t_lemin map)
{
    char *line;
    int ret;
    int i;

    i = 0;
    line = NULL;
    map.links = malloc(sizeof(char *) * 2000);
    ret = get_next_line(0, &line);
    if (ft_strlen(line) == 1 && ft_isdigit(line[0]))
        map.ants = ft_atoi(line);
    while (ret)
    {
        if (ft_strcmp(line, "##start") == 0)
        {
            ret = get_next_line(0, &line);
            map.start = line[0];
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
    }
    return (map);
}

int main(void)
{
    t_lemin map;

    map = ft_init(map);
    ft_findpath(map);
    return (0);
}