# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigondol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 11:22:36 by tigondol          #+#    #+#              #
#    Updated: 2019/03/04 13:56:02 by tigondol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

# src / obj files
SRC		= main.c \
			key_tools.c \
			fractal.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

#compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#mlx library
MLX		= ./minilibx/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx
MLX_LNK	= -L ./minilibx -l mlx -framework OpenGL -framework AppKit

#ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/
FT_LNK	= -L ./libft -l ft

#directories
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

.PHONY: all, clean, fclean, re

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "Object done."

$(FT_LIB):
	@make -C $(FT)
	@echo "Libft ok."

$(MLX_LIB):
	@make -C $(MLX)
	@echo "MiniLibX ok."

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "Everything done."

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean
	@echo "Objects cleaned."

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "Everything cleaned."

re: fclean all
