
NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libs/libft
MLX_DIR = libs/MLX42

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/map_parce.c $(SRC_DIR)/map_utils.c $(SRC_DIR)/map_validation.c $(SRC_DIR)/map_path.c $(SRC_DIR)/render.c $(SRC_DIR)/player.c

OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/map_parce.o $(OBJ_DIR)/map_utils.o $(OBJ_DIR)/map_validation.o $(OBJ_DIR)/map_path.o $(OBJ_DIR)/render.o $(OBJ_DIR)/player.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)/include

LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/build/libmlx42.a -lglfw -ldl -lpthread -lm

# Colores ANSI
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/build/libmlx42.a
	@echo "$(BLUE)Compilando so_long...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)so_long compilado ✓$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/libft.a:
	@echo "$(BLUE)Compilando libft...$(NC)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN)libft compilado ✓$(NC)"

$(MLX_DIR)/build/libmlx42.a:
	@echo "$(BLUE)Compilando MLX42...$(NC)"
	@cd $(MLX_DIR) && cmake -B build
	@cd $(MLX_DIR) && cmake --build build -j4
	@echo "$(GREEN)MLX42 compilado ✓$(NC)"

clean:
	@echo "$(RED)Borrando objetos...$(NC)"
	@rm -rf $(OBJ_DIR)
	@make -s -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Objetos borrados ✓$(NC)"

fclean: clean
	@echo "$(RED)Borrando todo...$(NC)"
	@rm -f $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Todo borrado ✓$(NC)"

re: fclean all

.PHONY: all clean fclean re