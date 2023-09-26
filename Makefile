# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:46:37 by cocheong          #+#    #+#              #
#    Updated: 2022/11/30 14:46:37 by cocheong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX = mlx/libmlx.a
MLXFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c \
		check_map.c \
		check_state.c \
		display.c \
		exit.c \
		floodfill.c \
		getdata.c \
		hook.c \
		init.c \
		movement.c \

SRCS       		=     	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS        	=     	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR    	=    	srcs/
LIBFT_DIR    	=    	libft/
OBJS_DIR    	=    	objs/

all:            
						mkdir -p $(OBJS_DIR)
						make libft
						make $(NAME)

bonus:
						mkdir -p $(OBJS_DIR)
						make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) $(MLXFLAGS) -o $(NAME)

libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:            clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(NAME)

re:                fclean all

.PHONY:            all bonus libft clean fclean re
