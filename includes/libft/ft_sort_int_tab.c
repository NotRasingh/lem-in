/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:06:38 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/18 10:15:16 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
	}
}
