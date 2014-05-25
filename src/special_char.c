/*
** insert.c for 42sh in /home/amouro_d/Dropbox/B2/42sh/groupe_milox/amouro_d/src
**
** Made by Dorian Amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Fri May  9 14:37:35 2014 Dorian Amouroux
** Last update Sun May 25 06:23:20 2014 chambon emmanuel
*/

#include "42.h"

int	insert_letter(t_str *command, union u_buffer buff)
{
  char	*temp;
  int	i;

  i = 0;
  while (i < 4 && (buff.tab_value[i] >= 32 && buff.tab_value[i] <= 126))
    {
      if (command->len >= 1023)
	return (0);
      if ((temp = my_strdup(&command->str[command->pos])) == NULL)
	return (2);
      my_strcpy(&command->str[command->pos + 1], temp);
      my_free(temp);
      command->str[command->pos] = buff.tab_value[i];
      command->pos++;
      command->len++;
      my_putchar(buff.tab_value[i]);
      CAPS("sc");
      my_putstr(&command->str[command->pos]);
      CAPS("rc");
      i++;
    }
  return (0);
}

int	erase_right(t_editor *editor)
{
  char	*temp;

  if (editor->command.pos == editor->command.len)
    return (0);
  if ((temp = my_strdup(&editor->command.str[editor->command.pos + 1])) == NULL)
    return (2);
  editor->command.len--;
  my_strcpy(&editor->command.str[editor->command.pos], temp);
  CAPS("sc");
  printf("%s ", temp);
  fflush(stdout);
  my_free(temp);
  CAPS("rc");
  return (0);
}

int	erase_left(t_editor *editor)
{
  char	*temp;

  if (editor->command.pos < 1 || editor->command.len == 0)
    return (0);
  if ((temp = my_strdup(&editor->command.str[editor->command.pos])) == NULL)
    return (2);
  my_strcpy(&editor->command.str[editor->command.pos - 1], temp);
  move_left(editor);
  CAPS("sc");
  printf("%s ", temp);
  fflush(stdout);
  CAPS("rc");
  my_free(temp);
  editor->command.len--;
  return (0);
}

int	end_of_line(t_editor *editor)
{
  if (editor->command.str[0] == 0)
    {
      my_putchar('\n');
      editor->len_prompt = print_prompt(&editor->sh);
      return (0);
    }
  my_putchar('\n');
  return (-1);
}
