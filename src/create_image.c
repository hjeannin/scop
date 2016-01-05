/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 15:39:01 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 19:06:18 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"
#include <stdlib.h>

int				create_image(t_data *d)
{
	glGenVertexArrays(1, &d->vao);
	glBindVertexArray(d->vao);
	glGenBuffers(2, &d->vbos[0]);
	glGenTextures(1, &d->texture_id);
	glBindTexture(GL_TEXTURE_2D, d->texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, d->b.width, d->b.height, 0,
					GL_BGR, GL_UNSIGNED_BYTE, d->bmp_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	d->vertices_size = sizeof(GLfloat) * d->vertices_num_elem;
	glBindBuffer(GL_ARRAY_BUFFER, d->vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, d->vertices_size, d->vertices_array,
					GL_STATIC_DRAW);
	glVertexAttribPointer(d->position_loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(d->position_loc);
	d->faces_size = sizeof(GLuint) * d->faces_num_elem;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, d->vbos[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, d->faces_size, d->faces_array,
					GL_STATIC_DRAW);
	free(d->vertices_array);
	free(d->faces_array);
	return (1);
}
