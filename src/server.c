/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:16:27 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/07 22:47:47 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minitalk.h"
# include <stdio.h>


void	signal_handler(int checking, siginfo_t *info)
{
	static char	*store;
	static int client_pid;

	if(client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		// printf("this is info for client : %d\n", client);
		store = 0;
	}
	if (checking == SIGUSR1)
		store = mt_strjoin(store, "1");
	if (checking == SIGUSR2)
		store = mt_strjoin(store, "0");
	if (mt_strlen(store) == 8)
	{
		mt_putchar(mt_btod(mt_atoi(store)));
		store = NULL;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	struct sigaction act;

	(void)av;

	if (ac != 1)
	{
		mt_putstr("Some thing is wrong with arguments\n");
		return (1);
	}
	act.sa_handler = (void*)signal_handler;
	pid = getpid();
	mt_putnbr(pid);
	mt_putstr("\n");

	if ((sigaction(SIGUSR1, &act, NULL)) < 0)
		mt_putstr("Err.. the signal not recieving!\n");
	if ((sigaction(SIGUSR2, &act, NULL)) < 0)
		mt_putstr("Err.. the signal not recieving!\n");
	while (1)
		pause();
}
