/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inf <inf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:18:25 by inf               #+#    #+#             */
/*   Updated: 2023/01/02 19:44:12 by inf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/minitalk.h"

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
