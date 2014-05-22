##
## Makefile for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
## 
## Made by chambon emmanuel
## Login   <chambo_e@epitech.net>
## 
## Started on  Tue May 20 21:58:44 2014 chambon emmanuel
## Last update Thu May 22 23:25:51 2014 chambon emmanuel
##

CC		=	gcc

RM		=	rm -f

INCLUDE_F	=	include/

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic -I$(INCLUDE_F)

SRC_F		=	src/

LIB_F		=	src/lib/

BTIN_F		=	src/builtins/

SRC		=	$(SRC_F)main.c				\
			$(SRC_F)get_env.c			\
			$(SRC_F)node_shell.c			\
			$(SRC_F)config.c			\
			$(SRC_F)free_sh.c			\
			$(SRC_F)print_tree.c			\
			$(SRC_F)sh_resolve_binary_tree.c			\
			$(SRC_F)sh_create_binary_tree.c			\
			$(SRC_F)sh_create_binary_tree_handle.c			\
			$(SRC_F)sh_operators.c			\
			$(SRC_F)sh_operators_handle.c			\
			$(SRC_F)sh_signals.c			\
			$(SRC_F)sh_get_path.c			\
			$(SRC_F)str_to_tab.c			\
			$(SRC_F)str_wtab.c			\
			$(SRC_F)tools1.c			\
			$(SRC_F)tools2.c			\
			$(SRC_F)tools3.c			\
			$(BTIN_F)common_builtins.c		\
			$(BTIN_F)check_builtins.c		\
			$(BTIN_F)cd/cd.c			\
			$(BTIN_F)echo/echo.c			\
			$(BTIN_F)env/env/env.c			\
			$(BTIN_F)env/setenv/setenv.c		\
			$(BTIN_F)env/unsetenv/unsetenv.c	\
			$(LIB_F)my_putchar.c			\
			$(LIB_F)my_strcat.c			\
			$(LIB_F)my_putstr.c			\
			$(LIB_F)get_next_line.c			\
			$(LIB_F)my_xmalloc.c

OBJ		=	$(SRC:.c=.o)

NAME		=	42sh


$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
		 	$(RM) $(NAME)

re		:	fclean all
