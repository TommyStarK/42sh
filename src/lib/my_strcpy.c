/*
** my_strcpy.c for my_strcpy in /home/sarda_j/rendu/Piscine-C-Jour_06/ex_01
**
** Made by jean sarda
** Login   <sarda_j@epitech.net>
**
** Started on  Mon Oct  7 09:32:43 2013 jean sarda
** Last update Sat Nov 23 23:27:26 2013 sarda_j
*/

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
      dest[i] = src[i++];
  dest[i] = '\0';
}
