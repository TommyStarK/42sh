/*
** conf.c for 42sh in /home/sarda_j/Dropbox/42sh/groupe_milox/sarda_j/
**
** Made by sarda_j
** Login   <sarda_j@epitech.net>
**
** Started on  Mon May 19 21:59:53 2014 sarda_j
** Last update Sat May 24 07:33:56 2014 chambon emmanuel
*/

#include "42.h"

int		conf_read(t_sh *sh)
{
  int		fd;
  char		*buff;

  if ((fd = open(".42shrc", O_RDONLY)) == -1)
    {
      fprintf(stderr, NO_CONF_FILE);
      return (-1);
    }
  while ((buff = get_next_line(fd)))
    {
      if (buff[0] != '#')
	{
	  if (!(strncmp(buff, "prompt : ", 9)))
	    set_prompt(sh, my_str_to_wordtab(&buff[9], 1));
	  else if (!(strncmp(buff, "alias ", 6)))
	    alias(sh, my_str_to_wordtab(&buff[6], ' '));
	}
      free(buff);
    }
  close(fd);
  return (0);
}
