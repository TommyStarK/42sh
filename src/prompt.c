/*
** prompt.c for 42sh in /home/sarda_j/Dropbox/42sh/groupe_milox/sarda_j/
**
** Made by sarda_j
** Login   <sarda_j@epitech.net>
**
** Started on  Mon May 19 22:00:29 2014 sarda_j
** Last update Sun May 25 09:21:58 2014 chambon emmanuel
*/

#include "42.h"

void		case_color(t_sh *sh, int *color, int *i)
{
  char		*var;
  int		var_len;

  var_len = my_varlen(&(sh->prompt[*i]));
  if (!(var = my_strncpy_m(&(sh->prompt[*i + 1]), var_len - 1)))
    return ;
  if ((*color = get_color_code(var)) == -1)
    *color = 0;
  *i = *i + var_len;
  free(var);
}

int		case_var(t_sh *sh, int *color, int *i)
{
  char		*var;
  int		var_len;
  int		ret;

  var_len = my_varlen(&(sh->prompt[*i]));
  if (!(var = my_strncpy_m(&(sh->prompt[*i + 1]), var_len - 1)))
    return (-1);
  my_putstr_color(my_getenv(sh->env, var), *color);
  *i = *i + var_len;
  ret = (int)strlen(my_getenv(sh->env, var));
  free(var);
  return (ret);
}

int		print_prompt(t_sh *sh, int i)
{
  int		color;
  int		size;

  color = 0;
  size = 0;
  if (!sh->prompt)
    my_putstr("$> ");
  else
    {
      while (i < (int)strlen(sh->prompt))
	{
	  if (sh->prompt[i] == '\\')
	    size += my_putchar_color(sh->prompt[i + 1], color);
	  else if (sh->prompt[i] == '%')
	    case_color(sh, &color, &i);
	  else if (sh->prompt[i] == '$')
	    size += case_var(sh, &color, &i);
	  else
	    size += my_putchar_color(sh->prompt[i], color);
	  i++;
	}
    }
  my_putchar(' ');
  return (size + 1);
}
