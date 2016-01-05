/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:33:29 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/18 14:15:35 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "mlx_opengl.h"

int				draw_img(t_data *d)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (d->auto_rot_y != 0.0)
		auto_rotate(d);
	if (d->texture_toggle <= 1.0f && d->texture_toggle_status == 1)
		d->texture_toggle += 0.01;
	else if (d->texture_toggle >= 0.0f && d->texture_toggle_status == 0)
		d->texture_toggle -= 0.01;
	glUseProgram(d->program);
	glUniformMatrix4fv(d->proj_loc, 1, GL_FALSE, d->proj_matrix);
	glUniformMatrix4fv(d->view_loc, 1, GL_FALSE, d->view_matrix);
	glUniformMatrix4fv(d->trans_loc, 1, GL_FALSE, d->trans_matrix);
	glUniformMatrix4fv(d->rot_y_loc, 1, GL_FALSE, d->rot_y_matrix);
	glUniformMatrix4fv(d->scale_loc, 1, GL_FALSE, d->scale_matrix);
	glUniform1f(d->texture_toggle_loc, d->texture_toggle);
	glUniform1f(d->color_loc, d->color);
	glDrawElements(GL_TRIANGLES, d->faces_size, GL_UNSIGNED_INT, 0);
	mlx_opengl_swap_buffers(d->win);
	if (!(check_gl_error(__FILE__, __LINE__)))
		return (0);
	return (1);
}
