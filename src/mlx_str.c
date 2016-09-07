/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 22:13:11 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/06 22:27:24 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mlx_putnbr(t_env *e, t_vect2i pos, int color, long nb)
{
	char	*str;

	str = ft_itoa(nb);
	mlx_string_put(e->mlx, e->win, pos.x, pos.y, color, str);
	free(str);
}

void	mlx_putcurval(t_env *e, t_vect2i pos, int color, long nb, long max)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = ft_strlen(str);
	mlx_string_put(e->mlx, e->win, pos.x, pos.y, color, str);
	free(str);
	mlx_string_put(e->mlx, e->win, pos.x + len * 10, pos.y, color, "/");
	str = ft_itoa(max);
	mlx_string_put(e->mlx, e->win, pos.x + 10 + len * 10, pos.y, color, str);
	free(str);
}
