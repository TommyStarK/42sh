/*
** sh_create_binary_tree.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Wed May 14 02:23:57 2014 thomas milox
** Last update Sun May 25 22:13:33 2014 Dorian Amouroux
*/

#include "42.h"

char		*patch_op_or_sep(char *cmd, int pos, int flag)
{
  char		*res;

  if (!cmd)
    return (NULL);
  if (!(res = my_xmalloc(sizeof(char) * 3)))
    return (NULL);
  memset(res, 0, 3);
  if (pos == 0)
    return (NULL);
  if (!flag)
    patch_sep(cmd, pos, res);
  if (flag == 1)
    patch_op(cmd, pos, res);
  return (res);
}

char		*patch_cmd(char *s, int size)
{
  int		i;
  char		*ret;

  if (!s)
    return (NULL);
  if (!(ret = my_xmalloc(sizeof(char) * (size + 1))))
    {
      fprintf(stderr, ERR_MALLOC);
      return (NULL);
    }
  i = 0;
  while (i < size)
    {
      ret[i] = s[i];
      ++i;
    }
  ret[i] = '\0';
  return (ret);
}

t_bin		*new_branch(char *current_cmd, int size, char *current_op)
{
  char		*cmd_part;
  t_bin		*tmp;

  cmd_part = NULL;
  if (!(tmp = my_xmalloc(sizeof(t_bin))))
    return (NULL);
  if (!current_cmd)
    {
      tmp->op = current_op;
      tmp->cmd = NULL;
    }
  else
    {
      tmp->op = NULL;
      cmd_part = patch_cmd(current_cmd, size);
      tmp->cmd = globing(my_str_to_wordtab(epur_str(cmd_part), ' '));
      free(cmd_part);
    }
  tmp->r = NULL;
  tmp->l = NULL;
  return (tmp);
}

t_bin		*create_binary_tree(t_bin **tree, char *s, int z)
{
  char		*op;
  t_tools	t;

  t.sep = -1;
  while (++t.sep < 2)
    {
      t.end = z - 1;
      while (t.end > 0)
	{
	  op = patch_op_or_sep(s, t.end, t.sep);
	  t.len = (int)strlen(op) + 1;
	  if (op[0])
	    {
	      *tree = new_branch(NULL, 0, op);
	      (*tree)->l = create_binary_tree(&((*tree)->l), s, t.end - t.len + 2);
	      (*tree)->r = create_binary_tree(&((*tree)->r), &s[t.end + t.len - 1],
					      (z - t.end - t.len + 1));
	      return (*tree);
	    }
	  free(op);
	  --t.end;
	}
    }
  *tree = new_branch(s, z, NULL);
  return (*tree);
}
