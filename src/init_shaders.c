/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:51:14 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 19:13:26 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"
#include <stdlib.h>

static int		load_shaders(t_data *d)
{
	if (!(d->vertex_shader = load_shader(GL_VERTEX_SHADER,
								"./shaders/vertex_shader.gls")))
		return (print_error("Vertex shader failed to load.\n", 0));
	if (!(d->geometry_shader = load_shader(GL_GEOMETRY_SHADER,
								"./shaders/geometry_shader.gls")))
		return (print_error("Geometry shader failed to load.\n", 0));
	if (!(d->fragment_shader = load_shader(GL_FRAGMENT_SHADER,
								"./shaders/fragment_shader.gls")))
		return (print_error("Fragment shader failed to load.\n", 0));
	return (1);
}

static int		compile_shaders(t_data *d)
{
	if (!(d->vertex_shader = compile_shader(d->vertex_shader)))
		return (print_error("Vertex shader failed to compile\n", 0));
	if (!(d->geometry_shader = compile_shader(d->geometry_shader)))
		return (print_error("Geometry shader failed to compile\n", 0));
	if (!(d->fragment_shader = compile_shader(d->fragment_shader)))
		return (print_error("Fragment shader failed to compile\n", 0));
	return (1);
}

static void		delete_after_error(t_data *d)
{
	glDeleteProgram(d->program);
	glDeleteShader(d->vertex_shader);
	glDeleteShader(d->geometry_shader);
	glDeleteShader(d->fragment_shader);
}

static int		link_program(t_data *d)
{
	GLint		is_linked;
	GLint		log_size;
	char		*link_log;

	is_linked = 0;
	glAttachShader(d->program, d->vertex_shader);
	glAttachShader(d->program, d->geometry_shader);
	glAttachShader(d->program, d->fragment_shader);
	glLinkProgram(d->program);
	glGetProgramiv(d->program, GL_LINK_STATUS, (int *)&is_linked);
	if (is_linked == GL_FALSE)
	{
		glGetProgramiv(d->program, GL_INFO_LOG_LENGTH, &log_size);
		link_log = ft_memalloc(log_size);
		glGetProgramInfoLog(d->program, log_size, &log_size, link_log);
		print_error("Could not link program\n", 0);
		print_error(link_log, 0);
		delete_after_error(d);
		free(link_log);
		return (0);
	}
	glDetachShader(d->program, d->vertex_shader);
	glDetachShader(d->program, d->geometry_shader);
	glDetachShader(d->program, d->fragment_shader);
	return (1);
}

int				init_shaders(t_data *d)
{
	if (!(load_shaders(d)))
		return (0);
	if (!(compile_shaders(d)))
		return (0);
	if (!(d->program = glCreateProgram()))
		return (print_error("glCreateProgram failed\n", 0));
	if (!link_program(d))
		return (print_error("link program failed\n", 0));
	return (1);
}
