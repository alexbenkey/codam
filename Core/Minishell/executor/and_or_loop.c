/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   and_or_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 14:17:03 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/02 17:44:36 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	what_cmd2(t_tokens *bigdata, t_super *super);

int	what_cmd(t_tokens *bigdata, t_super *super)
{
	what_cmd2(bigdata, super);
	bigdata = bigdata->next;
	while (bigdata)
	{
		if (!g_exit_code && bigdata->log_op == OPP_AND)
			what_cmd2(bigdata, super);
		if (g_exit_code && bigdata->log_op == OPP_OR)
			what_cmd2(bigdata, super);
		bigdata = bigdata->next;
	}
	return (1);
}
