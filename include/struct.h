/*
** struct.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 21:59:45 2014 chambon emmanuel
** Last update Sat May 24 09:16:19 2014 thomas milox
*/

#ifndef __STRUCT_H__
# define __STRUCT_H__

typedef struct		s_tools
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

typedef struct		s_bin
{
  int			success;
  char			*op;
  char			**cmd;
  struct s_bin		*r;
  struct s_bin		*l;
}			t_bin;

typedef struct		s_alias
{
  char			*alias;
  char			*replace;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_misc
{
  int			last_return;
  pid_t			pid_pgr;
  pid_t			last_pgr;
  char			**av;
  int			ac;
}			t_misc;

typedef struct		s_sh
{
  int			success;
  char			**env;
  char			*prompt;
  t_exe			*exe;
  t_bin			*tree;
  t_alias		*alias;
  t_misc		misc;
}			t_sh;

#endif /* !__STRUCT_H__ */
