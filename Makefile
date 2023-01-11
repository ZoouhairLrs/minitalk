# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 21:18:39 by zlaarous          #+#    #+#              #
#    Updated: 2023/01/11 20:10:21 by zlaarous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

FLAGS = -Wall -Wextra -Werror

NAME_CLIENT = client

NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus

NAME_SERVER_BONUS = server_bonus

SRC_CLIENT = ./src/client.c

SRC_SERVER = ./src/server.c

SRC_CLIENT_BONUS = ./bonus/client_bonus.c

SRC_SERVER_BONUS = ./bonus/server_bonus.c

TOOLS = ./Tools/mt_atoi.c \
		./Tools/mt_btod.c \
		./Tools/mt_putchar.c \
		./Tools/mt_putnbr.c \
		./Tools/mt_putstr.c \
		./Tools/mt_sign_in.c \
		./Tools/mt_strjoin.c \
		./Tools/mt_strlen.c \

OBJ = ${patsubst %.c, %.o, ${TOOLS}}

all : ${NAME_CLIENT} ${NAME_SERVER}

${NAME_CLIENT} :
	${CC} ${FLAGS} ${SRC_CLIENT} ${TOOLS} -o ${NAME_CLIENT}

${NAME_SERVER} :
	${CC} ${FLAGS} ${SRC_SERVER} ${TOOLS} -o ${NAME_SERVER}

bonus : all
	${CC} ${FLAGS} ${SRC_SERVER_BONUS} ${TOOLS} -o ${NAME_SERVER_BONUS}
	${CC} ${FLAGS} ${SRC_CLIENT_BONUS} ${TOOLS} -o ${NAME_CLIENT_BONUS}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME_CLIENT} ${NAME_SERVER} ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

re : fclean all

.PHONY : all clean fclean re