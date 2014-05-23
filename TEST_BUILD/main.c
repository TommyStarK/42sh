/*
** main.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Tue May 13 18:01:59 2014 thomas milox
** Last update Fri May 23 06:47:32 2014 chambon emmanuel
*/

#include "tommy.h"

void		print_tree(t_bin *tree)
{
  t_bin		*tmp;
  int		i;

  tmp = tree;
  if (tmp->cmd)
    {
      i = 0;
      while (tmp->cmd[i])
	printf("##### cmd :%s ###############\n", tmp->cmd[i++]);
    }
  else
    printf("###### operator :%s  #############\n", tmp->op);
  if (tmp->l)
    print_tree(tmp->l);
  if (tmp->r)
    print_tree(tmp->r);
}

int		main(int ac, char **av, char **env)
{
  t_sh		sh;
  char		buff[1024];

  (void)ac;
  sh.env = env;
  int i = 0;
  printf("NOUVEAU SHELLLLLL ###################################################\n");
  while (i = read(0, buff, 1024))
    {
      buff[i - 1] = 0;
      if (!(strcmp(buff, "exit")))
	return (0);
      epur_str(buff);
      sh.tree = create_binary_tree(&sh.tree, buff, my_strlen(buff));
      print_tree(sh.tree);
      resolve_binary_tree(&sh, &sh.tree);
      free_binary_tree(sh.tree);
    }
  return (0);
}
