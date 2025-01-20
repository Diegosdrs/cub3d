# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artberna <artberna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 14:37:18 by dsindres          #+#    #+#              #
#    Updated: 2025/01/20 11:41:52 by artberna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = cub3d.h

FLAGS = -Wall -Wextra -Werror -g3 -I.

EXE_FLAGS = -lX11 -lXext

SRC = main.c check_all.c init_graphics.c init_map.c init_player.c is_playable.c utils.c \
game.c algo_raycast.c algo_raycast_2.c algo_raycast_utils.c \
algo_raycast_utils_2.c algo_raycast_utils_3.c close_game.c movement.c \
movement_2.c movement_3.c game_2.c  game_3.c movement_verif.c \
movement_verif_2.c

OBJ_DIR = obj
MINILIBX = minilibx-linux
MINILIBX_FLAGS = -L./$(MINILIBX) -l:libmlx_Linux.a
LIBFT = my_library
LIBFT_FLAGS = -L./$(LIBFT) -l:my_library.a

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


CC = cc


all : $(NAME)

$(NAME): $(OBJ) | $(LIBFT)/libft.a $(MINILIBX)/libmlx_Linux.a
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT_FLAGS) $(MINILIBX_FLAGS) $(EXE_FLAGS) -o $(NAME) -lm
	@echo "compilation done"

$(MINILIBX)/libmlx_Linux.a :
	@make -C $(MINILIBX)

$(LIBFT)/libft.a :
	@make -C $(LIBFT)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(MINILIBX)
	@echo "cleaned"

fclean : clean
	@rm -rf $(NAME)
	@rm -f $(LIBFT)/libft.a
	@rm -f $(MINILIBX)/libmlx_Linux.a
	@echo "fcleaned"


re : fclean all

.PHONY: all clean fclean re