# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 14:41:50 by eschussl          #+#    #+#              #
#    Updated: 2024/02/25 18:16:12 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS_PATH 	=	sources/
LIBFT_PATH	=	libft/
GNL_PATH	=	get_next_line/
PRINTF_PATH	=	ft_printf/
PRINTFD_PATH=	fd_printf/
LST_PATH	=	lst/
MEM_PATH	=	mem/
PUT_PATH	=	put/
IS_PATH		=	is/
TO_PATH		=	to/
ALLOC_PATH	=	alloc/
READ_PATH	=	read/
CONVERT_PATH=	convert/
STR_PATH	=	str/

SRCS		=	$(addprefix $(LIBFT_PATH),\
				$(addprefix $(LST_PATH),\
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c)\
				$(addprefix $(MEM_PATH),\
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c)\
				$(addprefix $(PUT_PATH),\
				ft_putchar_fd.c ft_putlchar.c ft_putlstr.c ft_putnbr_fd.c ft_putstr_fd.c\
				ft_putlchar_fd.c ft_putlstr_fd.c\
				$(addprefix $(PRINTF_PATH),\
				ft_c.c ft_check_printf.c ft_flen.c ft_i_bis.c ft_i_ter.c\
				ft_i.c ft_initstruct.c ft_is.c ft_p_bis.c ft_p.c\
				ft_percentsign.c ft_s.c ft_strread.c ft_u_bis.c\
				ft_u.c ft_x_bis.c ft_x_ter.c ft_x.c ft_printf.c)\
				$(addprefix $(PRINTFD_PATH),\
				ft_c_fd.c ft_i_fd.c ft_i_ter_fd.c ft_p_fd.c\
				ft_percentsign_fd.c fd_printf.c ft_s_fd.c\
				ft_strread_fd.c ft_u_fd.c ft_x_fd.c))\
				$(addprefix $(IS_PATH),\
				ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c)\
				$(addprefix $(TO_PATH),\
				ft_tolower.c ft_toupper.c)\
				$(addprefix $(ALLOC_PATH),\
				ft_setalloc.c ft_calloc.c)\
				$(addprefix $(CONVERT_PATH),\
				ft_atoi.c ft_itoa.c ft_split.c)\
				$(addprefix $(READ_PATH),\
				gwf.c\
				$(addprefix $(GNL_PATH),\
				gnl_utils.c gnl.c))\
				$(addprefix $(STR_PATH),\
				ft_strchr.c ft_strdcpy.c ft_strdup.c ft_striteri.c ft_strjoin.c\
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c))\
				

OBJS		=	$(addprefix $(OBJS_PATH),$(SRCS:.c=.o))

OBJS_PATH	=	objects/

CC			=	cc

INC			=	-I ./includes

DEP			=	$(OBJS:.o=.d)

CFLAGS		=	-MMD -Wall -Wextra -Werror -g3

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $@ $^

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
			@mkdir -p $(OBJS_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(PUT_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(PUT_PATH)$(PRINTF_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(PUT_PATH)$(PRINTFD_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(READ_PATH)$(GNL_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(LST_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(MEM_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(IS_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(TO_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(ALLOC_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(CONVERT_PATH)
			@mkdir -p $(OBJS_PATH)$(LIBFT_PATH)$(STR_PATH)
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:	
			rm -rf $(OBJS_PATH)

fclean:		clean
			rm -f $(NAME)

re:			fclean
			make all
-include 