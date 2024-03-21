# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 18:13:27 by eschussl          #+#    #+#              #
#    Updated: 2024/03/21 15:50:23 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

CC				=	@cc
CFLAGS			=	-Wall -Wextra -Werror -g3
LFLAGS			= 	-lXext -lX11 -lz -lm

LIBFT_PATH		=	libft/
LIBFT			=	$(addprefix $(LIBFT_PATH),libft.a)
MINILIBX_PATH	=	minilibx-linux/
MINILIB			=	$(addprefix $(MINILIBX_PATH),libmlx.a)

SRCS_PATH		=	sources/
DISPLAY_PATH	=	display/
ERRORS_PATH		=	errors/
EVENT_PATH		=	event/
GRAPHICS_PATH	=	graphics/
PARSING_PATH	=	parsing/
SCALE_PATH		=	scale/
DISPLAY_PATH	=	display/
INIT_PATH		=	init/
COLOR_PATH		=	colors/
SRCS			=	main.c\
					$(addprefix $(ERRORS_PATH),\
					fdf_error.c)\
					$(addprefix $(PARSING_PATH),\
					fdf_args.c\
					fdf_mapping.c\
					fdf_parsing.c\
					fdf_map_info.c\
					fdf_vertices.c\
					fdf_normalizing.c\
					fdf_colors_set.c)\
					$(addprefix $(DISPLAY_PATH),\
					fdf_display_list.c\
					fdf_display_map.c\
					fdf_display_vertex.c\
					fdf_display_display.c)\
					$(addprefix $(INIT_PATH),\
					fdf_main_init.c\
					fdf_colors_init.c\
					fdf_image_init.c\
					fdf_display_init.c)\
					$(addprefix $(GRAPHICS_PATH),\
					fdf_graphics.c\
					fdf_graphics_close.c\
					fdf_graphics_keypress.c\
					fdf_draw_points.c\
					my_mlx_pixel_put.c\
					fdf_clean_win.c\
					fdf_push_loop.c\
					fdf_offset.c\
					fdf_move.c)\
					$(addprefix $(EVENT_PATH),\
					fdf_event.c)\
					$(addprefix $(COLOR_PATH),\
					fdf_color_shift.c\
					fdf_color2_vertex.c\
					fdf_colors_set.c)\

OBJS_PATH		=	objects/
OBJS			=	$(addprefix $(OBJS_PATH),$(SRCS:.c=.o))
INC_PATH		=	includes/

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MINILIBX_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ $(LIBFT) $(MINILIB) -I$(MINLIBX_PATH)$(INC_PATH) -I$(LIBFT_PATH)$(INC_PATH) -I$(INC_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC_PATH)fdf.h
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)$(ERRORS_PATH)
	@mkdir -p $(OBJS_PATH)$(PARSING_PATH)
	@mkdir -p $(OBJS_PATH)$(DISPLAY_PATH)
	@mkdir -p $(OBJS_PATH)$(INIT_PATH)
	@mkdir -p $(OBJS_PATH)$(GRAPHICS_PATH)
	@mkdir -p $(OBJS_PATH)$(EVENT_PATH)
	@mkdir -p $(OBJS_PATH)$(COLOR_PATH)

	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(MINILIBX_PATH) -I $(LIBFT_PATH)$(INC_PATH)

all	:$(NAME) libs

bonus : $(NAME_BONUS)

libft :
	make -C $(LIBFT_PATH)

minilibx :
	make -C $(MINILIBX_PATH)

libs : libft minilibx

clean :
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS_PATH)
	rm -rf $(OBJS_PATH_BONUS)

fclean : clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all

.PHONY : all bonus clean fclean re
-include 
