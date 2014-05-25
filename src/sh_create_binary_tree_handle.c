/*
** sh_create_binary_tree2.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Thu May 15 23:31:56 2014 thomas milox
** Last update Sun May 25 18:16:03 2014 thomas milox
*/

#include "42.h"

void		patch_sep(char *cmd, int pos, char *res)
{
  if (strlen(&cmd[pos]) > 1 && cmd[pos] == ';')
    my_strncpy(res, ";", 1);
  else if (strlen(&cmd[pos]) > 2 && cmd[pos] == '|' && cmd[pos - 1] == '|')
    my_strncpy(res, "||", 2);
  else if (cmd[pos] == '&' && cmd[pos - 1] == '&')
    my_strncpy(res, "&&", 2);
}

void		patch_op(char *cmd, int pos, char *res)
{
  if (cmd[pos] == '<' && cmd[pos - 1] != '<')
    my_strncpy(res, "<", 1);
  else if (cmd[pos] == '<' && cmd[pos - 1] == '<')
    my_strncpy(res, "<<", 2);
  else if (cmd[pos] == '>' && cmd[pos - 1] != '>')
    my_strncpy(res, ">", 1);
  else if (cmd[pos] == '>' && cmd[pos - 1] == '>')
    my_strncpy(res, ">>", 2);
  else if (cmd[pos] == '|' && cmd[pos - 1] != '|')
    my_strncpy(res, "|", 1);
}

void		free_binary_tree(t_bin *tree)
{
  t_bin		*tmp;
  int		i;

  tmp = tree;
  if (tmp->cmd)
    {
      i = 0;
      while (tmp->cmd[i])
	free(tmp->cmd[i++]);
      free(tmp->cmd);
    }
  else
    free(tmp->op);
  if (tmp->l)
    free_binary_tree(tmp->l);
  if (tmp->r)
    free_binary_tree(tmp->r);
  free(tmp);
}
