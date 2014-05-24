/*
** builtins.h for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 22 15:18:26 2014 chambon emmanuel
** Last update Sat May 24 06:31:07 2014 chambon emmanuel
*/

#ifndef __BUILTINS_H__
# define __BUILTINS_H__

#include "42.h"

int		tab_len(char **, char *);
int		check_present(char *, char **);
int		add_item(char *, char *, t_sh *);
int		cd(char **, t_sh *);
int		echo(char **);
int		my_env(char **, t_sh *, int);
int		my_setenv(char **, t_sh *);
int		my_unsetenv(char **, t_sh *);
int		check_builtins(t_sh *, t_bin *);
int		alias(t_sh *, char **);

#endif /* __BUILTINS_H__ */
