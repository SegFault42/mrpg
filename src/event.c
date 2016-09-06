/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:47:26 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/06 10:23:59 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void get_event(t_env *e)
{
	e->event.type = rand() % 4 + 1;
	e->event.pos = e->player.key;
	if (e->event.type == 1)
	{
		e->player.col = 0xFF0000;//Combat
		e->player.life = e->player.life - 2;
		e->event.end = 1;
	}
	else if (e->event.type == 2)
	{
		e->player.col = 0x00FF00;//Soin
		e->player.life = (e->player.life + e->player.max / 5) > e->player.max ? e->player.max : e->player.life + e->player.max / 10;
		e->event.end = 1;
	}
	else if (e->event.type == 3)
	{
		e->player.col = 0x0000FF;//Defense
		e->event.end = 1;
	}
	else if (e->event.type == 4)
	{
		e->player.col = 0xFFFF00;//Attaque
		e->event.end = 1;
	}
}

int			apply_event(void *env)
{
	t_env	*e;

	e = (t_env*)env;
	if (e->player.key != e->event.pos)
		get_event(e);
	else
	{

	}
	e->player.pos = 0;
	expose_hook((void*)e);
	return (1);
}
