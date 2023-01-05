/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:16:05 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/05 22:16:13 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bits(char c, int pid)
{
	int		i;
	char	x;

	i = 7;
	while (i >= 0)
	{
		x = c >> i-- & 1;
		if (x == 1)
			kill(pid, SIGUSR1);
		else if (x == 0)
			kill(pid, SIGUSR2);
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (mt_putstr("Some this wrong arguments not enough!\n"), 1);
	else
	{
		i = 0;
		pid = mt_atoi(av[1]);
		while (av[2][i])
		{
			send_bits(av[2][i], pid);
			i++;
		}
		if (av[2][i] == '\0')
		{
			send_bits(av[2][i], pid);
			sleep(1);
		}
	}
	return (0);
}
