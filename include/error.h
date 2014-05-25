/*
** error.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:05:19 2014 chambon emmanuel
** Last update Sun May 25 23:28:53 2014 chambon emmanuel
*/

#ifndef __ERROR_H__
# define __ERROR_H__

# define NO_CONF_FILE	"No configuration file found. Default value will be used\n"
# define ARG_CD		"Too much argument for cd !\n"
# define MISSING_ENV	"%.*s not found in env\n"
# define ARG_SETENV	"Wrong argument for setenv !\n"
# define PB_ENV		"A problem happened with env, please retry\n"
# define ARG_UNSET	"Wrong argument for unsetenv !\n"
# define NT_FND_ENV	"Item not found in env\n"
# define ERR_ENV	"Error: 'ENV' is NULL.\n"
# define ERR_FORK	"Error: with 'fork' syscall function.\n"
# define ERR_MALLOC	"Something wrong occured with 'malloc syscall'.\n"
# define ERR_CMD	"Shell: error: [%s] command not found.\n"
# define SEG_HANDLER	"Segmentation Fault !\n"
# define ACCESS_DENIED	"access : [%s]\n"
# define WRONG_COLOR	"%s: color not found. Applying white instead.\n"
# define INVALID_ALIAS	"Alias : invalid syntax.\n"
# define INVALID_VALUE	"\"%s\" is not valid in this context\n"
# define NO_ENV		"42sh: event not found: %d\n"
# define ERROR_HISTORY	"Error with [.history] file\n"
# define NO_TERMCAPS	"Your terminal doesn't handle all termcaps\n"
# define USAGE_SOURCE	"Usage : source path/to/conf/file\n"
# define URANDOM	"Cannot handle urandom\n"

#endif /* !__ERROR_H__ */
