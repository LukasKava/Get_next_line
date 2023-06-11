/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:24:56 by lkavalia          #+#    #+#             */
/*   Updated: 2022/04/04 19:32:40 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*---- Freeing -----------------------------------------------------------*/

char	*f_error(char *variable)
{
	free(variable);
	return (NULL);
}

/*---- Goes through the static hold till the \n character and ------------*/
/*---- saves everything to the char pointer ------------------------------*/
/*---- !!!! needs freeing !!!! -------------------------------------------*/
/*---- before = (char *)malloc(sizeof(char) * (len + 2)); ----------------*/
/*---- plus 2 because we need to malloc plus two places for \n and \0 ----*/
/*---- ex.  5 = 01234 ----------------------------------------------------*/

static	char	*save_till_n_f(char *s_hold)
{
	int		i;
	int		len;
	char	*before;

	i = 0;
	len = 0;
	if (!s_hold)
		return (NULL);
	while (s_hold[len] != '\n' && s_hold[len] != '\0')
		len++;
	before = (char *)malloc(sizeof(char) * (len + 2));
	if (!before)
		return (NULL);
	while (s_hold[i] != '\0' && s_hold[i] != '\n')
	{
		before[i] = s_hold[i];
		i++;
	}
	if (s_hold[i] == '\n')
	{
		before[i] = '\n';
		i++;
	}
	before[i] = '\0';
	return (before);
}

/*---- Goes through the static hold and saves everything after \n -------*/
/*---- saves everything to the char pointer -----------------------------*/
/*---- !!!! needs freeing !!!! ------------------------------------------*/

static char	*save_after_n_f(char *s_hold)
{
	char	*after;

	after = ft_strchr(s_hold, '\n');
	if (!after)
		return (f_error(s_hold));
	if (after[1])
		after = ft_strdup_f(&after[1]);
	else
		after = NULL;
	free(s_hold);
	return (after);
}

char	*get_next_line(int fd)
{
	static char		*hold;
	char			*final;
	char			*temp;
	int				size;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = read(fd, temp, BUFFER_SIZE);
	if (size == -1 || fd < 0)
		return (f_error(temp));
	while (size > 0)
	{
		temp[size] = '\0';
		if (!hold)
			hold = ft_strdup_f(temp);
		else
			hold = ft_strjoin_f(hold, temp);
		if (ft_strchr(temp, '\n'))
			break ;
		size = read(fd, temp, BUFFER_SIZE);
	}
	final = save_till_n_f(hold);
	hold = save_after_n_f(hold);
	free(temp);
	return (final);
}
