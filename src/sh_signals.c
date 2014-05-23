/*
** sh_signals.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May 17 02:47:33 2014 thomas milox
** Last update Fri May 23 06:52:04 2014 chambon emmanuel
*/

#include "42.h"

void		signal_seg(int status)
{
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	printf("Segmentation fault\n");
    }
}
