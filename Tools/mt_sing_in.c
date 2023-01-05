/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_sing_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:29:20 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/05 17:10:02 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minitalk.h"

int	mt_sing_in(int nbr, int sign)
{
	if (sign == '-')
		return (nbr * -1);
	else
		return (nbr);
}
