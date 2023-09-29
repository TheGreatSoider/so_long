# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:46:37 by cocheong          #+#    #+#              #
#    Updated: 2023/09/30 00:54:33 by cocheong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   	so_long
LIBFT        	=    	libft/libft.a
MLX            	=    	mlx/libmlx.a
CC            	=    	gcc
RM            	=    	rm -f
CFLAGS       	=    	-Wall -Wextra -Werror -Imlx
MLXFLAGS   		=    	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS_FILES    	=   	check_map \
						check_state \
						display \
						exit \
						floodfill \
						getdata \
						hook \
						init \
						movement \
						onscreensteps \
						so_long
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
