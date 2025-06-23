/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:34:42 by liyu              #+#    #+#             */
/*   Updated: 2025/06/19 00:35:19 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


//!TODO calculate the tex. 

int load_texture(void *mlx, char *path, t_tex *tex)
{
    int w, h;

    tex->img = mlx_xpm_file_to_image(mlx, path, &w, &h);
    if (!tex->img)
        return (0); 
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &tex->endian);
    tex->width = w;
    tex->height = h;
    return (1);
}

void free_texture(void *mlx, t_tex *tex)
{
    if (tex->img)
        mlx_destroy_image(mlx, tex->img);
    tex->img = NULL;
}

int get_tex_color(t_tex *tex, int x, int y)
{
    char *pixel;

    pixel = tex->addr + y * tex->size_line + x * (tex->bpp / 8);
    return (*(int *)pixel);
}

void ft_cast_wall(t_game *game, double distance, int column, char *texture_path)
{
    t_tex tex;
    if (!load_texture(game->mlx_ptr, texture_path, &tex))
        ft_error_close(game, "Texture load fail");
    
    int wall_height = (BLOCK / distance) * (WIDTH / 2);
    int start_y = (HEIGHT - wall_height) / 2;
    int end_y = start_y + wall_height;

    int tex_x = calculate_tex_x(game, &tex); 

    for (int y = start_y; y < end_y; y++)
    {
        int tex_y = (y - start_y) * tex.height / wall_height;
        int color = get_tex_color(&tex, tex_x, tex_y);
        put_pixel(game, column, y, color);
    }    
    free_texture(game->mlx_ptr, &tex);
}

