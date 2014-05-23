/*
** epur_str.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri May 23 21:07:41 2014 chambon emmanuel
** Last update Fri May 23 21:07:57 2014 chambon emmanuel
*/

char		*epur_str(char *s)
{
  int		i;
  int		j;

  i = -1;
  j = 0;
  if (!s)
    return (0);
  while (s[++i] != '\0')
    {
      if (s[i] != ' ' && s[i] != '\t')
	{
	  s[j] = s[i];
	  j++;
	  if (s[i + 1] == ' ' || s[i + 1] == '\t')
	    {
	      s[j] = ' ';
	      j++;
	    }
	}
    }
  s[j] = '\0';
  if (s[j - 1] == ' ')
    s[j - 1] = '\0';
  return (s);
}
