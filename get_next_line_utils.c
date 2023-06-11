/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:24:59 by lkavalia          #+#    #+#             */
/*   Updated: 2022/04/02 20:14:24 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*---- returns the lenght of the char array ----*/

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

/*---- Checks for the specified char(int c) ---------------*/
/*---- It returns everything after the \n + \n it self ----*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

/*---- This function joins two strings ----*/

char	*ft_strjoin_f(char *s1, char const *s2)
{
	char	*full_s;
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (0);
	full_s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!full_s)
		return (NULL);
	while (s1[i] != '\0')
	{
		full_s[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		full_s[i] = s2[a];
		a++;
		i++;
	}
	full_s[i] = '\0';
	free(s1);
	return (full_s);
}

/*---- Duplicates the string  ----*/

char	*ft_strdup_f(const char *string)
{
	int		i;
	int		len;
	char	*a;

	i = ft_strlen(string) + 1;
	len = 0;
	a = (char *)malloc(i * sizeof(char));
	if (!a)
		return (NULL);
	while (i > 0)
	{
		a[len] = string[len];
		len++;
		i--;
	}
	return (a);
}
