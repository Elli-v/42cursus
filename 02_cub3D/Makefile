NAME			= cub3D

CC				= gcc
RM				= rm -rf
CFLAGS		= -Wall -Wextra -Werror
SFLAGS    = -fsanitize=address
MFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit
INC_LINK 	= -I./utils/libft -I./srcs -I./utils/get_next_line

MLX				= libmlx.a
MLX_LIB		= ./mlx
LIBFT 		= libft.a
LIBFT_LIB = ./utils/libft

SRCS			= ./srcs/cub3d.c\
					./srcs/cub_save.c\
					./srcs/cub_key.c\
					./srcs/cub_exit.c\
					./srcs/parse/cub_init.c\
					./srcs/parse/cub_parse.c\
					./srcs/parse/cub_parsing_e.c\
					./srcs/parse/cub_utils_rgb.c\
					./srcs/parse/cub_utils_texture.c\
					./srcs/parse/cub_parsing_m.c\
					./srcs/parse/cub_utils.c\
					./srcs/parse/cub_map_convert_utils.c\
					./srcs/parse/cub_map_utils.c\
					./srcs/parse/cub_map_trim.c\
					./srcs/parse/cub_map_validity.c\
					./srcs/raycasting/raycasting.c\
					./srcs/raycasting/ray_init.c\
					./srcs/raycasting/ray_sprite.c\
					./srcs/raycasting/ray_draw_cf.c\
					./srcs/raycasting/ray_draw_sprite.c\
					./srcs/raycasting/ray_tex.c\
					./srcs/raycasting/ray_load_texture.c\
					./utils/get_next_line/get_next_line.c\
					./utils/get_next_line/get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(MLX) libft
	@cp $(LIBFT_LIB)/$(LIBFT) $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) $(MFLAGS) $(SFLAGS) $(INC_LINK) $(OBJS) $(LIBFT)
	@$(RM) $(LIBFT)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

#MLX compile
$(MLX):
	@$(MAKE) -C $(MLX_LIB) all

#libft compile
libft:
	@$(MAKE) -C $(LIBFT_LIB) all

clean:
	@$(MAKE) -C $(MLX_LIB) clean
	@$(MAKE) -C $(LIBFT_LIB) clean
	@$(RM) $(OBJS)

fclean:			clean
	@$(MAKE) -C $(LIBFT_LIB) fclean
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft bonus
