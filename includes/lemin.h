#ifndef LEMIN_H
# define LEMIN_H
#include "libft/libft.h"
#include "gnl/get_next_line.h"

typedef struct  s_lemin 
{
    int             ants;
    char            *start;
    char			*end;
    char            **links;
}                   t_lemin;

typedef struct      s_moves
{
    char            *path;
    int             rating;
    struct s_moves  *next;
}                   t_moves;

int ft_findchar(char c, char *str);
t_moves	*ft_best(t_moves *moves);
t_lemin ft_init();
void        ft_count(t_moves *tmp);
void		ft_add_node(t_moves **head, char *path);
void        ft_rate(t_moves *path);
void    ft_possible(char *begin, t_lemin map, t_moves **head);
void    ft_findpath(t_lemin map);
int ft_getnumber();
char    *ft_start();
char    *ft_end();
char    **ft_links();
#endif
