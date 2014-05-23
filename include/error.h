/*
** error.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:05:19 2014 chambon emmanuel
<<<<<<< HEAD
** Last update Sat May 24 00:45:15 2014 chambon emmanuel
=======
** Last update Sat May 24 01:09:13 2014 thomas milox
>>>>>>> 80cf21b1186bcd882cc114b166cd7e8361cbd828
*/

#ifndef __ERROR_H__
# define __ERROR_H__

# define NO_CONF_FILE			"No configuration file found. Default value will be used\n"
# define ARG_CD				"Too much argument for cd !\n"
# define MISSING_ENV			"%.*s not found in env\n"
# define ARG_SETENV			"Wrong argument for setenv !\n"
# define PB_ENV				"A problem happened with env, please retry\n"
# define ARG_UNSET			"Wrong argument for unsetenv !\n"
# define NT_FND_ENV			"Item not found in env\n"
# define ERR_ENV			"Error: 'ENV' is NULL.\n"
# define ERR_FORK			"Error: with 'fork' syscall function.\n"
# define ERR_MALLOC			"Error: something wrong occured with 'malloc syscall'.\n"
<<<<<<< HEAD
# define ERR_CMD			"Shell: error-> [%s] command not found.\n"
# define SEG_HANDLER			"Segmentation Fault !\n"
# define ACCESS_DENIED			"access : [%s]\n"
=======
# define ERR_CMD			"Shell: error: [%s] command not found.\n"
# define ERR_STR_TO_TAB			"Error: something went wrong with 'str_word_tab' call.\n"
# define SEG_HANDLER			"Segmentation Fault .\n"
# define ACCESS_DENIED			"access : error [%s]\n"
>>>>>>> 80cf21b1186bcd882cc114b166cd7e8361cbd828

#endif /* !__ERROR_H__ */
