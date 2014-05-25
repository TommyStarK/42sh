/*
** read.h for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun May 25 05:23:49 2014 chambon emmanuel
** Last update Sun May 25 17:27:25 2014 Dorian Amouroux
*/

#ifndef __READ_H__
# define __READ_H__

# define CAPS(str)	(my_putstr(tgetstr(str, NULL)))
# define USELESS(var)	(var = var)
# define LEFT		(4479771)
# define RIGHT		(4414235)
# define UP		(4283163)
# define DOWN		(4348699)
# define ENTER		(10)
# define BACKSPACE	(127)
# define DELETE		(2117294875)
# define CTRL_A		(1)
# define CTRL_E		(5)
# define HOME		(4738843)
# define END		(4607771)
# define CTRL_K		(11)
# define CTRL_Y		(25)
# define CTRL_L		(12)
# define CTRL_D		(4)

char			*read_stdin(t_editor *);
char			*get_file_history(int);
int			handle_eot(t_editor *);
int			set_editor(t_editor *);
int			unset_editor(t_editor *);
int			command_history(t_editor *);
void			init_command(t_str *);
void			handle_winch(int);
/*
** action
*/
int			end_of_line(t_editor *);
int			insert_letter(t_str *, union u_buffer);
int			erase_left(t_editor *);
int			erase_right(t_editor *);
int			init_editor(t_editor *);
int			exit_editor(t_editor *);
int			cut_line(t_str *, char **);
int			paste_line(t_str *, char **);
int			clear_the_screen(t_editor *);
/*
** move
*/
int			move_left(t_editor *);
int			move_right(t_editor *);
int			move_start(t_editor *);
int			move_end(t_editor *);
/*
** history
*/
int			init_history(t_editor *);
int			add_command_history(t_hist **, char *);
t_hist                  *get_last(t_hist *);
int			history_up(t_editor *);
int			history_down(t_editor *);
int			show_history(t_hist *);
int			history_length(t_hist *);
void			remove_last(t_editor *);

extern struct winsize	size_term;

#endif /* !__READ_H__ */
