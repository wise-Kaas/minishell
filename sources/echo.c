/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:46:56 by rgyles            #+#    #+#             */
/*   Updated: 2019/03/25 15:24:03 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **arguments)
{
	while (*arguments != NULL)
	{
		ft_putstr(*arguments);
		write(1, " ", 1);
		arguments++;
	}
	write(1, "\n", 1);
}