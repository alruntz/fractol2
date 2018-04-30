/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 13:26:28 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/04 18:15:54 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(unsigned int a, t_options *options)
{
	unsigned int	ret;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (a == options->iteration_max)
		return (options->color_max);
	r = (a * 5) * options->color_value;
	g = (255 - (a * 10)) * options->color_value;
	b = (255 - (a * 2)) * options->color_value;
	ret = (r << 16) + (g << 8) + b;
	return (ret);
}

void			change_color(t_options *options)
{
	options->color_max += 10000;
	options->color_value++;
	if (options->color_max >= 0xffffff)
		options->color_max = 0x000000;
}
