NAME1 = checker
NAME2 = push_swap
GCC = gcc -Wall -Wextra -fsanitize=address
SRCS1 = src/checker/*.c src/common/*.c
SRCS2 = src/push_swap/*.c src/common/*.c
INCLUDES = includes
LIBFT = libft/libft.a

all : ${NAME2} ${NAME1}

${NAME2} : 
	make -C libft
	${GCC} -I ${INCLUDES} ${SRCS2} ${LIBFT} -o ${NAME2}

${NAME1} : 
	make -C libft
	${GCC} -I ${INCLUDES} ${SRCS1} ${LIBFT} -o ${NAME1}


clean : 
	rm -f *.o

fclean :
	rm -f *.o ${NAME2} ${NAME1}

re: fclean all

.PHONY: all clean fclean re
