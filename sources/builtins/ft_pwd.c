/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:46:39 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 00:27:43 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_pwd(t_cmd *cmd, t_app *app)
{
	char	buffer[MAX_PATH_SIZE];

	if (cmd->has_options == TRUE)
	{
		ft_perror(app->name, cmd->basename, "", "no options allowed");
		return (1);
	}
	ft_getcwd(buffer);
	ft_write(STDOUT_FILENO, ft_env_get(&app->env, "PWD", buffer));
	ft_write(STDOUT_FILENO, "\n");
	return (0);
}
