/*
** my_puterr.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun May 25 06:24:36 2014 chambon emmanuel
** Last update Sun May 25 17:43:24 2014 Dorian Amouroux
*/

#include "42.h"

int	my_perror(char *function, int value)
{
  perror(function);
  return (value);
}
