/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:51:32 by inf               #+#    #+#             */
/*   Updated: 2023/01/03 16:48:17 by zlaarous         ###   ########.fr       */
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
		mt_putchar(mt_convert_to_decimal(mt_atoi(store)));
		store = NULL;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
	{
		mt_putstr("Wrong arguments\n");
		return (1);
	}
	pid = getpid();
	mt_putnbr(pid);
	mt_putstr("\n");
	if ((signal(SIGUSR1, signal_handler)) < 0)
		write(1, "Error recieving the signal\n", 27);
	if ((signal(SIGUSR2, signal_handler)) < 0)
		write(1, "Error recieving the signal\n", 27);
	while (1)
		pause();
}
