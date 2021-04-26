NAME			= cub3D

CC				= gcc
RM				= rm -rf
CFLAGS		= -Wall -Wextra -Werror
SFLAGS    = #-g3 -fsanitize=address
MFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit
INC_LINK 	= -I./utils/libft -I./srcs -I./utils/get_next_line

LIBFT 		= libft.a
LIBFT_LIB = ./utils/libft

SRCS			= ./srcs/cub3d.c\
					./srcs/cub_init.c\
					./srcs/cub_utils.c\
					./srcs/cub_utils_texture.c\
					./utils/get_next_line/get_next_line.c\
					./utils/get_next_line/get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS) libft
	@cp $(LIBFT_LIB)/$(LIBFT) $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) $(SFLAGS) $(INC_LINK) $(OBJS) $(LIBFT)
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
	@$(MAKE) -C $(LIBFT_LIB) clean
	@$(RM) $(OBJS)

fclean:			clean
	@$(MAKE) -C $(LIBFT_LIB) fclean
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft bonus