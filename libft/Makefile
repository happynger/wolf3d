# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:03:49 by otahirov          #+#    #+#              #
#    Updated: 2019/01/10 13:00:08 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR		= ./src
STRDIR		= $(SRCDIR)/str
INTDIR		= $(SRCDIR)/int
MEMDIR		= $(SRCDIR)/mem
UTILDIR		= $(SRCDIR)/utills
PRINTFDIR	= $(SRCDIR)/ft_printf
OBJDIR		= ./obj

SRC			= $(addprefix str/,$(shell ls $(STRDIR)/ | grep -E ".+\.c")) \
			  $(addprefix int/,$(shell ls $(INTDIR)/ | grep -E ".+\.c")) \
			  $(addprefix mem/,$(shell ls $(MEMDIR)/ | grep -E ".+\.c")) \
			  $(addprefix utills/,$(shell ls $(UTILDIR)/ | grep -E ".+\.c")) \
			  $(addprefix ft_printf/,$(shell ls $(PRINTFDIR)/ | grep -E ".+\.c"))

OBJ			= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc

INC			= -I ./includes

all: obj $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/str
	@mkdir -p $(OBJDIR)/int
	@mkdir -p $(OBJDIR)/mem
	@mkdir -p $(OBJDIR)/utills
	@mkdir -p $(OBJDIR)/ft_printf

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Generated the lib"

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

git:
	@git add .
	@git commit -m "Automated Update $(shell date | head -c 19 | tail -c 15 && echo)"
	@git push
	@echo "The update was pushed to the github"