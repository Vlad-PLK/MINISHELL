/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:54:48 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:47:50 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_close(t_exe *exec, t_cmd *cmd)
{
	close(exec->in_fd);
	if (cmd->rio.has_pipe_o == TRUE && cmd->sub.is_ended == FALSE)
	{
		exec->in_fd = ft_dup(exec->pipe_tab[0]);
		close(exec->pipe_tab[0]);
		close(exec->pipe_tab[1]);
	}
	else
	{
		if (cmd->rio.has_file_o == TRUE)
			close(exec->file_out);
	}
}
