/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:23:18 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/11 14:36:52 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_moves	*ft_best(t_moves *moves)
{
	t_moves		*tmp;
	t_moves		*best;
	int			rating;

	tmp = moves;
	best = tmp;
	rating = 2147483647;
	while (tmp)
	{
		if (tmp->rating < rating)
		{
			best = tmp;
			tmp->rating = rating;
		}
		tmp = tmp->next;
	}
	return (best);
}

void        ft_count(t_moves *tmp)
{
    int     i;
    char    **split;

    i = 0;
	split = ft_strsplit(tmp->path, ' ');
    while (split[i])
    {
        i++;
    }
    tmp->rating = i;
}

void        ft_rate(t_moves *path)
{
    t_moves *tmp;

    tmp = path;
    while (tmp)
    {
        ft_count(tmp);
        tmp = tmp->next;
    }
}

void		ft_add_node(t_moves **head, char *path)
{
	t_moves *tmp;
	t_moves *node;

	node = malloc(sizeof(t_moves));
	node->path = path;
	node->rating = 2147483647;
	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		tmp->next->next = NULL;
	}
//	free(node);
}
