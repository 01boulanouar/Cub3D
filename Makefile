NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


rendering = rendering/init_data.c rendering/rendering.c rendering/raycasting.c

UTILS = utils/ft_atol.c utils/ft_exit.c utils/ft_free.c utils/ft_gc.c \
		utils/ft_isallspace.c utils/ft_isdigit.c utils/ft_isin.c utils/ft_isspace.c \
		utils/ft_error.c utils/ft_lstnew.c utils/ft_lstadd_back.c \
		utils/ft_lstsize.c utils/ft_malloc.c utils/ft_lstlast.c utils/ft_putendl_fd.c \
		utils/ft_putstr_fd.c utils/ft_split.c utils/ft_strchr.c utils/ft_strcmp.c \
		utils/ft_strcspn.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c \
		utils/ft_strncmp.c utils/ft_strspn.c utils/ft_substr.c \
		utils/get_next_line.c

PARSING = parsing/read_map.c parsing/init_rgb.c parsing/check_map.c parsing/init_elements.c parsing/init_map.c 

SRC = $(UTILS) $(PARSING) $(rendering) events.c main.c
OBJ = $(SRC:.c=.o)

MLX = mlx/libmlx_Linux.a
MLX_FLAGS = -L/usr/lib -lXext -lX11 -lm 

all: $(NAME)

$(MLX):
	make -C mlx

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME) 
%.o: %.c include/Cupid.h
	$(CC) $(CFLAGS) -I./include -c $< -o $@

bonus: all

clean:
	make -C mlx clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
