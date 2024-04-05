# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 18:13:27 by eschussl          #+#    #+#              #
#    Updated: 2024/04/05 19:09:11 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

CC				=	@cc
CFLAGS			=	-Wall -Wextra -Werror -g3
LFLAGS			= 	-lXext -lX11 -lz -lm

LIBS_PATH		=	libs/
LIBFT_PATH		=	$(addprefix $(LIBS_PATH),libft/)
LIBFT			=	$(addprefix $(LIBFT_PATH),libft.a)
MINILIBX_PATH	=	$(addprefix $(LIBS_PATH),minilibx-linux/)
MINILIB			=	$(addprefix $(MINILIBX_PATH),libmlx.a)

SRCS_PATH		=	src/

BONUS_PATH		=	bonus/
INIT_PATH		=	init/
FREE_PATH		=	free/
PARS_PATH		=	parsing/
GRAPH_PATH		=	graphics/
HOOKS_PATH		=	hooks/
LINES_PATH		=	lines/
SRCS			=	main.c\
					$(addprefix $(FREE_PATH),fdf_error.c\
					fdf_freeparsing.c)\
					$(addprefix $(PARS_PATH), fdf_args.c\
					fdf_mapping.c\
					fdf_parsing.c\
					fdf_map_info.c\
					fdf_vertices.c\
					fdf_normilizing.c)\
					$(addprefix $(INIT_PATH),fdf_colors_init.c\
					fdf_scale_init.c\
					fdf_image_init.c\
					fdf_image_z_init.c)\
					$(addprefix $(GRAPH_PATH),fdf_graphics.c\
					fdf_draw_first_points.c\
					fdf_offset.c\
					fdf_scaling.c\
					fdf_put_pixel.c\
					fdf_clean_win.c)\
					$(addprefix $(HOOKS_PATH),fdf_hooks_close.c\
					fdf_hooks_keypress.c\
					fdf_angle.c\
					fdf_push_loop.c\
					fdf_events.c\
					fdf_mouse_scroll.c)\
					$(addprefix $(LINES_PATH),fdf_lines.c\
					fdf_draw_line.c\
					fdf_draw_pixel.c)\

					
SRCS_BONUS		=	main.c\
					$(addprefix $(FREE_PATH),fdf_error.c\
					fdf_freeparsing.c)\
					$(addprefix $(BONUS_PATH), fdf_args_bonus.c)\
					$(addprefix $(PARS_PATH), fdf_mapping.c\
					fdf_parsing.c\
					fdf_map_info.c\
					fdf_vertices.c\
					fdf_normilizing.c)\
					$(addprefix $(INIT_PATH),fdf_colors_init.c\
					fdf_scale_init.c\
					fdf_image_init.c\
					fdf_image_z_init.c)\
					$(addprefix $(GRAPH_PATH),fdf_graphics.c\
					fdf_draw_first_points.c\
					fdf_offset.c\
					fdf_scaling.c\
					fdf_put_pixel.c\
					fdf_clean_win.c)\
					$(addprefix $(HOOKS_PATH),fdf_hooks_close.c\
					fdf_hooks_keypress.c\
					fdf_push_loop.c\
					fdf_angle.c\
					fdf_events.c\
					fdf_mouse_scroll.c)\
					$(addprefix $(LINES_PATH),fdf_lines.c\
					fdf_draw_line.c\
					fdf_draw_pixel.c)\

OBJS_PATH		=	obj/
OBJS			=	$(addprefix $(OBJS_PATH),$(SRCS:.c=.o))
OBJS_BONUS		=	$(addprefix $(OBJS_PATH),$(SRCS_BONUS:.c=.o))
INC_PATH		=	inc/

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MINILIBX_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ $(LIBFT) $(MINILIB) -I$(MINLIBX_PATH)$(INC_PATH) -I$(LIBFT_PATH)$(INC_PATH) -I$(INC_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC_PATH)fdf.h
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)$(INIT_PATH)
	@mkdir -p $(OBJS_PATH)$(FREE_PATH)
	@mkdir -p $(OBJS_PATH)$(PARS_PATH)
	@mkdir -p $(OBJS_PATH)$(BONUS_PATH)
	@mkdir -p $(OBJS_PATH)$(GRAPH_PATH)
	@mkdir -p $(OBJS_PATH)$(HOOKS_PATH)
	@mkdir -p $(OBJS_PATH)$(LINES_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(MINILIBX_PATH) -I $(LIBFT_PATH)$(INC_PATH)

all	:$(NAME) libs

bonus : $(OBJS_BONUS)
	make -C $(LIBFT_PATH)
	make -C $(MINILIBX_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o fdf $(LIBFT) $(MINILIB) -I$(MINLIBX_PATH)$(INC_PATH) -I$(LIBFT_PATH)$(INC_PATH) -I$(INC_PATH)
	
libft :
	make -C $(LIBFT_PATH)

minilibx :
	make -C $(MINILIBX_PATH)

libs : libft minilibx

clean :
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS_PATH)

fclean : clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

bclean :
	rm -rf $(OBJS_PATH)

re : fclean all

.PHONY : all bonus clean fclean re
# -include 

