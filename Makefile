BLUE = 		\033[0;34m
GREEN = 	\033[0;32m
LIGHTBLUE = \033[1;34m
RED = 		\033[0;31m
YELLOW = 	\033[1;33m
ORANGE = 	\033[0;33m
MAGENTA = 	\033[0;35m
RESET = 	\033[0m

SRCS		= $(wildcard srcs/checker/*.c)

OBJS		= ${SRCS:.c=.o}

NAME		= checker

LIBFT		= srcs/libft/

HEADERS		= -I includes/

FLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

.c.o:		
			@gcc ${FLAGS} ${HEADERS} -I ${LIBFT} -c $< -o ${<:.c=.o} > /dev/null

${NAME}:	${OBJS}
			@echo "$(BLUE)"
			@make -C $(LIBFT) all
			@echo "$(BLUE)Compiling files...$(BLUE)"
			@gcc ${FLAGS} ${OBJS} ${LIBFT}/libft.a -o ${NAME} > /dev/null
			@echo "$(GREEN)[✔]$(RESET)"

all:		${NAME}

clean:
			@echo ""
			@echo "$(RED)Erase files '.o'"
			@make -C $(LIBFT) clean
			@rm -rf $(OBJS)
			@echo "\033[0m"

fclean:
			@echo ""
			@echo "$(RED)Erase files '.o'"
			@make -C $(LIBFT) clean
			@rm -rf $(OBJS)
			@echo "$(RED)Delete executable file and libft"
			@make -C $(LIBFT) fclean
			@rm -rf ${NAME}
			@echo "$(RESET)"

re:			fclean all

.PHONY:		clean fclean re all