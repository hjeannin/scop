/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:05:15 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 19:14:35 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "scop.h"

static int		prepare(char *filename, FILE **file, t_data *d)
{
	*file = fopen(filename, "rb");
	if (!(*file))
		return (print_error("Could not open .bmp\n", 0));
	if (fread(d->b.header, 1, 54, *file) != 54)
		return (print_error("Not a correct .bmp\n", 0));
	if (d->b.header[0] != 'B' || d->b.header[1] != 'M')
		return (print_error("Not a correct .bmp\n", 0));
	d->b.data_pos = *(int*)&(d->b.header[0x0A]);
	d->b.image_size = *(int*)&(d->b.header[0x22]);
	d->b.width = *(int*)&(d->b.header[0x12]);
	d->b.height = *(int*)&(d->b.header[0x16]);
	return (1);
}

int				load_bmp(char *filename, t_data *d)
{
	FILE				*file;

	file = NULL;
	if (!(prepare(filename, &file, d)))
		return (0);
	if (!(d->bmp_data = (unsigned char *)malloc(d->b.image_size)))
		return (print_error("Malloc error.\n", 0));
	fread(d->bmp_data, 1, d->b.image_size, file);
	fclose(file);
	return (1);
}
