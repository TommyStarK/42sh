/*
** struct.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 21:59:45 2014 chambon emmanuel
** Last update Wed May 21 13:57:00 2014 chambon emmanuel
*/

#ifndef __STRUCT_H__
# define __STRUCT_H__

typedef struct		s_alias
{
  char			*alias;
  char			*replace;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_sh
{
  char			**env;
  char			*prompt;
  // t_exe			*exe;
  // t_bin			*tree;
  t_alias		*alias;
}			t_sh;

#endif /* !__STRUCT_H__ */
