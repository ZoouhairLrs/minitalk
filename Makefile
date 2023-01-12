# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 21:18:39 by zlaarous          #+#    #+#              #
#    Updated: 2023/01/12 13:05:34 by zlaarous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = ./includes/minitalk.h

INCLUDE_BONUS = ./includes/minitalk_bonus.h

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME_CLIENT = client

NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus

NAME_SERVER_BONUS = server_bonus

SRC_CLIENT = ./src/client.c
OBJ_CLIENT = ./src/client.o

SRC_SERVER = ./src/server.c
OBJ_SERVER = ./src/server.o

SRC_CLIENT_BONUS = ./bonus/client_bonus.c
OBJ_CLIENT_BONUS = ./bonus/client_bonus.o

SRC_SERVER_BONUS = ./bonus/server_bonus.c
OBJ_SERVER_BONUS = ./bonus/server_bonus.o

TOOLS = ./Tools/mt_atoi.c \
		./Tools/mt_btod.c \
		./Tools/mt_putchar.c \
		./Tools/mt_putnbr.c \
		./Tools/mt_putstr.c \
		./Tools/mt_sign_in.c \
		./Tools/mt_strjoin.c \
		./Tools/mt_strlen.c \

TOBJ = ${patsubst %.c, %.o, ${TOOLS}}

all : ${NAME_CLIENT} ${NAME_SERVER}

${NAME_CLIENT} : ${TOBJ} ${OBJ_CLIENT}
	${CC} ${FLAGS} ${OBJ_CLIENT} ${TOBJ} -o ${NAME_CLIENT}

${NAME_SERVER} : ${TOBJ} ${OBJ_SERVER}
	${CC} ${FLAGS} ${OBJ_SERVER} ${TOBJ} -o ${NAME_SERVER}

bonus : ${TOBJ} ${OBJ_SERVER_BONUS} ${OBJ_CLIENT_BONUS}
	${CC} ${FLAGS} ${OBJ_SERVER_BONUS} ${TOBJ} -o ${NAME_SERVER_BONUS}
	${CC} ${FLAGS} ${OBJ_CLIENT_BONUS} ${TOBJ} -o ${NAME_CLIENT_BONUS}

%.o : %.c ${INCLUDE} ${INCLUDE_BONUS}
	$(CC) $(FLAGS) $< -c -o $@

clean :
	rm -rf ${TOBJ} ${OBJ_CLIENT} ${OBJ_SERVER} ${OBJ_SERVER_BONUS} ${OBJ_CLIENT_BONUS}

fclean : clean
	rm -rf ${NAME_CLIENT} ${NAME_SERVER} ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

re : fclean all

.PHONY : all clean fclean re