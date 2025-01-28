#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "so_long.h"

int ft_check_map(int fd);

int main(void)
{
    int fd;

    fd = open("map_0.ber", O_RDONLY);
    ft_check_map(fd);
    //flood_fill(map, 1, 1);
}