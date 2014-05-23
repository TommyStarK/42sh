/*
** my_strncpy.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri May 23 21:07:09 2014 chambon emmanuel
** Last update Fri May 23 21:07:26 2014 chambon emmanuel
*/

char		*my_strncpy(char *dest, char *src, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      if (src[i] == '\0')
        dest[i] = '\0';
      else
        dest[i] = src[i];
      i++;
    }
  return (dest);
}
