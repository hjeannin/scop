/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:16:42 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 18:55:02 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scop.h"

void			identity_mat4(GLfloat *out)
{
	out[0] = 1.0;
	out[1] = 0.0;
	out[2] = 0.0;
	out[3] = 0.0;
	out[4] = 0.0;
	out[5] = 1.0;
	out[6] = 0.0;
	out[7] = 0.0;
	out[8] = 0.0;
	out[9] = 0.0;
	out[10] = 1.0;
	out[11] = 0.0;
	out[12] = 0.0;
	out[13] = 0.0;
	out[14] = 0.0;
	out[15] = 1.0;
}

void			translation_mat4(GLfloat *t, GLfloat *out)
{
	identity_mat4(out);
	out[12] = t[0];
	out[13] = t[1];
	out[14] = t[2];
}

void			rotation_y_mat4(GLfloat angle, GLfloat *out)
{
	identity_mat4(out);
	out[0] = cos(angle);
	out[2] = -sin(angle);
	out[8] = sin(angle);
	out[10] = cos(angle);
}

void			scale_mat4(GLfloat scale, GLfloat *out)
{
	identity_mat4(out);
	out[0] = scale;
	out[5] = scale;
	out[10] = scale;
}

void			multiply_mat4(GLfloat *a, GLfloat *b, GLfloat *out)
{
	out[0] = a[0] * b[0] + a[1] * b[4] + a[2] * b[8] + a[3] * b[12];
	out[1] = a[0] * b[1] + a[1] * b[5] + a[2] * b[9] + a[3] * b[13];
	out[2] = a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + a[3] * b[14];
	out[3] = a[0] * b[3] + a[1] * b[7] + a[2] * b[11] + a[3] * b[15];
	out[4] = a[4] * b[0] + a[5] * b[4] + a[6] * b[8] + a[7] * b[12];
	out[5] = a[4] * b[1] + a[5] * b[5] + a[6] * b[9] + a[7] * b[13];
	out[6] = a[4] * b[2] + a[5] * b[6] + a[6] * b[10] + a[7] * b[14];
	out[7] = a[4] * b[3] + a[5] * b[7] + a[6] * b[11] + a[7] * b[15];
	out[8] = a[8] * b[0] + a[9] * b[4] + a[10] * b[8] + a[11] * b[12];
	out[9] = a[8] * b[1] + a[9] * b[5] + a[10] * b[9] + a[11] * b[13];
	out[10] = a[8] * b[2] + a[9] * b[6] + a[10] * b[10] + a[11] * b[14];
	out[11] = a[8] * b[3] + a[9] * b[7] + a[10] * b[11] + a[11] * b[15];
	out[12] = a[12] * b[0] + a[13] * b[4] + a[14] * b[8] + a[15] * b[12];
	out[13] = a[12] * b[1] + a[13] * b[5] + a[14] * b[9] + a[15] * b[13];
	out[14] = a[12] * b[2] + a[13] * b[6] + a[14] * b[10] + a[15] * b[14];
	out[15] = a[12] * b[3] + a[13] * b[7] + a[14] * b[11] + a[15] * b[15];
}
