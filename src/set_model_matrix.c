/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_model_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:57:58 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/09 20:04:39 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			set_trans_matrix(t_data *d)
{
	translation_mat4(d->translate, d->trans_matrix);
}

void			set_rot_y_matrix(t_data *d)
{
	rotation_y_mat4(d->rot_y, d->rot_y_matrix);
}

void			set_scale_matrix(t_data *d)
{
	scale_mat4(d->scale, d->scale_matrix);
}
