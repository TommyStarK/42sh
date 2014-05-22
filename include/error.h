/*
** error.h for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:05:19 2014 chambon emmanuel
** Last update Thu May 22 16:09:19 2014 chambon emmanuel
*/

#ifndef __ERROR_H__
# define __ERROR_H__

# define MALLOC_ERROR			"Can't perform malloc\n"
# define NO_CONF_FILE			"No configuration file found. Default value will be used\n"
# define ARG_CD				"Too much argument for cd !\n"
# define MISSING_ENV			"%.*s not found in env\n"
# define ARG_SETENV			"Wrong argument for setenv !\n"
# define PB_ENV				"A problem happened with env, please retry\n"
# define ARG_UNSET			"Wrong argument for unsetenv !\n"
# define NT_FND_ENV			"Item not found in env\n"

#endif /* !__ERROR_H__ */
