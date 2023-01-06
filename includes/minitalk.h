/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:15:51 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/05 23:52:57 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <strings.h>
//Tools headers :
int     mt_atoi(char *c);
int     mt_sign_in(int nbr, int sign);
int     mt_btod(int binary);
void	mt_putchar(char c);
void	mt_putnbr(int nb);
void	mt_putstr(char *str);
char	*mt_strjoin(char *s1, char *s2);
int     mt_strlen(char *str);
//Mendatory :
void	signal_handler(int checking);
void	send_bits(char c, int pid);

#endif
