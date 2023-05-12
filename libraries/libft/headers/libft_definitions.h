/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_definitions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:18:55 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 16:46:36 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DEFINITIONS_H
# define LIBFT_DEFINITIONS_H

# include "libft_constants.h"

typedef int			t_bool;
typedef int			t_fd;
typedef int			t_pid;
typedef int			t_rt;

typedef struct s_lst {
	void			*content;
	struct s_lst	*next;
}	t_lst;

#endif