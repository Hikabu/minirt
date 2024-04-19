# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 15:15:41 by valeriafedo       #+#    #+#              #
#    Updated: 2024/04/07 19:52:21 by vfedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



.PHONY		:	all clean fclean re libft debug

NAME		=	miniRT

HEADER		=	$(addprefix include/,	\
					minirt.h			\
					parcing.h			\
					scene.h				\
					get_next_line.h		\
					utils.h)

CFLAGS		=	-I include

CFLAGS		+=	-Wall -Wextra -Werror -g

# CFLAGS		+=	-fsanitize=address

RM			=	rm -rf

LIBFT		=	./libft/libft.a
LIBFT_H		=	./libft/libft.h

LIBMLX		=	./libmlx/libmlx.a

SRCS		=	$(addprefix src/, $(FILE_C))

FILE_C		=	main.c

FILE_C		+=	$(addprefix parcing/, 		\
					get_next_line.c			\
					get_next_line_utils.c	\
					get_split.c				\
					parc.c					\
					error_free_exit.c)


FILE_C		+=	$(addprefix utils/, \
					print_scene.c)

FILE_C		+=	$(addprefix scene/, \
					init_image.c)
					
FILE_C		+=	$(addprefix parc_create/, \
					parc_cilinder.c		\
					parse_scene_file.c	\
					parsing_error.c		\
					parsing_utils.c		\
					matrix.c			\
					rotate_camera.c)

FILE_C		+=	$(addprefix geometry/, \
					vector.c	)
					
FILE_C		+=	$(addprefix ray_tracing/, \
					trace_ray.c			\
					check_shadow.c		\
					compute_sp_cyl.c	\
					check.c				\
					check_cylinder.c	\
					check_sphere.c		\
					solver.c			\
					pixel_computing.c	\
					rgb_utils.c)
					

OBJ			=	$(addprefix objects/, $(FILE_C:%.c=%.o))

FOLDER		=	$(sort $(dir objects/ $(OBJ)))

all			:	$(FOLDER) $(LIBFT) $(LIBMLX) $(NAME)

$(NAME)		:	$(OBJ) $(LIBFT) $(LIBMLX)
				$(CC) $(CFLAGS) $(DEBF) $(LIBFT) $(LIBMLX) -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

$(LIBFT)		:	libft_obj
				make -C ./libft

libft_obj	:
				mkdir libft_obj

$(LIBMLX)		:
				make -C ./libmlx


$(FOLDER)	:
				mkdir -p $@

objects/%.o	:	./src/%.c $(HEADER) Makefile $(LIBFT_H)
				$(CC) $(CFLAGS) $(DEBF) -c $< -o $@

debug:
				make DEBF="-g3"

clean		:
				$(RM) $(OBJ)
				$(RM) $(FOLDER)
				make clean -C ./libft
				make clean -C ./libmlx
				$(RM) libft_obj

fclean		:	clean
				$(RM) $(NAME)
				make fclean -C ./libft

re			:	fclean all