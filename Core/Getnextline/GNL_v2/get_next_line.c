/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:42:31 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/02 01:13:35 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_move_string_to_start(char *string, int i)
{
	int	j;

	j = 0;
	while (string[i + j])
	{
		string[j] = string[i + j];
		j++;
	}
	string[j] = '\0';
}

char	*make_return(char *origin_string)
{
	int		i;
	int		j;
	char	*retstr;

	i = 0;
	j = 0;
	while (origin_string[i] != '\0' && origin_string[i] != '\n')
		i++;
	retstr = ft_calloc((i + 2), 1);
	while (origin_string[j] != '\n' && origin_string[j])
	{
		retstr[j] = origin_string[j];
		j++;
	}
	retstr[j] = origin_string[j];
	ft_move_string_to_start(origin_string, (j + 1));
	// if (origin_string)
	// {
	// 	free(origin_string);
	// 	origin_string = NULL;
	// }
	return (retstr);
}

char	*make_final_return(char *origin_string)
{
	int		i;
	char	*retstr;
	//char	*temp;

	i = 0;
	retstr = ft_calloc((ft_strlen(origin_string) + 1), 1);
	while (origin_string[i])
	{
		retstr[i] = origin_string[i];
		i++;
	}
	retstr[i] = '\0';
	ft_bzero(origin_string, ft_strlen(origin_string));
	//free(origin_string);
	//	temp = retstr;
	//free(temp);
	//origin_string = NULL;
	return (retstr);
}

int	check_calloc_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 0 && str)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*leftovers = NULL;
	char		*return_line;
	char		read_str[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*temp;		

	bytes_read = -1;
	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!leftovers)
		leftovers = ft_calloc(BUFFER_SIZE + 1, 1);
	while (!check_for_newline_in_string(leftovers) && bytes_read != 0)
	{	
		bytes_read = read(fd, read_str, BUFFER_SIZE);
		read_str[bytes_read + 1] = '\0';
		temp = leftovers;
		leftovers = ft_strjoin(leftovers, read_str);
		ft_clear((void *)temp);
	}

	
	if (!ft_strlen(leftovers) && bytes_read == 0)
	{
		ft_clear((void **)leftovers);
		return (NULL);
	}
	if ((check_for_newline_in_string(leftovers) == 0) || ((check_for_newline_in_string(leftovers) == -1) && BUFFER_SIZE != ft_strlen(leftovers) && ft_strlen(leftovers) != 0))
	{
		return_line = ft_calloc((ft_strlen(leftovers) + 1), 1);
		temp = return_line;
		return_line = make_final_return(leftovers);
		ft_clear((void **)temp);
		//free (leftovers);
		return ((char *)return_line);
	}
	else if (count_nl(leftovers) > 1 || check_for_newline_in_string(leftovers) != -1)
	{
		return_line = ft_calloc((ft_strlen(leftovers) + 1), 1);
		temp = return_line;
		return_line = make_return(leftovers);
		ft_clear((void **)temp);
		return ((char *)return_line);
	}
	return (NULL);
}

/*
problems: 
- something is most likely being modified after being freed. 
- initializing the leftovers in the way that I do might cause leaks, it might be better to init as array.

- add ft_clear function from V3
 */