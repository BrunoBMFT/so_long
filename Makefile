NAME = so_long
SRCS_DIR = ./srcs
SRCS = main.c parser.c parser_aux.c parser_flood.c init_textures.c init_textures_aux.c handle_inputs.c \
		render.c init_vars.c img.c clean.c	
OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
CC = cc
COMPRESS = ar rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MLX_DIR = ./includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm -lz

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)
	@echo $(NAME) ready!

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo libft compiled and ready!

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo objects clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo so_long fclean

re: fclean all
#remove this
run: re
	clear && ./so_long map.ber

.PHONY: all bonus fclean clean re
