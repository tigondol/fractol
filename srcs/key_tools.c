/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:03:44 by tigondol          #+#    #+#             */
/*   Updated: 2019/03/05 13:03:45 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(t_fractol *e)
{
	mlx_destroy_image(e->mlx, e->img.img);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void	keytools_zoom(int keycode, t_fractol *e)
{
	if (keycode == 69)
	{
		e->v.zoom += 50;
		ft_draw(*e);
	}
	if (keycode == 78 && e->v.zoom > 1)
	{
		e->v.zoom -= 50;
		ft_draw(*e);
	}
}

int		mouse_mvm(int x, int y, t_fractol *e)
{
	if (ft_strcmp(e->fractale, "julia") == 0)
	{
		e->v.x0 = (double)x / 1000;
		e->v.y0 = (double)y / 1000;
		ft_draw(*e);
	}
	return (0);
}

int		mouse_zoom(int keycode, int x, int y, t_fractol *e)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		e->v.zoom += 50;
		ft_draw(*e);
	}
	else if (keycode == 5)
	{
		e->v.zoom -= 50;
		ft_draw(*e);
	}
	return (0);
}

int		key_hook(int keycode, t_fractol *e)
{
	if (keycode == 53)
		clean_exit(e);
	else if (keycode == 126)
		e->v.y -= 10 / e->v.zoom;
	else if (keycode == 125)
		e->v.y += 10 / e->v.zoom;
	else if (keycode == 124)
		e->v.x += 10 / e->v.zoom;
	else if (keycode == 123)
		e->v.x -= 10 / e->v.zoom;
	else if (keycode == 33 && e->v.max_iteration > 0)
		e->v.max_iteration -= 5;
	else if (keycode == 30)
		e->v.max_iteration += 5;
	ft_draw(*e);
	keytools_zoom(keycode, e);
	return (0);
}
