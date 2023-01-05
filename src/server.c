/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:16:27 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/05 22:16:30 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"


void	signal_handler(int checking)
{
	static char	*store;

	if (checking == SIGUSR1)
		store = mt_strjoin(store, "1");
	if (checking == SIGUSR2)
		store = mt_strjoin(store, "0");
	if (mt_strlen(store) == 8)
	{
		mt_putchar(mt_btod(mt_atoi(store)));
		store = NULL;
	}
	// printf("this store : %s\n", store);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
	{
		mt_putstr("Some thing is wrong with arguments\n");
		return (1);
	}
	pid = getpid();
	mt_putnbr(pid);
	mt_putstr("\n");

	if ((signal(SIGUSR1, signal_handler)) < 0)
		mt_putstr("Err.. the signal not recieving!\n");
	if ((signal(SIGUSR2, signal_handler)) < 0)
		mt_putstr("Err.. the signal not recieving!\n");
	while (1)
		pause();
}
