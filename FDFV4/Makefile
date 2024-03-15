# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 18:13:27 by eschussl          #+#    #+#              #
#    Updated: 2024/03/07 18:26:50 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3
SRCS_PATH		=	sources/
INIT_PATH		=	init/
PARS_PATH		=	parsing/
FREE_PATH		=	free/
DISPLAY_PATH	=	display/
GRAPHICS_PATH	=	graphics/
MY_MLX_PATH		=	my_mlx/
LIBFT			=	libft/libft.a
MINLIBX_PATH	=	minilibx-linux/
MINILIB			=	libmlx_Linux.a
SRCS			=	main.c\
					$(addprefix $(FREE_PATH),\
					fdf_error.c)\
					$(addprefix $(PARS_PATH),\
					fdf_mapping.c\
					fdf_parsing.c\
					fdf_summary_parsing.c\
					fdf_vertices.c)\
					$(addprefix $(DISPLAY_PATH),\
					fdf_display_mapping.c\
					fdf_display_summary.c)\
					$(addprefix $(GRAPHICS_PATH),\
					fdf_graphics.c\
					fdf_graphics_keypress.c\
					fdf_graphics_close.c\
					fdf_graphics_instructions.c\
					$(addprefix $(MY_MLX_PATH),\
					my_mlx_pixel_put.c))
OBJS_PATH		=	objects/
OBJS			=	$(addprefix $(OBJS_PATH),$(SRCS:.c=.o))
INC				=	-I./includes -I./libft/includes		

$(NAME): $(OBJS)
	make -C libft/ 
	make -C $(MINLIBX_PATH)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT) -lXext -lX11 -lz -lm -I$(MINLIBX_PATH) $(MINLIBX_PATH)$(MINILIB)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)$(PARS_PATH)
	@mkdir -p $(OBJS_PATH)$(FREE_PATH)
	@mkdir -p $(OBJS_PATH)$(DISPLAY_PATH)
	@mkdir -p $(OBJS_PATH)$(GRAPHICS_PATH)
	@mkdir -p $(OBJS_PATH)$(GRAPHICS_PATH)$(MY_MLX_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) -I$(MINLIBX_PATH)

all	:$(NAME)

bonus : $(NAME_BONUS)

libft :
	make -C libft/ 

minilibx :
	make -C $(MINLIBX_PATH)

libs : libft minilibx

clean :
	make -C $(MINLIBX_PATH) clean
	make -C libft/ clean
	rm -rf $(OBJS_PATH)
	rm -rf $(OBJS_PATH_BONUS)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all

.PHONY : all bonus clean fclean re
-include 
