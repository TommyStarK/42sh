/*
** 42.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 21:59:05 2014 chambon emmanuel
** Last update Sun May 25 23:06:41 2014 chambon emmanuel
*/

#ifndef __42_H__
# define __42_H__

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
# include <errno.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "error.h"
# include "lib.h"
# include "struct.h"
# include "builtins.h"
# include "exec.h"
# include "prompt.h"
# include "read.h"

char		**get_env(char **);
int		node_shell(t_editor *);
void		free_sh(t_sh *);
int		conf_read(t_sh *sh);
pid_t		vfork(void);

#endif /* !__42_H__ */
