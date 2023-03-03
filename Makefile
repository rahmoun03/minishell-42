NAME = minishell
SRC = main.c error.c tools.c linked_list.c ft_split.c \
	split_special.c double_quotes.c expand_vrbs.c execution/exec.c \
	execution/get_path.c
CFLAGS = -Wall -Wextra -Werror
BREW_FLAGS = -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

all : ${NAME}

${NAME} : ${SRC}
	cc ${CFLAGS} ${BREW_FLAGS} ${SRC} -o minishell
clean :
	rm -rf minishell
fclean : clean

re : fclean all
