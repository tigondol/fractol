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
	double	x1;
	double	x2;
	double	xdiff;
	double	y1;
	double	y2;
	double	ydiff;
	double	c_reel;
	double	c_imaginaire;
	double	z_reel;
	double	z_imaginaire;
	int		i;
	double	tmp;
	double	zoom;
	int		max;
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
/*
**	mouse mvm params
*/
typedef struct		s_mouse
{
	int		x;
	int		y;
	int		x_mid;
	int		y_mid;
}					t_mouse;
typedef struct		s_fractol
{
	void		*mlx;
	void		*win;
	char		*fractale;
	t_data		img;
	t_var		v;
	t_mouse		mouse;
}					t_fractol;
/*
**	event.c
*/
void				move_img(t_fractol *e, t_data *black_screen,
int dx, int dy);
int					key_hook(int keycode, t_fractol *e);
int					mouse_hook(int button, int x, int y, void *param);
void				zoomer(t_fractol *mlx, t_data *black_screen, double value);
void				change_screen(t_fractol *mlx, t_data *e);
int					mouse_mvm(int x, int y, t_fractol *e);
/*
**	cleaners.c
*/
void				clean_exit(t_fractol *e);
void				clean_screen(t_fractol *mlx, t_data *e);
/*
**	algos.c
*/
void				mandelbrot(t_fractol *e, int Px, int Py);
// void				mandelbrot(t_fractol *e);
void				julia(t_fractol *e, int Px, int Py);
// void				shuriken(t_fractol *e);
void				init_fractale(t_fractol *e);
/*
**	fdf.c
*/
void				init_mlx(t_fractol e);
void    			ft_draw(t_fractol e);
#endif
