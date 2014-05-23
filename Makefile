##
## Makefile for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
## 
## Made by chambon emmanuel
## Login   <chambo_e@epitech.net>
## 
## Started on  Tue May 20 21:58:44 2014 chambon emmanuel
## Last update Fri May 23 06:51:45 2014 chambon emmanuel
##

CC		=	gcc -g

RM		=	rm -f

INCLUDE_F	=	include/

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic -I$(INCLUDE_F)

SRC_F		=	src/

LIB_F		=	src/lib/

BTIN_F		=	src/builtins/

SRC		=	$(SRC_F)*.c			\
			$(LIB_F)my_putchar.c			\
			$(LIB_F)my_strcat.c			\
			$(LIB_F)my_str_to_wordtab.c			\
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
