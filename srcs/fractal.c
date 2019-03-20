/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:30:01 by tigondol          #+#    #+#             */
/*   Updated: 2019/03/05 13:30:05 by tigondol         ###   ########.fr       */
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

void	mandelbrot(t_fractol *e, int Px, int Py)
{
	float x0;
	float y0;
	float x;
	float y;
	int iteration;
	float xtemp;

	x0 = Px / e->v.zoom + e->v.x;
 	y0 = Py / e->v.zoom + e->v.y;
 	x = 0.0;
 	y = 0.0;
 	iteration = 0;
 	while (x*x + y*y < 4 && iteration < e->v.max_iteration)
	{
		xtemp = x*x - y*y + x0;
   		y = 2*x*y + y0;
   		x = xtemp;
   		iteration = iteration + 1;
 	}
	e->img.color = iteration * 255 * iteration;
	if (iteration != e->v.max_iteration)
		color_put(*e, Px, Py, e->img.color);
	else
		color_put(*e, Px, Py, 0x000000);
}

void	julia(t_fractol *e, int Px, int Py)
{
	float x0;
	float y0;
	float x;
	float y;
	int iteration;
	float xtemp;

	x0 = 0.285;
 	y0 = 0.01;
 	x = Px / e->v.zoom + e->v.x;
 	y = Py / e->v.zoom + e->v.y;
 	iteration = 0;
 	while (x*x + y*y < 4 && iteration < e->v.max_iteration)
	{
		xtemp = x*x - y*y + x0;
   		y = 2*x*y + y0;
   		x = xtemp;
   		iteration = iteration + 1;
 	}
	e->img.color = iteration * 256 * iteration;
	if (iteration != e->v.max_iteration)
		color_put(*e, Px, Py, e->img.color);
	else
		color_put(*e, Px, Py, 0x000000);
}
