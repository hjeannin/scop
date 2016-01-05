/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:23:29 by hjeannin          #+#    #+#             */
/*   Updated: 2015/12/09 19:44:52 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			translate(GLfloat magnitude, GLfloat *axe, t_data *d)
{
	*axe += magnitude;
	set_trans_matrix(d);
}
