/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:16:27 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/12 16:56:28 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int checking, siginfo_t *info)
{
	static char	*pool;
	static int	client_pid;

	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		if (pool)
			free(pool);
		pool = 0;
	}
	if (checking == SIGUSR1)
		pool = mt_strjoin(pool, "1");
	if (checking == SIGUSR2)
		pool = mt_strjoin(pool, "0");
	if (mt_strlen(pool) == 8)
	{
		mt_putchar(mt_btod(mt_atoi(pool)));
		if (pool)
			free (pool);
		pool = NULL;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		mt_putstr("Some thing is wrong with arguments\n");
		return (1);
	}
	act.sa_handler = (void *)signal_handler;
	pid = getpid();
	mt_putnbr(pid);
	mt_putstr("\n");
	sigaction(SIGUSR1, &act, NULL);
	(sigaction(SIGUSR2, &act, NULL));
	while (1)
		pause();
}
