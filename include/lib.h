/*
** lib.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:11:03 2014 chambon emmanuel
** Last update Fri May 23 20:40:53 2014 chambon emmanuel
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
char		**my_str_to_wordtab(char *, char);
void		free_tab(char **);

#endif /* !__LIB_H__ */
