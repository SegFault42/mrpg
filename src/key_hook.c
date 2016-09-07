/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 22:27:54 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/07 05:02:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	free_datas_and_quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}

int			window_destroyed(void *env)
{
	t_env *e;

	e = (t_env*)env;
	free_datas_and_quit(e);
	return (1);
}

int			key_pressed(int key, void *env)
{
	t_env	*e;
	int		pos;

	e = (t_env*)env;
	pos = e->player.key;
	if (key == 53)
		free_datas_and_quit(e);
	if (key == 126)
		e->player.key = 2;
	if (key == 125)
		e->player.key = 4;
	if (key == 124)
		e->player.key = 3;
	if (key == 123)
		e->player.key = 1;
	if (key == 123 || key == 124 || key == 125 || key == 126)
		e->player.pos = e->player.key;
	expose_hook((void*)e);
	return (1);
}

// int			key_pressed(int key, void *env)
// {
// 	t_env *e;
//
// 	e = (t_env*)env;
// 	if (key == 53)
// 		free_datas_and_quit(e);
// 	if (key == 126)
// 		e->key.up = 1;
// 	if (key == 125)
// 		e->key.down = 1;
// 	if (key == 123)
// 		e->key.left = 1;
// 	if (key == 124)
// 		e->key.right = 1;
// 	return (1);
// }

// int			key_released(int key, void *env)
// {
// 	t_env *e;
//
// 	e = (t_env*)env;
// 	if (key == 126)
// 		e->key.up = 0;
// 	if (key == 125)
// 		e->key.down = 0;
// 	if (key == 123)
// 		e->key.left = 0;
// 	if (key == 124)
// 		e->key.right = 0;
// 	return (1);
// }
