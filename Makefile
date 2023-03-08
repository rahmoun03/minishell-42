# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 18:33:48 by arahmoun          #+#    #+#              #
#    Updated: 2023/03/08 14:07:17 by arahmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = main.c error.c tools.c linked_list.c ft_split.c split_special.c double_quotes.c expand_vrbs.c pid.c ft_itoa.c \
	execution/exec.c execution/get_path.c execution/tools.c
CFLAGS = -Wall -Wextra -Werror
BREW_FLAGS = -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

all : ${NAME}

${NAME} : ${SRC}
	cc ${CFLAGS} ${BREW_FLAGS} ${SRC} -o minishell
clean :
	rm -rf minishell
fclean : clean

re : fclean all
