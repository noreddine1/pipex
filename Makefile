# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 23:30:42 by nmaazouz          #+#    #+#              #
#    Updated: 2023/05/06 13:54:46 by nmaazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Werror -Wextra
NAME    = pipex
BONUS = pipex_bonus
INC = -I ./includes
HEAD_FILES = includes/pipex.h
LIBFT_A = libft.a

OBJ_DIR = obj/
OBJ_BNS_DIR = obj_bonus/

SRC_SH_DIR = src/shared/
SRC_BN_DIR = src/bonus/
SRC_MA_DIR = src/mandatory/

SRC_SH = error.c utils.c ft_function.c
SRC_MA = pipex.c
SRC_BN = pipex_bonus.c herdock.c

SRC_SH_PATH = $(addprefix $(SRC_SH_DIR), $(SRC_SH))
SRC_MA_PATH = $(addprefix $(SRC_MA_DIR), $(SRC_MA))
SRC_BN_PATH = $(addprefix $(SRC_BN_DIR), $(SRC_BN))

SRC_MANDATORY = SRC_SH_PATH SRC_MA_PATH
SRC_BONUS = SRC_SH_PATH SRC_BN_PATH

OBJ_SH_PATH = $(addprefix $(OBJ_DIR), $(SRC_SH:%.c=%.o))
OBJ_MA_PATH = $(addprefix $(OBJ_DIR), $(SRC_MA:%.c=%.o))
OBJ_BN_PATH = $(addprefix $(OBJ_DIR), $(SRC_BN:%.c=%.o))

OBJ_MANDATORY = $(OBJ_SH_PATH) $(OBJ_MA_PATH)
OBJ_BONUS = $(OBJ_SH_PATH) $(OBJ_BN_PATH)

all: $(LIBFT_A) $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_SH_PATH) $(OBJ_MA_PATH)
	$(CC) $(OBJ_MANDATORY) $(LIBFT_A) -o $@ $(INC)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_SH_PATH): $(OBJ_DIR)%.o: $(SRC_SH_DIR)%.c $(HEAD_FILES)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_MA_PATH): $(OBJ_DIR)%.o: $(SRC_MA_DIR)%.c $(HEAD_FILES)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@



bonus: $(BONUS)
	

$(BONUS): $(OBJ_DIR) $(LIBFT_A) $(OBJ_SH_PATH) $(OBJ_BN_PATH)
	$(CC) $(MLX_FLAGS) $(OBJ_BONUS) $(LIBFT_A) -o $@ $(INC)

$(OBJ_BN_PATH): $(OBJ_DIR)%.o: $(SRC_BN_DIR)%.c $(HEAD_FILES)
	@echo $(OBJ_BN_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_A):
	@make -s -C libft
	@cp libft/$(LIBFT_A) .

clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C libft clean

fclean: clean
	@rm -f $(BONUS) $(NAME) $(LIBFT_A)

re: fclean all bonus

.PHONY: all bonus clean fclean re