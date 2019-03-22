/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:30:01 by tigondol          #+#    #+#             */
/*   Updated: 2019/03/21 17:16:14 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_put(t_fractol e, int x, int y, int color)
{
	int	i;

	i = y * e.img.sizeline + e.img.bpp / 8 * x;
	if (i < 1)
		return (0);
	e.img.data[i] = color;
	e.img.data[i + 1] = color >> 8;
	e.img.data[i + 2] = color >> 16;
	return (0);
}

void	mandelbrot(t_fractol *e, int px, int py)
{
	float	x;
	float	y;
	int		iteration;
	float	xtemp;

	e->v.x0 = px / e->v.zoom + e->v.x;
	e->v.y0 = py / e->v.zoom + e->v.y;
	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y < 4 && iteration < e->v.max_iteration)
	{
		xtemp = x * x - y * y + e->v.x0;
		y = 2 * x * y + e->v.y0;
		x = xtemp;
		iteration = iteration + 1;
	}
	e->img.color = iteration * 255 * iteration;
	if (iteration != e->v.max_iteration)
		color_put(*e, px, py, e->img.color);
	else
		color_put(*e, px, py, 0x000000);
}

void	shuriken(t_fractol *e, int px, int py)
{
	float	x;
	float	y;
	int		iteration;
	float	xtemp;

	e->v.x0 = px / e->v.zoom + e->v.x;
	e->v.y0 = py / e->v.zoom + e->v.y;
	x = 0.0;
	y = 0.0;
	iteration = 0;
	while (x * x + y * y < 4 && iteration < e->v.max_iteration)
	{
		xtemp = x * x - y * y + e->v.x0;
		y = -2 * x * y + e->v.y0;
		x = xtemp;
		iteration = iteration + 1;
	}
	e->img.color = iteration * 255 / e->v.max_iteration;
	if (iteration != e->v.max_iteration)
		color_put(*e, px, py, e->img.color);
	else
		color_put(*e, px, py, 0x000000);
}

void	julia(t_fractol *e, int px, int py)
{
	float	x;
	float	y;
	int		iteration;
	float	xtemp;

	x = px / e->v.zoom + e->v.x;
	y = py / e->v.zoom + e->v.y;
	iteration = 0;
	while (x * x + y * y < 4 && iteration < e->v.max_iteration)
	{
		xtemp = x * x - y * y + e->v.x0;
		y = 2 * x * y + e->v.y0;
		x = xtemp;
		iteration = iteration + 1;
	}
	e->img.color = iteration * 256 * iteration;
	if (iteration != e->v.max_iteration)
		color_put(*e, px, py, e->img.color);
	else
		color_put(*e, px, py, 0x000000);
}
