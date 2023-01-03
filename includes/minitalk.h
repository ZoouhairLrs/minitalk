/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:12:10 by inf               #+#    #+#             */
/*   Updated: 2023/01/03 18:11:51 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
#include <strings.h>

//Tools headers :
int	mt_atoi(char *c);
int	mt_check(int nbr, int sign);
int	mt_convert_to_decimal(int binary);
void	mt_putchar(char c);
void	mt_putnbr(int nb);
void	mt_putstr(char *str);
char	*mt_strjoin(char *s1, char *s2);
int	mt_strlen(char *str);

//Mendatory :
void	signal_handler(int checking);
void	send_bits(char c, int pid);

#endif
