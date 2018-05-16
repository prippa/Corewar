/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:04:10 by vveselov          #+#    #+#             */
/*   Updated: 2018/01/17 13:24:55 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*str_join(char **s1, char *s2)
{
	int			i;
	int			j;
	char		*res;

	i = 0;
	j = 0;
	while ((*s1)[i])
		i++;
	while (s2[j])
		j++;
	res = (char *)malloc(sizeof(char) * (i + j + 1));
	j = -1;
	while ((*s1)[++j])
		res[j] = (*s1)[j];
	i = -1;
	while (s2[++i])
		res[j++] = s2[i];
	res[j] = '\0';
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (res);
}

static	char	*ft_line(char **s, int len, int i, int j)
{
	char		*res;
	char		*new_s;

	new_s = (char *)malloc(sizeof(char));
	new_s[0] = '\0';
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while ((*s)[++i] && (*s)[i] != '\n')
		res[i] = (*s)[i];
	res[i] = '\0';
	if ((*s)[++i])
	{
		j = i - 1;
		while ((*s)[i])
			i++;
		free(new_s);
		new_s = (char *)malloc(sizeof(char) * (i + 1));
		i = 0;
		while ((*s)[++j])
			new_s[i++] = (*s)[j];
		new_s[i] = '\0';
	}
	free(*s);
	*s = new_s;
	return (res);
}

static	void	fd_lst(t_fd **head, t_fd **lst, int fd)
{
	if (!(*head))
	{
		*head = (t_fd *)malloc(sizeof(t_fd));
		(*head)->fd = fd;
		(*head)->rd = 1;
		(*head)->next = NULL;
		(*head)->str = (char *)malloc(sizeof(char));
		(*head)->str[0] = '\0';
	}
	*lst = *head;
	while ((*lst)->next && (*lst)->fd != fd)
	{
		*lst = (*lst)->next;
	}
	if ((*lst)->fd != fd)
	{
		(*lst)->next = (t_fd *)malloc(sizeof(t_fd));
		*lst = (*lst)->next;
		(*lst)->fd = fd;
		(*lst)->rd = 1;
		(*lst)->next = NULL;
		(*lst)->str = (char *)malloc(sizeof(char));
		(*lst)->str[0] = '\0';
	}
}

static	int		fd_read(int i, char *buff, t_fd **lst, char **line)
{
	int rd;

	rd = read((*lst)->fd, buff, BUFF_SIZE);
	if (rd > 0)
	{
		buff[rd] = '\0';
		(*lst)->str = str_join(&(*lst)->str, buff);
	}
	else if (rd == -1)
		return (-1);
	if (rd == 0 && (*lst)->str[i] == '\0')
	{
		(*lst)->rd = 0;
		*line = (*lst)->str;
		if (i == 0)
			return (0);
		return (1);
	}
	return (2);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*head;
	t_fd			*lst;
	char			buff[BUFF_SIZE + 1];
	int				i;

	fd_lst(&head, &lst, fd);
	while (lst->rd != 0)
	{
		i = -1;
		while (lst->str[++i])
			if (lst->str[i] == '\n')
			{
				*line = ft_line(&lst->str, i, i, i);
				return (1);
			}
		if ((i = fd_read(i, buff, &lst, line)) != 2)
			return (i);
	}
	*line = 0;
	return (0);
}
