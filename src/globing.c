/*
** globing.c for globing in /home/sarda_j/Dropbox/Epitech/rendu/minishell2
**
** Made by sarda_j
** Login   <sarda_j@epitech.net>
**
** Started on  Tue Apr 15 08:39:30 2014 sarda_j
** Last update Sat May 24 07:44:45 2014 chambon emmanuel
*/

#include <glob.h>
#include "42.h"

int		my_tabcpy(char **tab_one, char **tab_two)
{
  int		i;

  i = 0;
  while (tab_two[i])
    {
      tab_one[i] = tab_two[i];
      i++;
    }
  tab_one[i] = NULL;
  return (0);
}

void		my_tabcat(char **tab_one, char **tab_two)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  while (tab_one[i])
    i++;
  while (tab_two[n])
    tab_one[i++] = tab_two[n++];
  tab_one[i] = NULL;
}

void		init_glob(int *s, int *x, int i)
{
  *s = 0;
  *x = i;
}

char		**replace_glob(char **av, int i)
{
  glob_t	gb;
  char		**new;
  char		*to_globe;
  int		s;
  int		x;

  init_glob(&s, &x, i);
  if ((to_globe = my_xmalloc(strlen(av[i]) + 1)) == NULL)
    return (av);
  my_strcpy(to_globe, av[i]);
  to_globe[strlen(av[i])] = '\0';
  if (glob(to_globe, GLOB_BRACE | GLOB_TILDE, NULL, &gb) == GLOB_NOMATCH)
    return (av);
  if ((new = my_xmalloc((tab_len(av, NULL) + gb.gl_pathc + 1)* sizeof(new))) == NULL)
    return (av);
  my_tabcpy(new, av);
  while (gb.gl_pathv[s])
    {
      if (!(new[i] = my_xmalloc((strlen(gb.gl_pathv[s]) + 1) * sizeof(new))))
	  return (av);
      my_strcpy(new[i++], gb.gl_pathv[s++]);
    }
  new[i] = NULL;
  my_tabcat(new, &av[x + 1]);
  return (new);
}

char		**globing(char **my_av)
{
  int		i;
  int		j;

  i = 0;
  while (my_av[i])
    {
      j = 0;
      while (my_av[i][j])
	{
	  if (my_av[i][j] == '*' || my_av[i][j] == '~' || my_av[i][j] == '?'
	      || my_av[i][j] == '{' || my_av[i][j] == '[' || my_av[i][j] == '(')
	      my_av = replace_glob(my_av, i);
	  j++;
	}
      i++;
    }
  /* int x = 0; */
  /* while (my_av[x]) */
  /*   printf("%d) <%s>\n", x, my_av[x++]); */
  return (my_av);
}
