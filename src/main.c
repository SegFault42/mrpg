/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:49:57 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/07 06:47:09 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	launch_rpg(t_env *e)
{
	e->key.up = 0;
	e->key.down = 0;
	e->key.right = 0;
	e->key.left = 0;
	e->player.pos = 0;
	e->player.key = 0;
	e->player.life = 10;
	e->player.max = 10;
	e->player.att = 4;
	e->player.def = 0;
	e->player.lvl = 1;
	e->player.xp = 0;
	e->player.col = 0xFFFFFF;
	e->event.pos = 0;
	srand(time(NULL));
	mlx_key_hook(e->win, key_pressed, (void*)e);
	mlx_hook(e->win, DESTROYNOTIFY, STRUCTURE_NOTIFY_MASK, window_destroyed, e);
	mlx_loop_hook(e->mlx, apply_event, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}

int			main(void)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
		ft_putendl("Creation of mlx failed.");
	else if (!(e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "RPG 0")))
		ft_putendl("Creation of the window failed.");
	else if (!(create_img(&e, &(e.img))))
		ft_putendl("Creation of the image failed.");
	else
		launch_rpg(&e);
	return (0);
}
