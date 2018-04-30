/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 16:43:48 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/04 18:18:39 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_X 750
# define WIN_Y 750
# define WIN_CX 750 / 2
# define WIN_CY 750 / 2

# include "libft.h"

typedef struct		s_vector2
{
	double x;
	double y;
}					t_vector2;

typedef struct		s_options
{
	void			*mlx;
	void			*win;
	float			c_r;
	float			c_i;
	float			zoom;
	unsigned int	iteration_max;
	int				key_j_press;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			tmp_x;
	double			tmp_y;
	double			tmp_x2;
	double			tmp_y2;
	void			*img;
	char			*str_img;
	int				bpp;
	int				s_l;
	int				endian;
	unsigned int	color_max;
	unsigned int	color_value;
	int				type_fract;
}					t_options;

void				run(t_options *options);
void				run_mandelbrot(t_options *options);
void				run_mandelruntz(t_options *options);
void				run_julia(t_options *options);

int					hook_mouse_move(int x, int y, t_options *options);
int					hook_key_press(int key, t_options *options);
int					hook_mouse_button(int button, int x, int y,
										t_options *options);

int					expose_hook(t_options *options);

void				add_pixel(t_options *options, int x, int y, unsigned int c);
unsigned int		get_color(unsigned int a, t_options *options);
void				change_color(t_options *options);

t_vector2			new_vector2(double x, double y);
void				put_infos(t_options *options);
void				change_fractale(t_options *options);
void				quit_program(t_options *options);

#endif
