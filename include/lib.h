/*
** lib.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:11:03 2014 chambon emmanuel
** Last update Thu May 22 15:21:19 2014 chambon emmanuel
*/

#ifndef __LIB_H__
# define __LIB_H__

# define BUFF_SIZE	4096

char		*get_next_line(int);
void		*my_xmalloc(size_t);
void		my_putchar(char);
void		my_putstr(char *);
char		*my_strcat(char *, char *);
char		*strdup(char *);

#endif /* !__LIB_H__ */
