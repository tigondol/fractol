/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:52:46 by tigondol          #+#    #+#             */
/*   Updated: 2019/03/21 17:26:53 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_fractol e)
{
	int		x;
	int		y;

	y = 0;
	while (y < e.v.image_h)
	{
		x = 0;
		while (x < e.v.image_w)
		{
			if (ft_strcmp(e.fractale, "mandelbrot") == 0)
				mandelbrot(&e, x, y);
			if (ft_strcmp(e.fractale, "julia") == 0)
				julia(&e, x, y);
			if (ft_strcmp(e.fractale, "shuriken") == 0)
				shuriken(&e, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img.img, e.v.x, e.v.y);
}

void	init_var(t_fractol *e)
{
	if (ft_strcmp(e->fractale, "mandelbrot") == 0
			|| ft_strcmp(e->fractale, "shuriken") == 0)
	{
		e->v.x = -2.1;
		e->v.y = -1.2;
	}
	if (ft_strcmp(e->fractale, "julia") == 0)
	{
		e->v.x = -1;
		e->v.y = -1.2;
		e->v.x0 = 0.285;
		e->v.y0 = 0.01;
	}
}

void	init_mlx(t_fractol e)
{
	init_var(&e);
	e.v.image_h = WIN_HEIGHT;
	e.v.image_w = WIN_WIDTH;
	e.v.max_iteration = 51;
	if (!(e.mlx = mlx_init()))
		exit(-1);
	if (!(e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol")))
		exit(-1);
	if (!(e.img.img = mlx_new_image(e.mlx, e.v.image_w, e.v.image_h)))
		exit(-1);
	e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp,
		&e.img.sizeline, &e.img.endian);
	ft_draw(e);
	mlx_hook(e.win, 6, (1L << 6), mouse_mvm, &e);
	mlx_mouse_hook(e.win, mouse_zoom, &e);
	mlx_hook(e.win, 2, 2, key_hook, &e);
	mlx_loop(e.mlx);
}

int		main(int ac, char **av)
{
	t_fractol e;

	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot")
			&& ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "shuriken")))
	{
		ft_putstr("Usage : ./fractol fractal [mandelbrot - julia");
		ft_putendl(" - shuriken]");
		return (-1);
	}
	e.fractale = av[1];
	e.v.zoom = ZOOM;
	init_mlx(e);
	return (0);
}
