
NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libs/libft
MLX_DIR = libs/MLX42

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/map_parce.c $(SRC_DIR)/map_utils.c $(SRC_DIR)/map_validation.c

OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/map_parce.o $(OBJ_DIR)/map_utils.o $(OBJ_DIR)/map_validation.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)/include

LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/build/libmlx42.a -lglfw -ldl -lpthread -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) 
	make -C $(LIBFT_DIR) fclean 

re: fclean all

.PHONY: all clean fclean re