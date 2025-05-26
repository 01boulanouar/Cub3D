#include "Cupid.h"

static t_list	*skip_newlines(t_cube *cube)
{
	char	*line;
	t_list	*current;

	current = cube->lines;
	while (current)
	{
		line = current->content;
		if (line && !ft_isallspace(line))
			break ;
		current = current->next;
	}
	return (current);
}

static void	check_characters(char *line)
{
	if (!line)
		return ;
	while (*line)
	{
		if (!ft_isin(*line, "01NSEW") && !ft_isspace(*line))
			ft_error("Invalid Map Character");
		if (*line == 9)
			ft_error("Map should not contain tabs");
		line++;
	}
}

void	init_map(t_cube *cube)
{
	t_list	*current;
	char	*line;
	int		i;

	i = 0;
	current = skip_newlines(cube);
	cube->map = ft_malloc((ft_lstsize(current) + 1) * sizeof(char *));
	while (current)
	{
		line = current->content;
		if (line && !ft_isallspace(line) && current->next
			&& ft_isallspace(current->next->content))
			ft_error("Incorrect Map Structure: one or more empty lines");
		check_characters(line);
		if(!line)
			ft_error("Element after Map");
		cube->map[i++] = ft_strdup(line);
		current = current->next;
	}
	cube->map_length = i;
	cube->map[i] = NULL;
}
