/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_Swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 14:35:27 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/30 16:01:33 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct x_list{
		void 			*content;
		size_t			number;
		struct x_list 	*next;
}				ft_list;

#endif