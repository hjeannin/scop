/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:32:58 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/10 17:42:56 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			scale(GLfloat magnitude, t_data *d)
{
	d->scale += magnitude;
	if (d->scale < 0.1f)
		d->scale = 0.1f;
	set_scale_matrix(d);
}
