/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_empty.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 16:00:37 by jbax          #+#    #+#                 */
/*   Updated: 2023/04/13 16:02:00 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	is_empty(char *line)
{
	while (*line && ft_iswhite_space(*line))
		line++;
	if (*line)
		return (1);
	return (0);
}
