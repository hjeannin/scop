/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_shader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:19:06 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 18:58:22 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"
#include <stdlib.h>

GLuint			compile_shader(GLuint current_shader)
{
	GLint		status;
	GLint		log_size;
	char		*comp_log;

	status = 0;
	log_size = 0;
	glCompileShader(current_shader);
	glGetShaderiv(current_shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		glGetShaderiv(current_shader, GL_INFO_LOG_LENGTH, &log_size);
		comp_log = ft_memalloc(log_size);
		glGetShaderInfoLog(current_shader, log_size, &log_size, comp_log);
		print_error("Could not compile shader :\n", 0);
		print_error(comp_log, 0);
		free(comp_log);
		return (0);
	}
	return (current_shader);
}
