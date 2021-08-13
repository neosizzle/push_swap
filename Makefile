NAME1 = checker
NAME2 = push_swap
GCC = gcc -Wall -Wextra
SRCS1 = src/checker/*.c src/common/*.c libft/*.c
SRCS2 = src/push_swap/*.c src/common/*.c libft/*.c
INCLUDES = includes
LIBFT = libft/libft.a

all : ${NAME2} ${NAME1}

${NAME2} : 
	make -C libft
	${GCC} -I ${INCLUDES} ${SRCS2} -o ${NAME2}

${NAME1} : 
	make -C libft
	${GCC} -I ${INCLUDES} ${SRCS1} -o ${NAME1}


clean : 
	rm -f *.o

fclean :
	rm -f *.o ${NAME2} ${NAME1}

re: fclean all

.PHONY: all clean fclean re
