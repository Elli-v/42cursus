# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 15:24:05 by soooh             #+#    #+#              #
#    Updated: 2021/05/30 14:41:28 by soooh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC				= gcc
RM				= rm -rf
SRCS			= ./srcs/push_swap.c\
					./srcs/ps_utils.c\
					./srcs/ps_init.c\
					./srcs/ps_linked.c

CFLAGS			= -Wall -Wextra -Werror

INC_LINK 		= -I./libft -I./srcs

LIBFT 			= libft.a
LIBFT_LIB 		= ./libft

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):		$(OBJS) libft
	@cp $(LIBFT_LIB)/$(LIBFT) $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) $(INC_LINK) $(OBJS) $(LIBFT)
	@$(RM) $(LIBFT)
	
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

.PHONY:			all clean fclean re libft