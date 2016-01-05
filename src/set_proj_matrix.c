/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_proj_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:17:36 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 19:55:42 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "scop.h"

void			set_proj_matrix(GLfloat *proj_matrix, GLfloat fov,
								GLfloat near_cp, GLfloat far_cp)
{
	GLfloat		scale;
	GLfloat		ratio;

	scale = 1.0f / tan(fov * 0.5 * M_PI / 180);
	ratio = (1.0f * RES_X) / (1.0f * RES_Y);
	identity_mat4(proj_matrix);
	proj_matrix[0] = scale / ratio;
	proj_matrix[5] = scale;
	proj_matrix[10] = (far_cp + near_cp) / (near_cp - far_cp);
	proj_matrix[11] = -1.0f;
	proj_matrix[14] = (2.0f * far_cp * near_cp) / (near_cp - far_cp);
	proj_matrix[15] = 0.0f;
}
