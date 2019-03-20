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

void	keytools_zoom(int keycode, t_fractol *e)
{
	if (keycode == 69)
	{
		e->v.zoom += 50;
		// e->v.max_iteration += 5;
		ft_putendl("ZOOM +");
		// mlx_destroy_image(e->mlx, e->img.img);
		// e->v.image_w = (0.6 + 2.1) * e->v.zoom;
		// e->v.image_h = (1.2 + 1.2) * e->v.zoom;
		// printf("%f - %f \n", e->v.image_w, e->v.image_h);
		// e->img.img = mlx_new_image(e->mlx, e->v.image_w, e->v.image_h);
		// e->img.data = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.sizeline, &e->img.endian);
		ft_draw(*e);
	}
	if (keycode == 78)
	{
		e->v.zoom -= 50;
		ft_putendl("ZOOM -");
		// e->v.max_iteration -= 5;
		// mlx_destroy_image(e->mlx, e->img.img);
		// e->v.image_w = (0.6 + 2.1) * e->v.zoom;
		// e->v.image_h = (1.2 + 1.2) * e->v.zoom;
		// printf("%f - %f \n", e->v.image_w, e->v.image_h);
		// e->img.img = mlx_new_image(e->mlx, e->v.image_w, e->v.image_h);
		// e->img.data = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.sizeline, &e->img.endian);
		ft_draw(*e);
	}
}

int		key_hook(int keycode, t_fractol *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 53)
		exit(0);
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
	printf("%d\n", keycode);
	keytools_zoom(keycode, e);
	// mlx_put_image_to_window(e->mlx, e->win, e->img.img,
			// e->v.x, e->v.y);
	return (0);
}
