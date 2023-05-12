/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/20 17:02:31 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_del() :
*
*/
void	ft_prs_reading_del(t_lne *lne, t_bool cut)
{
	if (cut == TRUE)
	{
		lne->seg.rdr.read_delimiter = FALSE;
		lne->seg.rdr.read_redirection_i = FALSE;
		ft_chrcat(lne->seg.rdr.arg.content, '\25', MAX_LINE_SIZE);
	}
	ft_strlcat(lne->seg.cmd.rio.pathname_i, lne->seg.rdr.arg.content,
		MAX_PATH_SIZE);
}