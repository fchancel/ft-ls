# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/30 11:28:22 by fchancel     #+#   ##    ##    #+#        #
#    Updated: 2019/01/30 12:44:26 by fchancel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		= 	ft_ls
SRC_PATH 	= 	src
SRC_NAME 	=	main.c						\
				display.c					\
				manage_flag.c				\
				ft_linked_list.c			\
				launcher_ls.c				\
				manage_dir.c				\
				annex_function.c			\
				function_sort.c				\
				function_sort_annex.c		\
				display_permit.c			\
				display_detail.c			\
				display_error.c				\
				get_size.c					\
				column.c					\
				count.c						\
				launcher_display_detail.c	\
				struct_for_col.c

OBJ_PATH	= 	obj
CPPFLAGS	=	-I include
LDFLAG		= 	-L libft
LDLIBS		=	-lft
CC 			=	clang
CFLAGS 		=	-Werror -Wall -Wextra

OBJ_NAME 	= 	$(SRC_NAME:.c=.o)

SRC 		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ 		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAG) $(LDLIBS) $^ -o $@
	@echo "Compilation Ft_ls .... OK"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Clean Ft_ls .......... OK"

fclean: clean
	@rm -f libft/libft.a
	@rm -fv $(NAME)
	@echo "Fclean Ft_ls .......... OK"
re: fclean all
