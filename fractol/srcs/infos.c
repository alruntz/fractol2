/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   infos.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 17:24:08 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/04 18:16:33 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	put_infos(t_options *options)
{
	mlx_string_put(options->mlx, options->win, 10, 10,
			0x00FFFFFF, "--- FRACTALE EN COURS ---");
	if (options->type_fract == 1)
		mlx_string_put(options->mlx, options->win, 10, 30,
				0x00FFFFFF, "JULIA");
	else if (options->type_fract == 2)
		mlx_string_put(options->mlx, options->win, 10, 30,
				0x00FFFFFF, "MANDELBROT");
	else if (options->type_fract == 3)
		mlx_string_put(options->mlx, options->win, 10, 30,
				0x00FFFFFF, "MANDELRUNTZ");
}
