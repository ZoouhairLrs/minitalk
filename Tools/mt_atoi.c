/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:10:07 by inf               #+#    #+#             */
/*   Updated: 2023/01/02 23:38:17 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minitalk.h"

int	mt_atoi(char *c)
{
	size_t	i;
	size_t	nbr;
	int		symb;

	symb = 1;
	i = 0;
	nbr = 0;
	while (c[i] == 32 || (c[i] >= 9 && c[i] <= 13))
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		symb = c[i];
		i++;
	}
	while (c[i] && (c[i] >= '0') && (c[i] <= '9'))
	{
		nbr *= 10;
		nbr += c[i] - '0';
		i++;
	}
	return (mt_check(nbr, symb));
}
