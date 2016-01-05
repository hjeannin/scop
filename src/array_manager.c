/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:23:36 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 18:56:15 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

GLfloat			*create_float_array(GLuint size)
{
	GLfloat		*new_array;

	if (!(new_array = (GLfloat *)malloc(sizeof(*new_array) * size)))
		return (NULL);
	ft_memset(new_array, 0, size);
	return (new_array);
}

void			print_float_array(GLfloat *a, GLuint size)
{
	GLuint		i;

	i = 0;
	while (i < size)
	{
		dprintf(2, "[%f],[%f],[%f]\n", a[i], a[i + 1], a[i + 2]);
		i += 3;
	}
}

GLuint			*create_uint_array(GLuint size)
{
	GLuint		*new_array;

	if (!(new_array = (GLuint *)malloc(sizeof(*new_array) * size)))
		return (NULL);
	ft_memset(new_array, 0, size);
	return (new_array);
}

void			print_uint_array(GLuint *a, GLuint size)
{
	GLuint		i;

	i = 0;
	while (i < size)
	{
		dprintf(2, "[%i],[%i],[%i]\n", a[i], a[i + 1], a[i + 2]);
		i += 3;
	}
}
