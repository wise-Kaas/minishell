/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:25:50 by rgyles            #+#    #+#             */
/*   Updated: 2019/04/10 20:07:15 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <dirent.h>
# include <signal.h>

# define O_YELLOW "\033[01;33m"
# define O_NC "\033[0m"

# define SHELL "minishell: "
# define CD "cd: "

# define WN_SETENV "setenv: wrong number of arguments"
# define WN_UNSETENV "unsetenv: wrong number of arguments"

# define NUD_SH SHELL "no such user or named directory: "

# define NF_COMMAND SHELL "I've been looking, but couldn't find: "
# define NF_FOD CD "you kidding? no such file or directory: "

# define NF_HD_CD CD "what have you done to my home directory path?"
# define NF_OLDPWD_CD CD "old pwd 404"
# define NF_FOD_CD CD NF_FOD

# define ER_CD CD "error"
# define ER_EX SHELL "permission denied: "
# define ND_CD CD "it's not a directory, honey: "
# define TMA_CD CD "that's way too much than I can handle"

typedef struct	s_bin
{
	char			*dir;
	char			**bins;
	struct s_bin	*next;
}				t_bin;

char			**init_environment(char *str, char **environ);
char			**get_envi_array(char **envi, int flag);
void			free_envi_array(char **envi);
void			print_envi(char *str, char **envi);
char			*get_envi_field(char *field, char **envi);
int				update_envi_field(char *field, char *new_line, char ***envi);
char			*join_envi_line(char *field, char *value);

void			init_binaries(char *path, t_bin **bins);

char			**init_arguments(char *input, char **envi);
void			check_argument(char **argument, char **envi);
void			check_dollar_sign(char **argument, char **envi);

void			form_request(char *str, char ***envi, t_bin **bins);
void			command_queue(char *input, char ***envi, t_bin **bins);

void			set_envi(char **arguments, char ***envi, t_bin **bins);
void			unset_envi(char **arguments, char ***envi, t_bin **bins);
void			change_direct(char **arguments, char ***envi);
void			echo(char **arguments);

void			command(char **arguments, char **envi, t_bin *bins);
void			command_path(char **arguments, char **envi);

void			free_list(t_list **list);
void			free_bins(t_bin **bins);
void			free_char_array(char ***array);

#endif
