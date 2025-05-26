#include "Cupid.h"

static int	valid_file_name(char *str)
{
	int	i;

	if (!str || ft_strlen(str) < 4)
		return (0);
	i = ft_strlen(str) - 1;
	if (str[i--] == 'b' && str[i--] == 'u' && str[i--] == 'c' && str[i] == '.')
		return (1);
	return (0);
}

static t_list	*read_lines(char *str)
{
	char	*line;
	int		fd;
	t_list	*lines;

	lines = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Invalid file path or permisions");
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&lines, ft_lstnew(ft_strdup(line)));
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		ft_error("Failed to close the map file");
	return (lines);
}

void	parse(int argc, char **argv, t_cube *cube)
{
	if (argc != 2)
		ft_error("Invalid Argument: takes one argument");
	if (!valid_file_name(argv[1]))
		ft_error("Invalid file name: must end with .cube");
	cube->lines = read_lines(argv[1]);
	if (!cube->lines)
		ft_error("Empty Map File");
	init_elements(cube);
	init_rgb(cube->f, &cube->floor);
	init_rgb(cube->c, &cube->celling);
	init_map(cube);
	check_map(cube->map);
	check_player(cube->map);
}
