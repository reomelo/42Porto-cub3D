#include "cub3D.h"

void ft_print_textures(t_tinfo *tinfo)
{
    printf("NO: %s\n", (char *)tinfo->north);
    printf("SO: %s\n", (char *)tinfo->south);
    printf("WE: %s\n", (char *)tinfo->west);
    printf("EA: %s\n", (char *)tinfo->east);
    printf("FLOOR 0: %d\n", tinfo->floor[0]);
    printf("FLOOR 1: %d\n", tinfo->floor[1]);
    printf("FLOOR 2: %d\n", tinfo->floor[2]);
    printf("CEIL 0: %d\n", tinfo->ceil[0]);
    printf("CEIL 1: %d\n", tinfo->ceil[1]);
    printf("CEIL 2: %d\n", tinfo->ceil[2]);
}