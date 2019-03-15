/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:52:46 by tigondol          #+#    #+#             */
/*   Updated: 2019/03/05 11:52:51 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_draw(t_fractol e)
{
    int     x;
    int     y;

    y = 0;
    while (y < e.v.image_h)
    {
        x = 0;
        while (x < e.v.image_w)
        {
            init_variables(&e, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(e.mlx, e.win, e.img.img, e.v.x, e.v.y);
}

void	init_mlx(t_fractol e)
{

    e.v.x = 0;
    e.v.y = 0;
    e.v.image_h = (1.2 + 1.2) * ZOOM;
	e.v.image_w = (0.6 + 2.1) * ZOOM;
    e.v.max_iteration = 50;
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
    e.img.img = mlx_new_image(e.mlx, e.v.image_w, e.v.image_h);
    e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp, &e.img.sizeline, &e.img.endian);
    ft_draw(e);
    mlx_hook(e.win, 2, 2, key_hook, &e);
    mlx_loop(e.mlx);
}

int		main(int ac, char **av)
{
	t_fractol e;

    if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") &&
        ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "shuriken")))
    {
        ft_putstr("Usage : ./fractol fractal [mandelbrot - julia");
        ft_putendl("- shuriken]");
        return (-1);
    }
    e.fractale = av[1];
    e.v.zoom = ZOOM;
    init_mlx(e);
    return (0);
}
