##
## Makefile for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
## 
## Made by chambon emmanuel
## Login   <chambo_e@epitech.net>
## 
## Started on  Tue May 20 21:58:44 2014 chambon emmanuel
## Last update Tue May 20 22:20:13 2014 chambon emmanuel
##

CC		=	gcc

RM		=	rm -f

INCLUDE_F	=	include/

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic -I$(INCLUDE_F)

SRC_F		=	src/

LIB_F		=	src/lib/

SRC		=	$(SRC_F)main.c		\
			$(SRC_F)get_env.c	\
			$(SRC_F)node_shell.c	\
			$(SRC_F)free_sh.c	\
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
