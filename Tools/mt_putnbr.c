/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:17:20 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/05 22:17:22 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minitalk.h"

void	mt_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		mt_putchar(nb + '0');
	}
	else if (nb < 0)
	{
		mt_putchar('-');
		if (nb == -2147483648)
		{
			mt_putchar('2');
			mt_putnbr(147483648);
		}
		else
		{
			mt_putnbr(nb *(-1));
		}
	}
	else
	{
		mt_putnbr(nb / 10);
		mt_putnbr(nb % 10);
	}
}
