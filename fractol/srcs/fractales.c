/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractales.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 16:54:02 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/04 16:55:22 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

unsigned int	iteration(double z_r, double z_i, t_options *options)
{
	unsigned int	i;
	double			tmp;

	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < options->iteration_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + options->c_r;
		z_i = 2 * tmp * z_i + options->c_i;
		i++;
	}
	return (i);
}

void			run_julia(t_options *options)
{
	unsigned int	i;
	t_vector2		pos;
	double			z_r;
	double			z_i;

	pos = new_vector2(-1, -1);
	while (++pos.x < WIN_X)
	{
		pos.y = -1;
		while (++pos.y < WIN_Y)
		{
			z_r = pos.x / options->zoom + options->x1;
			z_i = pos.y / options->zoom + options->y1;
			i = iteration(z_r, z_i, options);
			if (i != options->iteration_max)
				add_pixel(options, pos.x, pos.y, get_color(i, options));
		}
	}
	mlx_put_image_to_window(options->str_img, options->win, options->img, 0, 0);
}

void			run_mandelbrot(t_options *options)
{
	unsigned int	i;
	int				color2;
	t_vector2		pos;

	color2 = 55;
	pos = new_vector2(-1, -1);
	while (++pos.x < WIN_X)
	{
		pos.y = -1;
		while (++pos.y < WIN_Y)
		{
			options->c_r = pos.x / options->zoom + options->x1;
			options->c_i = pos.y / options->zoom + options->y1;
			i = iteration(0, 0, options);
			if (i != options->iteration_max)
				add_pixel(options, pos.x, pos.y, get_color(i, options));
			else
				add_pixel(options, pos.x, pos.y,
							get_color(color2 += 45, options));
		}
	}
	mlx_put_image_to_window(options->str_img, options->win, options->img, 0, 0);
	mlx_destroy_image(options->mlx, options->img);
}

void			run_mandelruntz(t_options *options)
{
	unsigned int	i;
	t_vector2		pos;
	double			z_r;
	double			z_i;

	pos = new_vector2(-1, -1);
	while (++pos.x < WIN_X)
	{
		pos.y = -1;
		while (++pos.y < WIN_Y)
		{
			options->c_r = pos.x / options->zoom + options->x1;
			options->c_i = pos.y / options->zoom + options->y1;
			z_r = 3.14159265359 / 10.282 + options->c_r / 1.24;
			z_i = 3.14159265359 / 10.282 + options->c_i / 1.24;
			i = iteration(z_r, z_i, options);
			if (i != options->iteration_max)
				add_pixel(options, pos.x, pos.y, get_color(i, options));
		}
	}
	mlx_put_image_to_window(options->str_img, options->win, options->img, 0, 0);
	mlx_destroy_image(options->mlx, options->img);
}
