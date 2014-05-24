/*
** exec.h for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 22 23:10:07 2014 chambon emmanuel
** Last update Sat May 24 23:13:31 2014 chambon emmanuel
*/

#ifndef __EXEC_H__
# define __EXEC_H__

/* sh_create_binary_tree */
char                    *patch_op_or_sep(char *, int, int);
char                    *patch_cmd(char *, int);
t_bin                   *new_branch(char *, int, char *);
t_bin                   *create_binary_tree(t_bin **, char *, int);
/* sh_create_binary_tree_handle.c */
void                    patch_sep(char *, int, char *);
void                    patch_op(char *, int, char *);
void                    free_binary_tree(t_bin *);
/* sh_resolve_binary_tree */
int                     do_exec(t_sh *, t_bin *, int);
int                     do_exec_local(t_sh *, t_bin *);
int                     dispatch_sep_or_op(t_sh *, t_bin *);
int                     resolve_binary_tree(t_sh *, t_bin **);
/* sh_operators.c */
int                     make_pipe(t_sh * , t_bin *);
int                     make_rredir(t_sh * , t_bin *);
int                     make_d_rredir(t_sh * , t_bin *);
int                     make_lredir(t_sh * , t_bin *);
int                     make_d_lredir(t_sh * , t_bin *);
/* sh_operators_handle.c */
char                    *handle_d_lredir(char *, int);
void			make_separators(t_sh *, t_bin *);
/* sh_get_path.c */
int                     check_if_env_variable_exist(char **, char *);
char                    *get_path(t_sh *, t_bin *, int);
char                    *patch_path_to_execve(t_bin *, int, char *);
/* sh_signals.c */
void                    signal_seg(int);
int			get_signal_end_cmd(int);
/* TOOLS */
char                    *gt_next_line(const int);
/* ALIAS */
char			*replace_alias(char *, t_sh *);
char			**globing(char **);

#endif /* !__EXEC_H__ */
