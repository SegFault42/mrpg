/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:47:26 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/07 06:45:24 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	attack_target(int *life, int att, int def)
{
	if (att - def > 0)
		*life -= att - def;
	if (*life < 1)
		return (0);
	return (1);
}

static void	create_enemy(t_env *e)
{
	int		points;

	points = 4 + e->player.lvl * 2 + rand() % (2 + e->player.lvl / 2);
	e->enemy.xp = points;
	e->enemy.max = rand() % points * 2 + 2;
	points -= (e->enemy.max - 2) / 2;
	e->enemy.att = rand() % points + 1;
	points -= e->enemy.att - 1;
	e->enemy.def = points;
	e->enemy.life = e->enemy.max;
}

static void get_event(t_env *e)
{
	e->event.type = rand() % 8 + 1;
	e->event.pos = e->player.key;
	if (e->event.type > 0 && e->event.type < 5)
	{
		e->player.col = 0xFF0000;//Combat
		create_enemy(e);
		if (!attack_target(&(e->enemy.life), e->player.att, e->enemy.def))
		{
			player_addxp(e);
			e->event.type = 0;
		}
		attack_target(&(e->player.life), e->enemy.att, e->player.def);
	}
	else if (e->event.type > 4 && e->event.type < 7)
	{
		e->player.col = 0x00FF00;//Soin
		e->player.life = (e->player.life + e->player.max / 5) > e->player.max ? e->player.max : e->player.life + e->player.max / 5;
		e->event.type = 0;
	}
	else if (e->event.type == 7)
	{
		e->player.col = 0x0000FF;//Defense
		e->player.def++;
		e->event.type = 0;
	}
	else if (e->event.type == 8)
	{
		e->player.col = 0xFFFF00;//Attaque
		e->player.att++;
		e->event.type = 0;
	}
}

int			apply_event(void *env)
{
	t_env	*e;

	e = (t_env*)env;
	if (e->player.life > 0)
	{
		if (e->player.key != e->event.pos || (!e->event.type && e->player.pos))
			get_event(e);
		else if (e->event.pos == e->player.pos)
		{
			if (e->event.type > 0 && e->event.type < 5)
			{
				if (!attack_target(&(e->enemy.life), e->player.att, e->enemy.def))
				{
					player_addxp(e);
					e->event.type = 0;
				}
				else
					attack_target(&(e->player.life), e->enemy.att, e->player.def);
			}
		}
	}
	e->player.pos = 0;
	expose_hook((void*)e);
	return (1);
}
