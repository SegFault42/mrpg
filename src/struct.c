/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 12:15:31 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/06 06:29:51 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vect2i	set_vect2i(int x, int y)
{
	t_vect2i	vect2i;

	vect2i.x = x;
	vect2i.y = y;
	return (vect2i);
}

t_vect2d	set_vect2d(double x, double y)
{
	t_vect2d	vect2d;

	vect2d.x = x;
	vect2d.y = y;
	return (vect2d);
}

int			create_img(t_env *e, t_img *img)
{
	if (!(img->i = mlx_new_image(e->mlx, WIN_W, WIN_H)))
		return (0);
	img->d = mlx_get_data_addr(img->i, &(img->bpp), &(img->sl), &(img->edn));
	return (1);
}
