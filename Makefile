# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 14:04:19 by valeriafedo       #+#    #+#              #
#    Updated: 2024/01/10 14:07:30 by valeriafedo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minirt
HEADER		=	$(addprefix include/,\
					minirt.h\
					vector.h\
					camera.h\
					scene.h\
					utils.h\
					get_next_line.h)
RM				=	rm -rf
CFLAGS			=	-I include
CFLAGS			+=	-Lmlx -lmlx -framework OpenGL -framework AppKit


DIR_SRCS 		= ./srcs/
SRC				= main.c 
SRCS			= $(addprefix $(DIR_SRCS), $(SRC))
#OBJ 			=	$(SRCS:.c=.o)
OFLAGS 			=	-Wall -Wextra -Werror -Imlx -g #-fsanitize=address
IFLAGS			=	-Ilibft
LFLAGS			=	-Llibft -lft




OBJ			=	$(addprefix objects/, $(SRCS:%.c=%.o))

FOLDER		=	$(sort $(dir objects/ $(OBJ)))
LIBFT		=	./libft/libft.a

%.o: %.c 
	@cc -c $(CFLAGS) $(IFLAGS) $(DFLAGS)  $< -o $@

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a mlx/libmlx.a
	cc $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS) $(MFLAGS) -o $@
	@echo "$(YELLOW) Executable file $(NAME) was compiled $(END)"

FORCE:

#libft/libft.a: FORCE
#	cd libft && make
$(LIBFT)		:	libft_obj
			make -C ./libft
libft_obj	:
				mkdir libft_obj

mlx/libmlx.a: FORCE
	cd mlx && make

clean:
	$(RM) $(OBJ)
	make -C libft fclean
	@echo "$(PURPLE) Executable file $(NAME) was deleted$(END)"

fclean:	clean
	$(RM) $(NAME)
	@echo "$(END) Executable file $(NAME) was compiled$(END)"
re:	fclean all

.PHONY: all clean fclean re libft bonus
