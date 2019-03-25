/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:23:27 by rgyles            #+#    #+#             */
/*   Updated: 2019/03/25 18:47:40 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command(char **commands, char **my_env)
{
	pid_t	childPID;

	childPID = fork();
	if (childPID >= 0)
	{
		if (childPID == 0)
			execve("/bin/pwd", commands, my_env);
		else
			wait(NULL);
	}
	else
		ft_putendl("fork failed");
}
