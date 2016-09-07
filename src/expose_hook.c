/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:56:03 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/07 06:57:52 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		img_put_pixel(t_env *e, t_img *i, t_vect2i p, int c)
{
	int		pos;
	int		size;

	size = ((WIN_H - 1) * e->img.sl) + (WIN_W * e->img.bpp / 8);
	pos = (p.y * i->sl) + (p.x * i->bpp / 8);
	if (pos > 0 && pos + 2 < size && p.x >= 0
		&& (p.x * e->img.bpp / 8) < e->img.sl)
	{
		if (i->edn)
		{
			i->d[pos] = mlx_get_color_value(e->mlx, c / 0x10000 % 0x100);
			i->d[pos + 1] = mlx_get_color_value(e->mlx, c / 0x100 % 0x100);
			i->d[pos + 2] = mlx_get_color_value(e->mlx, c % 0x100);
		}
		else
		{
			i->d[pos] = mlx_get_color_value(e->mlx, c % 0x100);
			i->d[pos + 1] = mlx_get_color_value(e->mlx, c / 0x100 % 0x100);
			i->d[pos + 2] = mlx_get_color_value(e->mlx, c / 0x10000 % 0x100);
		}
	}
}

static void	clear_img(t_img *i)
{
	t_vect2i	p;
	int			pos;

	p.y = -1;
	while (++p.y < WIN_H)
	{
		p.x = -1;
		while (++p.x < WIN_W)
		{
			pos = (p.y * i->sl) + (p.x * i->bpp / 8);
			i->d[pos] = 0;
			i->d[pos + 1] = 0;
			i->d[pos + 2] = 0;
		}
	}
}

static void	draw_player(t_env *e, int x, int y)
{
	int		max_x;
	int		max_y;

	max_x = x + 50;
	max_y = y + 50;
	while (y < max_y)
	{
		x = max_x - 50;
		while (x < max_x)
		{
			img_put_pixel(e, &(e->img), set_vect2i(x, y), e->player.col);
			x++;
		}
		y++;
	}
}

static void	draw_enemy_stat(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 410, 0xFF0000, "ENEMY");
	mlx_string_put(e->mlx, e->win, 10, 430, 0x00AA00, "Life:");
	mlx_putcurval(e, set_vect2i(70, 430), 0x00AA00, e->enemy.life, e->enemy.max);
	mlx_string_put(e->mlx, e->win, 10, 450, 0xA52A2A, "Attack:");
	mlx_putnbr(e, set_vect2i(90, 450), 0xA52A2A, e->enemy.att);
	mlx_string_put(e->mlx, e->win, 10, 470, 0xADD8E6, "Defense:");
	mlx_putnbr(e, set_vect2i(100, 470), 0xADD8E6, e->enemy.def);
}

static void	draw_ui(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 5, 0xDDDDDD, "Level:");
	mlx_putnbr(e, set_vect2i(80, 5), 0xDDDDDD, e->player.lvl);
	mlx_string_put(e->mlx, e->win, 10, 25, 0xDDDDDD, "Exp:");
	mlx_putcurval(e, set_vect2i(60, 25), 0xDDDDDD, e->player.xp, (9 + e->player.lvl) * e->player.lvl);
	mlx_string_put(e->mlx, e->win, 10, 45, 0x00AA00, "Life:");
	mlx_putcurval(e, set_vect2i(70, 45), 0x00AA00, e->player.life, e->player.max);
	mlx_string_put(e->mlx, e->win, 10, 65, 0xFFFF00, "Attack:");
	mlx_putnbr(e, set_vect2i(90, 65), 0xFFFF00, e->player.att);
	mlx_string_put(e->mlx, e->win, 10, 85, 0x00AAFF, "Defense:");
	mlx_putnbr(e, set_vect2i(100, 85), 0x00AAFF, e->player.def);
	if (e->event.type > 0 && e->event.type < 5)
		draw_enemy_stat(e);
	if (e->player.life < 1)
		mlx_string_put(e->mlx, e->win, 200, 410, 0xFF0000, "YOU LOOSE");
}

int			expose_hook(void *env)
{
	t_env	*e;

	e = (t_env*)env;
	clear_img(&(e->img));
	if (e->player.pos == 0)
		draw_player(e, WIN_W / 2 - 25, WIN_H / 2 - 25);
	else if (e->player.pos == 1)
		draw_player(e, WIN_W / 2 - 75, WIN_H / 2 - 25);
	else if (e->player.pos == 2)
		draw_player(e, WIN_W / 2 - 25, WIN_H / 2 - 75);
	else if (e->player.pos == 3)
		draw_player(e, WIN_W / 2 + 25, WIN_H / 2 - 25);
	else if (e->player.pos == 4)
		draw_player(e, WIN_W / 2 - 25, WIN_H / 2 + 25);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	draw_ui(e);
	return (1);
}
