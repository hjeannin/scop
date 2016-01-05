/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:52:52 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 19:15:07 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "scop.h"
#include "libft.h"

static GLchar		*copy_file(char const *file_name, int nc)
{
	int				fd;
	char			buf[nc + 1];
	GLchar			*fc;

	if (!(fd = open(file_name, O_RDONLY)))
		return (NULL);
	read(fd, buf, nc);
	buf[nc] = '\0';
	close(fd);
	fc = ft_memalloc(sizeof(char) * nc + 1);
	ft_strcpy(fc, buf);
	fc[nc] = '\0';
	return (fc);
}

static int			get_null_char(char const *file_name)
{
	int				fd;
	char			buf[1];
	int				nc;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	nc = 0;
	while (read(fd, buf, 1))
		nc++;
	close(fd);
	return (nc);
}

GLuint				load_shader(GLenum type, char const *file_name)
{
	GLuint			current_shader;
	int				file_size;
	GLchar			*source;

	file_size = 0;
	if ((current_shader = glCreateShader(type)) == 0)
		return (print_error("glCreateShader failed\n", 0));
	file_size = get_null_char(file_name);
	source = copy_file(file_name, file_size);
	glShaderSource(current_shader, 1, (const GLchar **)&source, 0);
	return (current_shader);
}
