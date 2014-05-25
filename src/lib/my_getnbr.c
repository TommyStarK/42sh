/*
** my_getnbr.c for Corewar in /home/chambo_e/Dropbox/Corewar/build/asm/src/base
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Apr 13 19:11:45 2014 chambon emmanuel
** Last update Sun Apr 13 19:11:47 2014 chambon emmanuel
*/

int	my_getnbr(char *str)
{
  int	c;
  int	signe;
  int	nb;

  signe = 1;
  c = 0;
  while (str[c] != '\0' && (str[c] == '+' || str[c] == '-'))
    {
      if (str[c] == '-')
	signe = signe * -1;
      c = c + 1;
    }
  str = str + c;
  nb = 0;
  c = 0;
  while (str[c] >= '0' && str[c] <= '9')
    {
      nb = nb * 10;
      nb = nb - (str[c] - '0');
      c = c + 1;
    }
  return (nb * signe * -1);
}
