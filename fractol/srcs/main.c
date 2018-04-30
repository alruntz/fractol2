/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 19:08:39 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/04 18:36:34 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdlib.h>

int			param_error(int argc, char **argv)
{
	int type_fract;

	if (argc == 2)
	{
		type_fract = ft_atoi(argv[1]);
		if (type_fract >= 1 && type_fract <= 3)
			return (1);
	}
	ft_putstr("usage: fractol [num de la fractale]\n");
	ft_putstr("		1 : Julia\n");
	ft_putstr("		2 : Mandelbrot\n");
	ft_putstr("		3 : MandelRuntz");
	return (0);
}

void		run(t_options *options)
{
	options->img = mlx_new_image(options->mlx, WIN_X, WIN_Y);
	if (options->type_fract == 1)
		run_julia(options);
	else if (options->type_fract == 2)
		run_mandelbrot(options);
	else if (options->type_fract == 3)
		run_mandelruntz(options);
	put_infos(options);
}

t_options	*init_options(char **argv)
{
	t_options *ret;

	if (!(ret = (t_options *)malloc(sizeof(t_options))))
		return (NULL);
	ret->mlx = mlx_init();
	ret->win = mlx_new_window(ret->mlx, WIN_X, WIN_Y, "Fractol_101");
	ret->c_r = 0.285;
	ret->c_i = 0.01;
	ret->zoom = WIN_X / 4;
	ret->iteration_max = 500;
	ret->key_j_press = 0;
	ret->x1 = -2;
	ret->y1 = -1.25;
	ret->x2 = 2;
	ret->y2 = 1.25;
	ret->color_max = 0x000000;
	ret->color_value = 1;
	ret->type_fract = ft_atoi(argv[1]);
	return (ret);
}

int			main(int argc, char **argv)
{
	t_options *options;

	if (param_error(argc, argv))
	{
		options = init_options(argv);
		mlx_expose_hook(options->win, &expose_hook, options);
		mlx_hook(options->win, 6, (1L << 6), &hook_mouse_move, options);
		mlx_hook(options->win, 4, (1L << 2), &hook_mouse_button, options);
		mlx_key_hook(options->win, &hook_key_press, options);
		run(options);
		mlx_loop(options->mlx);
	}
	return (0);
}
