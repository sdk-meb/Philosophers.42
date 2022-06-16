
NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

FILE_PHILO = main.c parsing.c init.c  philo.util.c daily_philosophy.c sit_to_table.c

OBJ_PHILO = $(FILE_PHILO:.c=.o)

%.o:%.c philo.h 
	@${CC} ${CFLAGS} -o $@ -c $<

all: ${NAME} 

${NAME} : ${OBJ_PHILO}
	@echo " • All object files was created "
	@${CC} ${CFLAGS} -o ${NAME} ${OBJ_PHILO}
	

clean :
	@rm -rf ${OBJ_PHILO}
	@echo " • All object files was removed "

fclean : clean
	@rm -rf ${NAME}
	@echo " • The executed file was removed"

re : fclean all

.PHONY: re fclean clean all
