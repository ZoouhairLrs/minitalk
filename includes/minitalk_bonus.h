/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:37:15 by zlaarous          #+#    #+#             */
/*   Updated: 2023/01/09 17:16:12 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <strings.h>
//Tools headers :
int		mt_atoi(char *c);
int		mt_sign_in(int nbr, int sign);
int		mt_btod(int binary);
void	mt_putchar(char c);
void	mt_putnbr(int nb);
void	mt_putstr(char *str);
char	*mt_strjoin(char *s1, char *s2);
int		mt_strlen(char *str);

#endif