/*
** lib.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:11:03 2014 chambon emmanuel
** Last update Sun May 25 01:33:25 2014 chambon emmanuel
*/

#ifndef __LIB_H__
# define __LIB_H__

# define BUFF_SIZE	4096

typedef struct  s_it
{
  int           i;
  int           j;
  int           size;
}               t_it;

char		*get_next_line(int);
void		*my_xmalloc(size_t);
void		my_putchar(char);
void		my_putstr(char *);
char		*my_strcat(char *, char *);
char		*strdup(char *);
char		**my_str_to_wordtab(char *, char);
void		free_tab(char **);
char            *epur_str(char *);
char            *my_strncpy(char *, char *, int);
char            *my_strcpy(char *, char *);
int		my_putchar_color(char, int);
int		my_putstr_color(char *, int);
char		*strcat_dat(char **);

#endif /* !__LIB_H__ */
