/*
** my_malloc.c for croewar in /home/amouro_d/Dropbox/B2/korewar/COREWAR_TRAN/lib
**
** Made by Dorian Amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Sun Apr 13 13:07:48 2014 Dorian Amouroux
** Last update Sun May 25 06:21:22 2014 chambon emmanuel
*/

#include "42.h"

t_malloc	*g_malloc_list = NULL;

void		free_all(void)
{
  t_malloc	*tmp;
  t_malloc	*save;

  tmp = g_malloc_list;
  save = g_malloc_list;
  while (tmp != NULL)
    {
      free(tmp->ptr);
      save = tmp;
      tmp = tmp->next;
      free(save);
    }
  g_malloc_list = NULL;
}

void		my_free(void *ptr)
{
  t_malloc	*tmp;
  t_malloc	*save;

  if (ptr == g_malloc_list->ptr)
    {
      tmp = g_malloc_list;
      g_malloc_list = g_malloc_list->next;
      free(tmp->ptr);
      free(tmp);
      return ;
    }
  save = g_malloc_list;
  tmp = g_malloc_list->next;
  while (tmp != NULL)
    {
      if (tmp->ptr == ptr)
	{
	  save->next = tmp->next;
	  free(tmp->ptr);
	  free(tmp);
	  return ;
	}
      save = tmp;
      tmp = tmp->next;
    }
}

int		add_in_malloc_list(void *ptr)
{
  t_malloc	*elem;

  elem = malloc(sizeof(t_malloc));
  if (elem == NULL)
    return (-1);
  elem->next = g_malloc_list;
  elem->ptr = ptr;
  g_malloc_list = elem;
  return (0);
}

void	*my_malloc(int size)
{
  void	*ptr;
  char	*memset;
  int	i;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      fprintf(stderr, ERR_MALLOC);
      return (NULL);
    }
  i = 0;
  memset = (char *)ptr;
  while (i < size)
    {
      memset[i] = 0;
      i++;
    }
  if (add_in_malloc_list(ptr) == -1)
    {
      fprintf(stderr, ERR_MALLOC);
      return (NULL);
    }
  return (ptr);
}
