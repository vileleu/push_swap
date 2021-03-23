BLUE = 		\033[0;34m
GREEN = 	\033[0;32m
LIGHTBLUE = \033[1;34m
RED = 		\033[0;31m
YELLOW = 	\033[1;33m
ORANGE = 	\033[0;33m
MAGENTA = 	\033[0;35m
RESET = 	\033[0m

SRCS_C		= $(wildcard srcs/checker/*.c) $(wildcard srcs/common_files/*.c)

SRCS_PS		= $(wildcard srcs/push_swap/*.c) $(wildcard srcs/common_files/*.c)

OBJS_C		= ${SRCS_C:.c=.o}

OBJS_PS		= ${SRCS_PS:.c=.o}

NAME_C		= checker

NAME_PS		= push_swap

LIBFT		= srcs/libft/

HEADERS		= -I includes/

FLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

.c.o:		
			@gcc ${FLAGS} ${HEADERS} -I ${LIBFT} -c $< -o ${<:.c=.o} > /dev/null

${NAME_PS}:	${OBJS_C} ${OBJS_PS}
			@echo "$(BLUE)"
			@make -C $(LIBFT) all
			@echo "$(BLUE)Compiling files..."
			@gcc ${FLAGS} ${OBJS_C} ${LIBFT}/libft.a -o ${NAME_C} > /dev/null
			@echo "$(GREEN)[checker done][✔]$(RESET)"
			@echo "$(BLUE)Compiling files..."
			@gcc ${FLAGS} ${OBJS_PS} ${LIBFT}/libft.a -o ${NAME_PS} > /dev/null
			@echo "$(GREEN)[push_swap done][✔]$(RESET)"

all:		${NAME_PS}

clean:
			@echo ""
			@echo "$(RED)Erase files '.o'"
			@make -C $(LIBFT) clean
			@rm -rf $(OBJS_C) $(OBJS_PS)
			@echo "\033[0m"

fclean:
			@echo ""
			@echo "$(RED)Erase files '.o'"
			@make -C $(LIBFT) clean
			@rm -rf $(OBJS_C) $(OBJS_PS)
			@echo "$(RED)Delete executable file and libft"
			@make -C $(LIBFT) fclean
			@rm -rf ${NAME_C} ${NAME_PS}
			@echo "$(RESET)"

re:			fclean all

.PHONY:		clean fclean re all