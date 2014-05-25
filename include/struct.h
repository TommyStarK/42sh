/*
** struct.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 21:59:45 2014 chambon emmanuel
** Last update Sun May 25 20:03:00 2014 Dorian Amouroux
*/

#ifndef __STRUCT_H__
# define __STRUCT_H__

typedef struct		termios t_termios;

typedef	struct		s_termcaps
{
  char			*name;
  char			*code;
}			t_termcaps;

union			u_buffer
{
  int			int_value;
  char			tab_value[4];
};

typedef struct		s_str
{
  int			pos;
  char			str[1024];
  int			len;
}			t_str;

typedef struct		s_hist
{
  char			*str;
  struct s_hist		*prev;
  struct s_hist		*next;
}			t_hist;

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
  char			**env;
  char			*prompt;
  t_exe			*exe;
  t_bin			*tree;
  t_alias		*alias;
  t_hist		*history;
  t_misc		misc;
}			t_sh;

typedef struct		s_editor
{
  t_str			command;
  t_sh			sh;
  int			len_prompt;
  t_termios		term;
  t_hist		*history;
  t_hist		*current;
  t_hist		*last;
  int			fd_history;
  int			mode;
  char			*history_file_name;
}			t_editor;

typedef struct		s_action
{
  int			keycode;
  int			(*function)(t_editor *);
}			t_action;

#endif /* !__STRUCT_H__ */
