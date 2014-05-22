/*
** 42.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 21:59:05 2014 chambon emmanuel
** Last update Thu May 22 15:21:48 2014 chambon emmanuel
*/

#ifndef __42_h__
# define __42_h__

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <strings.h>
# include "error.h"
# include "lib.h"
# include "struct.h"
# include "builtins.h"

char		**get_env(char **);
int		node_shell(t_sh *);
void		free_sh(t_sh *);
int		conf_read(t_sh *sh);

#endif /* !__42_H__ */
