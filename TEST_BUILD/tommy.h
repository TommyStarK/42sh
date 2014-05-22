/*
** tommy.h for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Tue May 13 17:54:05 2014 thomas milox
** Last update Thu May 22 22:48:37 2014 thomas milox
*/

#ifndef __TOMMY_H__
# define __TOMMY_H__

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "tools.h"

# define ERR_ENV "Error: 'ENV' is NULL.\n"
# define ERR_FORK "Error: with 'fork' syscall function.\n"
# define ERR_MALLOC "Error: something wrong occured with 'malloc syscall'.\n"
# define ERR_CMD "Shell: error-> [%s] command not found.\n"
# define ERR_STR_TO_TAB "Error: something went wrong with 'str_to_tab' call.\n"

typedef	struct		s_tools
{
  int			len;
  int			end;
  int			sep;
}			t_tools;

typedef struct		s_exe
{
  int			stdin;
  int			stdout;
  int			stderr;
  int			pipefd[2];
}			t_exe;

typedef	struct		s_bin
{
  char			*op;
  char			**cmd;
  struct s_bin		*r;
  struct s_bin		*l;
}			t_bin;

typedef struct		s_sh
{
  char			**env;
  t_exe			*exe;
  t_bin			*tree;
}			t_sh;

/* sh_create_binary_tree */
char			*patch_op_or_sep(char *, int, int);
char			*patch_cmd(char *, int);
t_bin			*new_branch(char *, int, char *);
t_bin			*create_binary_tree(t_bin **, char *, int);
/* sh_create_binary_tree_handle.c */
void			patch_sep(char *, int, char *);
void			patch_op(char *, int, char *);
void			free_binary_tree(t_bin *);
/* sh_resolve_binary_tree */
int			do_exec(t_sh *, t_bin *);
int			do_exec_local(t_sh *, t_bin *);
int			dispatch_sep_or_op(t_sh *, t_bin *);
int			resolve_binary_tree(t_sh *, t_bin **);
/* sh_operators.c */
int			make_pipe(t_sh * , t_bin *);
int			make_rredir(t_sh * , t_bin *);
int			make_d_rredir(t_sh * , t_bin *);
int			make_lredir(t_sh * , t_bin *);
int			make_d_lredir(t_sh * , t_bin *);
/* sh_operators_handle.c */
t_exe			*set_flux_rredir(t_exe *, char **, int);
t_exe			*set_flux_d_rredir(t_exe *, char **, int);
t_exe			*set_flux_lredir(t_exe *, char **, int);
char			*handle_d_lredir(char *, int);
/* sh_get_path.c */
int			check_if_env_variable_exist(char **, char *);
char			*get_path(t_sh *, t_bin *);
char			*patch_path_to_execve(t_bin *, int, char *);
/* sh_signals.c */
void			signal_seg(int);
/* TOOLS */
char			*get_next_line(const int);
char			**str_wtab(char *);
char			**str_to_tab(char *, char);
#endif /* ! __TOMMY_H__ */
