/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:11:44 by rasingh           #+#    #+#             */
/*   Updated: 2018/09/14 10:19:46 by rasingh          ###   ########.fr       */
/*   Updated: 2018/08/09 14:04:38 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putstr_fd(str[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
	ft_putstr_fd("\n\n\n\n\n", 2);
}
