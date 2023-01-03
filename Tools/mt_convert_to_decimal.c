/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_convert_to_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:15:40 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/03 14:51:18 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minitalk.h"

int	mt_convert_to_decimal(int binary)
{
	int	decimal;
	int	base;
	int	rem;

	decimal = 0;
	base = 1;
	while (binary != 0)
	{
		rem = binary % 10;
		decimal = decimal + rem * base;
		binary = binary / 10;
		base = base * 2;
	}
	// if (decimal > 127 || decimal < 0)
	// {
	// 	mt_putstr("\nError Recieving the signal\n");
	// 	exit(0);
	// }
	// else
		return (decimal);
}
