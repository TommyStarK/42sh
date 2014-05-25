/*
** read_file.c for 42sh in /home/tequilol/Dropbox/B2/42sh/groupe_milox/amouro_d/src
**
** Made by Dorian Amouroux
** Login   <tequilol@epitech.net>
**
** Started on  Sat May 24 08:56:25 2014 Dorian Amouroux
** Last update Sun May 25 20:32:31 2014 chambon emmanuel
*/

#include "42.h"

char	*concat_buffer(char *s1, char *s2, int size)
{
  char	*new_str;

  if (s1 == NULL)
    return (my_strdup(s2));
  if (!(new_str = my_malloc(size + 1)))
    return (NULL);
  my_strcpy(new_str, s1);
  my_strcat(new_str, s2);
  my_free(s1);
  return (new_str);
}

char	*get_file_history(int fd)
{
  int	size;
  int	ret;
  char	buffer[4096 + 1];
  char	*file;

  size = 0;
  file = NULL;
  while ((ret = read(fd, buffer, 4096)) > 0)
    {
      buffer[ret] = 0;
      size += ret;
      if (!(file = concat_buffer(file, buffer, size)))
	{
	  close(fd);
	  return (NULL);
	}
    }
  if (file == NULL && ret == -1)
    fprintf(stderr, ERROR_HISTORY);
  close(fd);
  return (file);
}
