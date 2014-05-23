/*
** echo.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/chambo_e/echo
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May  8 21:18:56 2014 chambon emmanuel
** Last update Thu May 22 15:13:43 2014 chambon emmanuel
*/

#include "42.h"

int		return_int(char *error, int ret)
{
  if (error)
    fprintf(stderr, error);
  return (ret);
}

int		large_opt(char *str)
{
  if (!strcmp(str, "version"))
    printf("echo 0.1\nMade for 42sh - Epitech by chambo_e\n");
  else if (!strcmp(str, "help"))
    {
      printf("Usage: echo [OPTIONS] [STRING]\n");
      printf("Echo the STRING(s) to standard output\n");
      printf("   -n : \n\tdo not output the trailing newline\n");
      printf("   -e : \n\tenable interpretation of backslash escapes\n");
      printf("   -E : \n\tenable interpretation of backslash ");
      printf("escapes (default)\n   --help :\n\tdisplay this help and exit\n");
      printf("   --version :\n\tdisplay version of the command and exit\n");
    }
  else
    return (-1);
  return (0);
}

int		get_flag(char *flag, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '-')
	return (large_opt(&str[i + 1]));
      else if ((str[i] == 'n') && ((*flag == 2) || (*flag == 0)))
	*flag += 1;
      else if ((str[i] == 'e') && ((*flag & 2) <= 1))
	*flag += 2;
      else if ((str[i] == 'E') && (*flag >= 2))
	*flag -= 2;
      else if ((str[i] != 'n') && (str[i] != 'E') && (str[i] != 'e'))
	return (-1);
      i++;
    }
  return (1);
}

void		my_putstr_echo(char *str, int flag)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (flag >= 2 && (str[i] == '\\') && str[i + 1])
	{
	  if (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'f')
	    my_putchar(str[i + 1] - 90);
	  else if (str[i + 1] == 't')
	    my_putchar(9);
	  else if (str[i + 1] == 'n')
	    my_putchar(10);
	  else if (str[i + 1] == 'v')
	    my_putchar(11);
	  else if (str[i + 1] == 'r')
	    my_putchar(3);
	  else
	    my_putchar('\\');
	  i++;
	}
      else
	my_putchar(str[i]);
      i++;
    }
}

int		print_arg(char **opt, char flag)
{
  int		i;

  i = 0;
  while (opt[i])
    {
      my_putstr_echo(opt[i], flag);
      if (strcmp(&opt[i][strlen(opt[i]) - 2], "\\n"))
	my_putchar(' ');
      i++;
    }
  if (flag != 1 && flag != 3)
    my_putchar('\n');
  return (0);
}

int		echo(char **opt)
{
  char		flag;
  int		i;
  int		x;

  i = 0;
  flag = 0;
  if (!opt[0])
    return (return_int("\n", 0));
  while (opt[i])
    {
      if (opt[i][0] && opt[i][0] == '-')
	{
	  x = get_flag(&flag, &opt[i][1]);
	  if (x == 0)
	    return (0);
	  if (x == -1)
	    return (print_arg(&opt[i], flag));
	  i++;
	}
      else
	return (print_arg(&opt[i], flag));
    }
  return (0);
}
