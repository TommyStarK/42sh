/*
** source.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src/builtins/source
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun May 25 22:54:57 2014 chambon emmanuel
** Last update Sun May 25 23:10:12 2014 chambon emmanuel
*/

#include "42.h"

int		print_usage_source(t_sh *sh)
{
  fprintf(stderr, USAGE_SOURCE);
  sh->misc.last_return = 1;
  return (0);
}

int		source(t_sh *sh, char **opt)
{
  int		fd;
  char		*buff;

  if (!opt[0])
    return (print_usage_source(sh));
  if ((fd = open(opt[0], O_RDONLY)) == -1)
    {
      fprintf(stderr, NO_CONF_FILE);
      sh->misc.last_return = 1;
      return (0);
    }
  while ((buff = get_next_line(fd)))
    {
      if (buff[0] != '#')
	{
	  if (!(strncmp(buff, "prompt : ", 9)))
	    set_prompt(sh, my_str_to_wordtab(&buff[9], 1), 1);
	  else if (!(strncmp(buff, "alias ", 6)))
	    alias(sh, my_str_to_wordtab(&buff[6], ' '), 1, 0);
	}
      free(buff);
    }
  close(fd);
  return (0);
}
