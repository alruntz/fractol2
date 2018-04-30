/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   images.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 13:34:08 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/04 16:31:25 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	add_pixel(t_options *options, int x, int y, unsigned int c)
{
	char	*px;
	int		bpp;
	int		endian;
	int		len;
	int		*tmp;

	if (x >= WIN_X || y >= WIN_Y || x < 0 || y < 0)
		return ;
	px = mlx_get_data_addr(options->img, &bpp, &len, &endian);
	tmp = (int *)&px[(y * len) + (x * (bpp / 8))];
	*tmp = c;
}
