# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 23:30:42 by nmaazouz          #+#    #+#              #
#    Updated: 2023/04/23 22:20:07 by nmaazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g
INC = -I ./includes
LIBFT_A = libft.a

OBJ_DIR = obj/

SRC_DIR = src/

SRC = pipex.c utils.c error.c

SRC_PATH = $(addprefix $(SRC_DIR), $(SRC))
OBJ_PATH = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

all: $(OBJ_DIR) $(LIBFT_A) $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(OBJ_PATH) includes/pipex.h
	$(CC) $(OBJ_PATH) $(LIBFT_A) -o $@ $(INC)

$(OBJ_PATH): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_A):
	@make -s -C libft
	@cp libft/$(LIBFT_A) .

clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C libft clean
	
fclean: clean
	@rm -f $(NAME) $(LIBFT_A)
	
re: fclean all



.PHONY: all clean fclean re