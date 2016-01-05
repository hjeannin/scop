/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_blender_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:27:29 by hjeannin          #+#    #+#             */
/*   Updated: 2016/01/05 20:01:55 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdio.h>
#include <string.h>

static int		check_obj_validity(char const *obj_file)
{
	if (strstr(obj_file, ".obj") == NULL)
		return (print_error("Not an .obj file.\n", 0));
	return (1);
}

static void		store_faces_ext(t_data *d, int *j, int t[4])
{
	d->faces_array[*j] = t[0] - 1;
	d->faces_array[*j + 1] = t[1] - 1;
	d->faces_array[*j + 2] = t[2] - 1;
	d->faces_array[*j + 3] = t[0] - 1;
	d->faces_array[*j + 4] = t[2] - 1;
	d->faces_array[*j + 5] = t[3] - 1;
	*j += 6;
}

static void		store_faces(t_data *d, int *j, FILE *file, int mode)
{
	int			res;
	int			t[4];
	int			i[4];

	res = 0;
	init_int_tab(t, 4);
	init_int_tab(i, 4);
	if (mode == SLASH)
		res = fscanf(file, "%i/%i %i/%i %i/%i %i/%i",
					&t[0], &i[0], &t[1], &i[1], &t[2], &i[2], &t[3], &i[3]);
	else if (mode == NO_SLASH)
		res = fscanf(file, "%i %i %i %i", &t[0], &t[1], &t[2], &t[3]);
	if (res == 3 || res == 6)
	{
		d->faces_array[*j] = t[0] - 1;
		d->faces_array[*j + 1] = t[1] - 1;
		d->faces_array[*j + 2] = t[2] - 1;
		*j += 3;
	}
	else if (res == 4 || res == 8)
		store_faces_ext(d, j, t);
	init_int_tab(t, 4);
}

static int		prepare_file_and_arrays(t_data *d, int *i, int *j)
{
	*i = 0;
	*j = 0;
	if (!check_obj_validity(d->obj_file))
		return (print_error("Invalid file\n", 0));
	count_needed_array_size(d, d->parsing_mode);
	d->faces_num_elem = d->f_count * 3;
	d->faces_array = create_uint_array(d->faces_num_elem);
	d->vertices_num_elem = d->v_count * 3;
	d->vertices_array = create_float_array(d->vertices_num_elem);
	return (1);
}

int				parse_obj_file(t_data *d)
{
	FILE		*file_ptr;
	char		buf[128];
	int			res;
	int			i;
	int			j;

	res = 0;
	if (!(prepare_file_and_arrays(d, &i, &j)))
		return (0);
	file_ptr = fopen(d->obj_file, "r");
	if (!(file_ptr))
		return (print_error("Could not open .obj\n", 0));
	while (res != EOF)
	{
		res = fscanf(file_ptr, "%s", buf);
		if (strcmp(buf, "v") == 0)
		{
			fscanf(file_ptr, "%f %f %f\n", &d->vertices_array[i],
					&d->vertices_array[i + 1], &d->vertices_array[i + 2]);
			i += 3;
		}
		if (strcmp(buf, "f") == 0)
			store_faces(d, &j, file_ptr, d->parsing_mode);
	}
	return (fclose(file_ptr) + 1);
}
