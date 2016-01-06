/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:03:58 by hjeannin          #+#    #+#             */
/*   Updated: 2016/01/06 16:55:52 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "stddef.h"

static void		init_float_tab(GLfloat *t, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		t[i] = 0.0f;
		i++;
	}
}

void			init_int_tab(int *t, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		t[i] = 0;
		i++;
	}
}

static int		init_data_part2(t_data *d)
{
	d->vao = 0;
	d->vbos[0] = 0;
	d->vbos[1] = 0;
	d->vertex_shader = 0;
	d->fragment_shader = 0;
	d->geometry_shader = 0;
	d->program = 0;
	d->position_loc = 0;
	d->proj_loc = 0;
	d->view_loc = 0;
	d->trans_loc = 0;
	d->rot_y_loc = 0;
	d->scale_loc = 0;
	d->color_loc = 0;
	d->vertices_size = 0;
	d->vertices_num_elem = 0;
	d->vertices_array = NULL;
	d->v_count = 0;
	d->faces_size = 0;
	d->faces_num_elem = 0;
	d->faces_array = NULL;
	d->f_count = 0;
	return (1);
}

int				init_data(t_data *d)
{
	d->init = NULL;
	d->win = NULL;
	d->obj_file = NULL;
	d->texture_file = NULL;
	d->parsing_mode = NO_SLASH;
	d->color = 0.0f;
	d->texture_id = 0;
	d->bmp_data = NULL;
	d->translate[0] = 0.0f;
	d->translate[1] = 0.0f;
	d->translate[2] = -5.0f;
	d->rot_y = 0.0f;
	d->scale = 1.0f;
	d->auto_rot_y = 0.0f;
	d->texture_toggle_status = 0;
	d->texture_toggle = 0.0f;
	d->texture_toggle_loc = 0;
	init_float_tab(d->proj_matrix, 16);
	init_float_tab(d->view_matrix, 16);
	init_float_tab(d->trans_matrix, 16);
	init_float_tab(d->rot_y_matrix, 16);
	init_float_tab(d->scale_matrix, 16);
	init_data_part2(d);
	return (1);
}
