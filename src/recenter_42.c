/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recenter_42.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:34:07 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/17 18:48:04 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <string.h>
#include <stdio.h>

int				recenter_42(t_data *d)
{
	int			i;

	i = 0;
	if (strstr(d->obj_file, "42.obj") > 0)
	{
		while (i < d->vertices_num_elem)
		{
			d->vertices_array[i + 2] -= 1.0;
			i += 3;
		}
	}
	return (1);
}
