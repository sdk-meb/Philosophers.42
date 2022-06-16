
NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

FILE_PHILO = main_bonus.c parsing_bonus.c init_bonus.c  philo.util_bonus.c \
				daily_bonus.c sit_to_table_bonus.c

OBJ_PHILO = $(FILE_PHILO:.c=.o)

%.o:%.c philo_bonus.h
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
