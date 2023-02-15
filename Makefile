NAME = minishell
SRC = main.c error.c tools.c linked_list.c
CFLAGS = -Wall -Wextra -Werror
BREW_FLAGS = -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

all : ${NAME}

${NAME} : ${SRC}
	cc ${CFLAGS} ${BREW_FLAGS} ${SRC} -o minishell
clean :
	rm -rf minishell
flean : clean

re : fcean all
