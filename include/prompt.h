/*
** prompt.h for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 24 00:32:22 2014 chambon emmanuel
** Last update Sat May 24 00:46:14 2014 chambon emmanuel
*/

#ifndef __PROMPT_H__
 #define __PROMPT_H__

# include "struct.h"

int		print_prompt(t_sh *);
int		my_varlen(char *);
char		*my_strncpy_m(char *, int);
int		get_color_code(char *);
char		*my_getenv(char **, char *);
int		set_prompt(t_sh *, char **);

#endif /* !__PROMPT_H__ */
