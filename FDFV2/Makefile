# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 18:13:27 by eschussl          #+#    #+#              #
#    Updated: 2024/02/26 21:14:02 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3
SRCS_PATH		=	sources/
INIT_PATH		=	init/
PARS_PATH		=	parsing/
LIBFT			=	libft/libft.a
SRCS			=	main.c\
					$(addprefix $(INIT_PATH),\
					fdf_summary_init.c)\
					$(addprefix $(PARS_PATH),\
					fdf_mapping_line.c\
					fdf_mapping.c\
					fdf_parsing.c\
					fdf_summary_parsing.c)
OBJS_PATH		=	objects/
OBJS			=	$(addprefix $(OBJS_PATH),$(SRCS:.c=.o))
INC				=	-I./includes -I./libft/includes		

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)$(INIT_PATH)
	@mkdir -p $(OBJS_PATH)$(PARS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all	:$(NAME)

bonus : $(NAME_BONUS)

clean :
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
