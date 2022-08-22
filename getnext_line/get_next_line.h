/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 04:30:39 by hboukili          #+#    #+#             */
/*   Updated: 2021/11/29 05:10:03 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strchr(char *s);
int		ft_strlen(char *str);
char	*ft_check(char *a);
char	*ft_print(char *a);
char	*get_len(int fd, char *a);
#endif