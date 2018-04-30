/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hook.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 11:42:05 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 13:17:28 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keys_macos.h"

int		hook_mouse_move(int x, int y, t_options *options)
{
	if (x <= 0 || y <= 0 || x >= WIN_X ||
			y >= WIN_Y || !options->key_j_press)
		return (0);
	options->c_r = (float)(x + WIN_CX) / (WIN_X * 2);
	options->c_i = (float)(y + WIN_CY) / (WIN_Y * 2);
	run(options);
	return (0);
}

void	fractol_zoom(t_options *options, int x, int y, int sense)
{
	options->tmp_x = options->x1 + x * (options->x2 - options->x1) / WIN_X;
	options->tmp_y = options->y1 + y * (options->y2 - options->y1) / WIN_Y;
	options->tmp_x2 = options->x1;
	options->tmp_y2 = options->y1;
	if (sense)
	{
		options->zoom *= 2;
		options->x1 = options->tmp_x - (options->x2 - options->x1) / 4;
		options->x2 = options->tmp_x + (options->x2 - options->tmp_x2) / 4;
		options->y1 = options->tmp_y - (options->y2 - options->y1) / 4;
		options->y2 = options->tmp_y + (options->y2 - options->tmp_y2) / 4;
	}
	else
	{
		options->zoom /= 2;
		options->x1 = options->tmp_x - (options->x2 - options->x1);
		options->x2 = options->tmp_x + (options->x2 - options->tmp_x2);
		options->y1 = options->tmp_y - (options->y2 - options->y1);
		options->y2 = options->tmp_y + (options->y2 - options->tmp_y2);
	}
}

int		hook_mouse_button(int button, int x, int y, t_options *options)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		if (button == SCROLL_UP)
			fractol_zoom(options, x, y, 1);
		if (button == SCROLL_DOWN)
			fractol_zoom(options, x, y, 0);
		run(options);
	}
	return (0);
}

int		hook_key_press(int key, t_options *options)
{
	if (key == KEY_J && options->type_fract == 1)
		options->key_j_press = (options->key_j_press) ? 0 : 1;
	if ((key >= 123 && key <= 126) || key == KEY_C ||
			key == KEY_X || key == KEY_ESCAPE)
	{
		if (key == KEY_LEFT)
			options->x1 += 0.01;
		else if (key == KEY_RIGHT)
			options->x1 -= 0.01;
		else if (key == KEY_UP)
			options->y1 += 0.01;
		else if (key == KEY_DOWN)
			options->y1 -= 0.01;
		else if (key == KEY_C)
			change_color(options);
		else if (key == KEY_X)
			change_fractale(options);
		else if (key == KEY_ESCAPE)
			quit_program(options);
		run(options);
	}
	return (0);
}

int		expose_hook(t_options *options)
{
	run(options);
	return (0);
}
