#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int ft_count_line(int fd);
char **ft_fill(int fd);
int ft_check_map(int fd);
void ft_free_map(char **map);
void print_map(char **map);
int ft_validate_map(char **map);

int ft_check_map(int fd)
{
    int i;
    int j;
    int lines;
    char **map;
    int largura;

    fd = open("teste.ber", O_RDONLY);
    if (fd == -1)
        return (0);
    map = ft_fill(fd);
    lines = ft_count_line(fd);
    i = 0;
    largura = ft_strlen(map[0]);
//verifica se as linhas estão no mesmo tamanho
    while (map[i])
    {
        if (ft_strlen(map[i]) != largura)
            return (printf("Nao sao do mesmo tamanho\n"), ft_free_map(map), 0);
        i++;
    }
//verifica as pontas se são paredes
    j = 0;
    while (map[0][j])
    {
        if (map[0][j] != '1' && map[0][j] != 'E')
            return (printf("Parede superior invalida\n"), ft_free_map(map), 0);
        if (map[lines - 1][j] != '1' && map[lines - 1][j] != 'E')
            return (printf("Parede inferior invalida\n"), ft_free_map(map), 0);
        j++;
    }
    i = 0;
    while (map[i])
    {
        if (map[i][0] != '1' && map[i][0] != 'E') 
            return (printf("Parede esquerda invalida\n"), ft_free_map(map), 0);       
        if (map[i][largura - 1] != '1' && map[i][largura - 1] != 'E')
            return (printf("Parede direita invalida\n"), ft_free_map(map), 0);       
        i++;
    }
//verifica se tem todos elementos
    i = 0;
    int p = 0, c = 0, e = 0;
    int pi, pj;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                p++;
                pi = i;
                pj = j;

            }
            else if(map[i][j] == 'C')
                c++;
            else if(map[i][j] == 'E')
                e++;
            j++;
        }
        i++;
    }
    if (p == 1 && c > 0 && e == 1)
    {
        flood_fill(map, pj, pi);
        if (ft_validate_map(map) == 1)
            return (printf("Mapa Valido\n"), ft_free_map(map), 0);
        else
            return (printf("Mapa Invalido flood fill\n"), ft_free_map(map), 0);
    }    
    //return (printf("Mapa invalido\n"), ft_free_map(map), 0);
}

int ft_count_line(int fd)
{
    int i;
    char *line;

    i = 0;
    fd = open("teste.ber", O_RDONLY);
    if (fd == -1)
        return (0);
    while ((line = get_next_line(fd)) != NULL )
	{
		i++;
		free(line);
	}
    close(fd);
    return (i);
}

char **ft_fill(int fd)
{
    int i = 0;
    char *line;
    char **map;
    size_t len;

    fd = open("teste.ber", O_RDONLY);
    if(fd == -1)
        return (0);
    map = malloc(sizeof(char *) * (ft_count_line(fd) + 1));
    if(map == NULL)
        return (0);
    while ((line = get_next_line(fd)) != NULL)
	{
        len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
		map[i] = line;
		i++;
	}
	map[i] = NULL;
    close(fd);
    return (map);
}

void ft_free_map(char **map)
{
    int i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void flood_fill(char **map, int x, int y)
{
    if (x < 0 || y < 0 || !map[y] || !map[y][x])
        return;
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    map[y][x] = 'V';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

void print_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}
int ft_validate_map(char **map)
{
    int i = 0;
    int j;

    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                return (0);
            else if(map[i][j] == 'C')
                return (0);
            else if(map[i][j] == 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
        /*if (pi != -1 && pj != -1)
        {
            printf("Mapa depois do flood fill:\n");
            print_map(map);
        }
        return (printf("Mapa valido apos flood fill\n"), 0);*/


