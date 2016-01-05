/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:20:00 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/09 20:38:43 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <float.h>

void			rotate(GLfloat power, t_data *d)
{
	d->rot_y += power;
	set_rot_y_matrix(d);
}

void			auto_rotate(t_data *d)
{
	d->rot_y += d->auto_rot_y;
	set_rot_y_matrix(d);
}
