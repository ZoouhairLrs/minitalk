/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_btod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:16:54 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/09 17:48:45 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	mt_btod(int binary)
{
	int	dec_value;
	int	base;
	int	last_digit;

	dec_value = 0;
	base = 1;
	while (binary)
	{
		last_digit = binary % 10;
		binary = binary / 10;
		dec_value += last_digit * base;
		base = base * 2;
	}
	return (dec_value);
}
