# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 15:10:49 by otahirov          #+#    #+#              #
#    Updated: 2019/01/18 13:31:36 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d

SRCDIR		= ./src
INCDIR		= ./includes
OBJDIR		= ./obj

SRC			= keyboard.c \
			  main.c \
			  reader.c \
			  render.c \
			  mouse.c

OBJ			= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC			= gcc
CFLAG		= -Wall -Wextra -Werror -O3

MLX			= ./minilibx
MLX_LINK	= -L $(MLX) -lmlx -framework OpenGL -framework AppKit
MLX_INC		= -I $(MLX)
MLX_LIB		= $(addprefix $(MLX),mlx.a)

FTDIR		= ./libft
FT			= $(addprefix $(FTDIR),/)
FT_LIB		= $(addprefix $(FT),libft.a)
FT_INC		= -I $(FTDIR)/includes
FT_LINK		= -L $(FTDIR) -lft

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAG) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LINK) $(FT_LINK) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: fclean all

git:
	@git add .
	@git commit -m "Automated Update $(shell date | head -c 19 | tail -c 15 && echo)"
	@git push
	@echo "The update was pushed to the github"