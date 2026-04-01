NAME			= cub3d
MINILIBX_DIR	= minilibx-linux
MINILIBX		= $(MINILIBX_DIR)/libmlx.a
PROJECT_DIR		= $(shell pwd)
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
CFLAGS			= -Wall -Wextra -Werror -g
INCLUDE			= -I$(LIBFT_DIR) -I$(MINILIBX_DIR)/include -Iinclude
LDFLAGS			= -lm -lXext -lX11 -lmlx -L$(MINILIBX_DIR)
MLX_CFLAGS		= CFLAGS='-O3 --std=gnu89'

SRCS			= src/main.c\

OBJS=$(SRCS:src/%.c=obj/%.o)

# tip: use make -s to silent the output
all: $(NAME)
bonus: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS) 
	$(CC) -o $@ $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(LDFLAGS)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $(CFLAGS) $(INCLUDE) $<

$(LIBFT): | $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

# only useful to bootstrap libft
$(LIBFT_DIR):
	git clone git@github.com:natamun/42-minishell.git
	mv 42-minishell/libft .
	rm 42-minishell -rf

$(MINILIBX): | $(MINILIBX_DIR)
	make -f Makefile.mk $(MLX_CFLAGS) -C $(MINILIBX_DIR)

$(MINILIBX_DIR):
	git clone https://github.com/42paris/minilibx-linux.git
	rm -rf $(MINILIBX_DIR)/.git

norm:
	norminette src $(LIBFT_DIR) | grep Error || true

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean norm bonus all
