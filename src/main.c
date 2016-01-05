/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 13:55:52 by hjeannin          #+#    #+#             */
/*   Updated: 2016/01/05 19:52:34 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "scop.h"
#include "mlx.h"
#include "mlx_opengl.h"
#include "libft.h"

static int		translation_key_events(int key, t_data *d)
{
	if (key == K_LEFT)
		translate(-0.2, &d->translate[0], d);
	if (key == K_RIGHT)
		translate(0.2, &d->translate[0], d);
	if (key == K_UP)
		translate(0.2, &d->translate[1], d);
	if (key == K_DOWN)
		translate(-0.2, &d->translate[1], d);
	if (key == K_PAGE_UP)
		translate(-0.2, &d->translate[2], d);
	if (key == K_PAGE_DOWN)
		translate(0.2, &d->translate[2], d);
	return (1);
}

static int		key_events(int key, t_data *d)
{
	if (key == K_ESC)
		exit(0);
	translation_key_events(key, d);
	if (key == K_A)
		rotate(-0.2, d);
	if (key == K_D)
		rotate(0.2, d);
	if (key == K_PLUS)
		scale(0.2, d);
	if (key == K_MOINS)
		scale(-0.2, d);
	if (key == K_Q)
		d->auto_rot_y -= 0.01;
	if (key == K_E)
		d->auto_rot_y += 0.01;
	if (key == K_T)
		d->texture_toggle_status = (d->texture_toggle_status == 0) ? 1 : 0;
	return (1);
}

int				init_opengl(t_data *d)
{
	glEnable(GL_DEPTH_TEST);
	set_proj_matrix(d->proj_matrix, 70, 0.1, 100);
	set_view_matrix(d);
	set_trans_matrix(d);
	set_rot_y_matrix(d);
	set_scale_matrix(d);
	if (!(init_shaders(d)))
		return (0);
	get_locations(d);
	if (!(parse_obj_file(d)))
		return (0);
	if (!(recenter_42(d)))
		return (0);
	if (!(load_bmp(d->texture_file, d)))
		return (0);
	if (!(create_image(d)))
		return (0);
	return (1);
}

int				main(int argc, char *argv[])
{
	t_data		d;

	if (argc < 3)
		return (print_error("I need a .obj then a .bmp\n", 0));
	if (argc == 3)
	{
		init_data(&d);
		d.obj_file = argv[1];
		d.texture_file = argv[2];
		if (!(d.init = mlx_init()))
			return (print_error("minilibx failed to initialize\n", -1));
		if ((d.win = mlx_new_opengl_window(d.init, RES_X, RES_Y, TITLE)))
		{
			mlx_opengl_window_set_context(d.win);
			if (!(init_opengl(&d)))
				return (0);
			mlx_key_hook(d.win, key_events, &d);
			mlx_loop_hook(d.init, draw_img, &d);
			mlx_loop(d.init);
		}
	}
	return (0);
}
