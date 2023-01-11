/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:36:37 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/11 19:18:57 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	mt_recieving(int sig)
{
	if (sig == SIGUSR1)
		mt_putstr("MSG Received\n");
	exit (0);
}

void	send_signals(char c, int pid)
{
	int		i;
	char	shift;

	i = 7;
	while (i >= 0)
	{
		shift = c >> i-- & 1;
		if (shift == 1)
			kill(pid, SIGUSR1);
		else if (shift == 0)
			kill(pid, SIGUSR2);
		usleep(500);
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
		signal(SIGUSR1, mt_recieving);
		while (av[2][i])
		{
			send_signals(av[2][i], pid);
			i++;
		}
		send_signals(0, pid);
		sleep(1);
	}
	return (0);
}
