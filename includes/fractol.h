/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:21:47 by tigondol          #+#    #+#             */
/*   Updated: 2019/03/22 13:21:53 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# define WIN_WIDTH	800
# define WIN_HEIGHT	800
# define ZOOM		300.0
/*
**	variables
*/
typedef struct		s_var
{
	float	x;
	float	y;
	double	x0;
	double	y0;
	int		i;
	double	tmp;
	double	zoom;
	// int		max;
	double	image_w;
	double	image_h;
	int		image_x;
	int		image_y;
	int		p;
	int 	max_iteration;
}					t_var;
/*
** img params ()
*/
typedef struct		s_data
{
	void	*img;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		tmp;
	int		x;
	int		y;
	int 	color;
}					t_data;

typedef struct		s_fractol
{
	void		*mlx;
	void		*win;
	char		*fractale;
	t_data		img;
	t_var		v;
}					t_fractol;
/*
**	key_tools.c
*/
int					key_hook(int keycode, t_fractol *e);
int 				mouse_mvm(int x, int y, t_fractol *e);
int 				mouse_zoom(int keycode, int x, int y, t_fractol *e);
/*
**	cleane_exit.c
*/
void				clean_exit(t_fractol *e);
/*
**	fractal.c
*/
void				mandelbrot(t_fractol *e, int Px, int Py);
void				julia(t_fractol *e, int Px, int Py);
void				shuriken(t_fractol *e, int Px, int Py);
void				init_fractale(t_fractol *e);
/*
**	main.c
*/
void				init_mlx(t_fractol e);
void    			ft_draw(t_fractol e);
#endif
