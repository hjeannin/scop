/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_blender_file_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:24:26 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 20:37:18 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdio.h>
#include <string.h>

static int		scanning_wrong_mode(t_data *d, FILE **file)
{
	d->parsing_mode = (d->parsing_mode == SLASH) ? NO_SLASH : SLASH;
	d->v_count = 0;
	fclose(*file);
	count_needed_array_size(d, d->parsing_mode);
	return (1);
}

static int		scan_faces(t_data *d, int *res, FILE **file, int mode)
{
	int			t[4];
	int			i[4];

	init_int_tab(t, 4);
	init_int_tab(i, 4);
	if (mode == SLASH)
	{
		*res = fscanf(*file, "%i/%i %i/%i %i/%i %i/%i",
					&t[0], &i[0], &t[1], &i[1], &t[2], &i[2], &t[3], &i[3]);
		if (*res == 1)
			return (scanning_wrong_mode(d, file));
	}
	if (mode == NO_SLASH)
	{
		*res = fscanf(*file, "%i %i %i %i", &t[0], &t[1], &t[2], &t[3]);
		if (*res == 1)
			return (scanning_wrong_mode(d, file));
	}
	if (*res == 4 || *res == 6)
		d->f_count += 2;
	if (*res == 3 || *res == 8)
		d->f_count++;
	init_int_tab(t, 4);
	return (1);
}

int				count_needed_array_size(t_data *d, int mode)
{
	FILE		*file;
	char		buf[128];
	int			res;

	res = 0;
	file = fopen(d->obj_file, "r");
	if (!(file))
		return (print_error("Could not open .obj\n", 0));
	while (res != EOF)
	{
		res = fscanf(file, "%s", buf);
		if (strcmp(buf, "v") == 0)
			d->v_count++;
		if (strcmp(buf, "f") == 0)
			scan_faces(d, &res, &file, mode);
	}
	fclose(file);
	return (1);
}
