# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 21:18:39 by zlaarous          #+#    #+#              #
#    Updated: 2023/01/10 16:57:23 by zlaarous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

FLAGS = -Wall -Wextra -Werror

NAME_C = client

NAME_S = server

# NAME_CB = client_bonus

# NAME_SB = server_bonus

SRC_C = ./src/client.c

SRC_S = ./src/server.c

# SRC_CB = client_bonus.c

# SRC_SB = server_bonus.c

UTILS = ./Tools/mt_atoi.c \
		./Tools/mt_btod.c \
		./Tools/mt_putchar.c \
		./Tools/mt_putnbr.c \
		./Tools/mt_putstr.c \
		./Tools/mt_sign_in.c \
		./Tools/mt_strjoin.c \
		./Tools/mt_strlen.c \

OBJ = ${patsubst %.c, %.o, ${UTILS}}

all : ${NAME_C} ${NAME_S}

${NAME_C} :
	${CC} ${FLAGS} ${SRC_C} ${UTILS} -o ${NAME_C}

${NAME_S} :
	${CC} ${FLAGS} ${SRC_S} ${UTILS} -o ${NAME_S}

# bonus : all
# 	${CC} ${FLAGS} ${SRC_SB} ${UTILS} -o ${NAME_SB}
# 	${CC} ${FLAGS} ${SRC_CB} ${UTILS} -o ${NAME_CB}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME_C} ${NAME_S} 
# ${NAME_SB} ${NAME_CB}

re : fclean all

.PHONY : all clean fclean re