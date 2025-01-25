#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int ft_check_map(int fd);

int main(void)
{
    int fd;

    fd = open("teste.ber", O_RDONLY);
    ft_check_map(fd);
    //flood_fill(map, 1, 1);
}