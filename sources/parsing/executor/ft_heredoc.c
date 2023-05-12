/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:59:19 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:47:26 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc(t_cmd *cmd, t_exe *exec)
{
	if (cmd->has_heredoc == TRUE
		|| cmd->has_herestr == TRUE)
	{
		ft_write(exec->pipe_doc[1], cmd->heredoc);
		ft_close(exec->pipe_doc[0]);
		ft_close(exec->pipe_doc[1]);
	}
}
