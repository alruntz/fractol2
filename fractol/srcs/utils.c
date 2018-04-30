/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 13:49:44 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/04 18:15:15 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
#include "stdlib.h"
#include "mlx.h"

t_vector2	new_vector2(double x, double y)
{
	t_vector2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

void		change_fractale(t_options *options)
{
	if (options->type_fract == 3)
		options->type_fract = 1;
	else
		options->type_fract++;
}

void		quit_program(t_options *options)
{
	mlx_destroy_window(options->mlx, options->win);
	free(options);
	exit(0);
}
