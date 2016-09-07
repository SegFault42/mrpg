/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 04:48:20 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/07 06:22:12 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	player_levelup(t_env *e)
{
	int		stat;
	e->player.xp -= (9 + e->player.lvl) * e->player.lvl;
	e->player.lvl++;
	stat = rand() % 3;
	if (stat == 0)
	{
		e->player.life += 2;
		e->player.max += 2;
	}
	else if (stat == 1)
		e->player.att++;
	else if (stat == 2)
		e->player.def++;
}

void		player_addxp(t_env *e)
{
	e->player.xp += e->enemy.xp;
	while (e->player.xp >= (9 + e->player.lvl) * e->player.lvl)
		player_levelup(e);
}
