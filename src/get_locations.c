/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_locations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:15:20 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 14:23:51 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		get_locations(t_data *d)
{
	d->position_loc = glGetAttribLocation(d->program, "position");
	d->proj_loc = glGetUniformLocation(d->program, "proj_matrix");
	d->view_loc = glGetUniformLocation(d->program, "view_matrix");
	d->trans_loc = glGetUniformLocation(d->program, "trans_matrix");
	d->rot_y_loc = glGetUniformLocation(d->program, "rot_y_matrix");
	d->scale_loc = glGetUniformLocation(d->program, "scale_matrix");
	d->texture_toggle_loc = glGetUniformLocation(d->program, "tex_tog");
	d->color_loc = glGetUniformLocation(d->program, "color");
}
