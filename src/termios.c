/*
** read_stdin.c for 42sh in /home/amouro_d/Dropbox/42sh/src
**
** Made by Dorian Amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Fri May  9 14:06:40 2014 Dorian Amouroux
** Last update Sun May 25 17:18:56 2014 Dorian Amouroux
*/

#include "42.h"

struct winsize	size_term;

int	init_editor(t_editor *editor)
{
  int	ret;
  char	*term;

  if (!(term = getenv("TERM")))
    return (1);
  if ((ret = tgetent(NULL, term)) != 1)
    {
      if (ret == -1)
	perror("tgetent");
      return (1);
    }
  if (tcgetattr(0, &editor->term) == -1)
    return (my_perror("tcgetattr", 1));
  if (tcsetattr(0, 0, &editor->term) == -1)
    return (my_perror("tcsetattr", 1));
  if (ioctl(0, TIOCGWINSZ, &size_term) == -1)
    return (my_perror("ioctl", 1));
  if (signal(SIGWINCH, &handle_winch) == SIG_ERR)
    return (my_perror("signal", 1));
  if (init_history(editor) == -1)
    return (1);
  return (0);
}

int		exit_editor(t_editor *editor)
{
  t_hist	*tmp;

  if (editor->mode == 1)
    return (0);
  if (tcsetattr(0, 0, &editor->term) == -1)
    return (my_perror("tcsetattr", 1));
  tmp = editor->history;
  if ((editor->fd_history = open(".history",
				 O_TRUNC | O_CREAT |  O_WRONLY, 0644)) == -1)
    return (my_perror("open", 1));
  while (tmp != NULL)
    {
      if (write(editor->fd_history, tmp->str, strlen(tmp->str)) == -1)
	return (my_perror("write", 1));
      if (write(editor->fd_history, "\n", 1) == -1)
	return (my_perror("write", 1));
      tmp = tmp->next;
    }
  close(editor->fd_history);
  return (0);
}

int	init_history(t_editor *editor)
{
  char	*file;
  char	**file_wt;
  int	i;

  editor->history = NULL;
  editor->fd_history = open(".history", O_RDONLY, 0644);
  if (editor->fd_history == -1)
    return (0);
  if (!(file = get_file_history(editor->fd_history)))
    return (0);
  close(editor->fd_history);
  if (!(file_wt = wordtab(file, "\n")))
    return (-1);
  i = 0;
  while (file_wt[i] != NULL)
    {
      if (add_command_history(&editor->history, file_wt[i]) == -1)
	return (-1);
      i++;
    }
  return (0);
}

int	unset_editor(t_editor *editor)
{
  editor->term.c_lflag |= ICANON | ECHO;
  editor->term.c_cc[VMIN] = 0;
  editor->term.c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, &editor->term) == -1)
    return (my_perror("tcsetattr", -1));
  return (0);
}

int	set_editor(t_editor *editor)
{
  editor->term.c_lflag &= ~(ICANON | ECHO);
  editor->term.c_cc[VMIN] = 1;
  editor->term.c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, &editor->term) == -1)
    return (my_perror("tcsetattr", -1));
  return (0);
}
