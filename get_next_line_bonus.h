/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:46:08 by lkavalia          #+#    #+#             */
/*   Updated: 2022/04/02 20:46:57 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*---- Headers ----*/

# include <stdlib.h>
# include <unistd.h>

/*---- Function prototypes ----*/

char	*get_next_line(int fd);
char	*ft_strjoin_f(char *s1, const char *s2);
char	*ft_strdup_f(const char *string);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup_f2(char *s);
size_t	ft_strlen(const char *c);

#endif