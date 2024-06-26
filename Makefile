# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 16:43:25 by jmabel            #+#    #+#              #
#    Updated: 2024/04/22 20:42:05 by valeriafedo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY		:	all clean fclean re libft debug

NAME		=	miniRT

HEADER		=	$(addprefix include/,\
					minirt.h\
					vector.h\
					parcing.h\
					scene.h\
					get_next_line.h)

CFLAGS		=	-I include

CFLAGS		+=	-Wall -Wextra -Werror -g

# CFLAGS		+=	-fsanitize=address

RM			=	rm -rf

LIBFT		=	./libft/libft.a
LIBFT_H		=	./libft/libft.h

LIBMLX		=	./libmlx/libmlx.a

FILE_C		=	main.c

FILE_C		+=	$(addprefix image/,\
				hook.c\
				search_objects.c\
				resize_objects.c\
				change_objects.c\
				image.c)

FILE_C		+=	$(addprefix raytracer/,\
				check_intersection.c\
				intersection.c\
				intersection_cylinder.c\
				raytracer.c\
				compute_pixel_sphere.c\
				compute_pixel_plane.c\
				pixel_computing.c\
				compute_pixel_cylinder.c\
				solver.c)

FILE_C		+=	$(addprefix vector/,\
				scalar_product.c\
				vector_create.c\
				vector_length_normalizing.c\
				vector_linear_operations.c\
				vector_print.c)

FILE_C		+=	$(addprefix utils/,\
				get_next_line.c \
				print_scene.c)
				
FILE_C		+=	$(addprefix parser/,\
				parser.c\
				free_scene.c\
				parser_readscene.c\
				parser_utils.c\
				parser_readfloat.c\
				parser_readplane.c\
				parser_readsphere.c\
				parser_readcylinder.c\
				parser_set_ambinet_light.c)

FILE_C		+=	$(addprefix camera_move/,\
				camera_rotate.c\
				camera_rotation_utils.c\
				camera_translate.c)

SRCS		=	$(addprefix src/, $(FILE_C))

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