/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:20:17 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/18 14:25:02 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scop.h"
#include <stdio.h>
#include <stdlib.h>

int				print_error(char *msg, int code)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	return (code);
}

int				check_gl_error(char const *file, int line)
{
	GLenum		err;

	err = glGetError();
	if (err != GL_NO_ERROR)
	{
		if (err == GL_INVALID_ENUM)
			dprintf(2, "GL: Invalid enum in %s line %d\n", file, line);
		else if (err == GL_INVALID_VALUE)
			dprintf(2, "GL: Invalid value in %s line %d\n", file, line);
		else if (err == GL_INVALID_OPERATION)
			dprintf(2, "GL: Invalid operation in %s line %d\n", file, line);
		else if (err == GL_INVALID_FRAMEBUFFER_OPERATION)
			dprintf(2, "GL: Invalid framebuffer operation in %s line %d\n",
					file, line);
		else if (err == GL_OUT_OF_MEMORY)
			dprintf(2, "GL: Out of memory in %s line %d\n", file, line);
		exit(0);
		return (0);
	}
	return (1);
}
