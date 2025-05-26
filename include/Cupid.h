#ifndef CUPID_H
# define CUPID_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TITLE "cub3D"
# define HEIGHT 720
# define WIDTH 1280

# define TILE_SIZE 64

# define ESC 65307

# define CLOSE_BUTTON 17

# define W 119
# define D 100
# define S 115
# define A 97

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define TILE_SIZE 64

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}					t_direction;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;

typedef struct s_gc
{
	void			*ptr;
	struct s_gc		*next;

}					t_gc;

typedef struct s_img
{
	char			*path;

	void			*img;

	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

	int				height;
	int				width;

}					t_img;

typedef struct s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct s_player
{
	t_vec			pos;
	t_vec			dir;
}					t_player;

typedef struct s_ray
{
	t_vec			side;
	t_vec			delta;
	t_vec			dir;
	t_vec			step;
	t_direction		wall;
	double			perp_wall;
}					t_ray;

typedef struct s_cube
{
	void			*mlx;
	void			*win;
	t_img			frame;

	t_list			*lines;
	char			*f;
	char			*c;

	t_ray			ray;
	t_vec			plane;
	t_player		player;

	char			**map;
	int				map_x;
	int				map_y;
	int				map_length;

	t_img			no;
	t_img			so;
	t_img			we;
	t_img			ea;

	unsigned int	floor;
	unsigned int	celling;

}					t_cube;

// parsing
void				init_rgb(char *str, unsigned int *rgb);
void				init_map(t_cube *cube);
void				check_map(char **map);
void				check_player(char **map);
void				init_elements(t_cube *cube);
void				parse(int argc, char **argv, t_cube *cube);
void				init_data(t_cube *cube);

// rendering
void				init_player(t_cube *cube);
void				draw(t_cube *cube);
void				pixel_put(t_cube *cube, int x, int y, int color);
void				render(t_cube *cube);
int					close_window(t_cube *cube);

// utils
unsigned long long	ft_atol(const char *str);
void				ft_error(char *message);
void				ft_exit(int exit_status);
void				ft_free(void);
t_gc				**ft_gc(void);
int					ft_isdigit(char c);
int					ft_isallspace(char *str);
int					ft_isin(const char c, const char *charset);
int					ft_isspace(char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				*ft_malloc(size_t size);
t_list				*ft_lstlast(t_list *lst);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(const char *s, int fd);
char				**ft_free_split(char **arr, int i);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strspn(const char *s, const char *accept);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strcspn(const char *s, const char *reject);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*get_next_line(int fd);

#endif
