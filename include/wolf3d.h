/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:17:17 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/06 09:35:40 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <stdio.h>
# include "includes/libft.h"
# include "mlx.h"

# define WIN_W 500
# define WIN_H 500

# define MOTION_MASK (1L<<6)
# define KEYPRESS_MASK (1L<<0)
# define KEYRELEASE_MASK (1L<<1)
# define STRUCTURE_NOTIFY_MASK (1L<<17)
# define MOTION_NOTIFY 6
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROYNOTIFY 17

typedef struct s_vect2d		t_vect2d;
typedef struct s_vect2i		t_vect2i;
typedef struct s_img		t_img;
typedef struct s_keys		t_keys;
typedef struct s_player		t_player;
typedef struct s_event		t_event;
typedef struct s_env		t_env;

struct		s_vect2d
{
	double	x;
	double	y;
};

struct		s_vect2i
{
	int		x;
	int		y;
};

struct		s_img
{
	void	*i;
	char	*d;
	int		bpp;
	int		sl;
	int		edn;
};

struct		s_keys
{
	int		up;
	int		left;
	int		right;
	int		down;
};

struct		s_player
{
	int		pos;
	int		key;
	int		life;
	int		max;
	int		att;
	int		def;
	int		col;
};

struct		s_event
{
	int		type;
	int		pos;
	int		end;
};

struct		s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_keys		key;
	t_event		event;
};

t_vect2d	set_vect2d(double x, double y);
t_vect2i	set_vect2i(int x, int y);
int			create_img(t_env *e, t_img *img);

int			key_pressed(int key, void *env);
int			key_released(int key, void *env);
int			apply_event(void *env);
int			window_destroyed(void *env);
int			expose_hook(void *env);

void		img_put_pixel(t_env *d, t_img *i, t_vect2i p, int c);

#endif
