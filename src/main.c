/*
** main.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:01:26 2014 chambon emmanuel
** Last update Sun May 25 21:34:38 2014 Dorian Amouroux
*/

#include "42.h"

void		set_struct(t_editor *editor, int ac, char **av)
{
  editor->sh.alias = NULL;
  editor->sh.prompt = NULL;
  editor->sh.tree = NULL;
  editor->sh.exe = NULL;
  editor->sh.misc.last_return = 0;
  editor->sh.misc.pid_pgr = getpid();
  editor->sh.misc.last_pgr = 0;
  editor->sh.misc.av = av;
  editor->sh.misc.ac = ac;
}

int		main(int ac, char **av, char **env)
{
  t_editor     	editor;

  if (!(editor.sh.env = get_env(env)))
    return (-1);
  set_struct(&editor, ac, av);
  if ((editor.mode = init_editor(&editor)) == -1)
    return (1);
  conf_read(&editor.sh);
  while (node_shell(&editor) != -1);
  free_sh(&editor.sh);
  exit_editor(&editor);
  free_all();
  return (0);
}
