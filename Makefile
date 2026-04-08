NAME			= cub3d
MINILIBX_DIR	= minilibx-linux
MINILIBX		= $(MINILIBX_DIR)/libmlx.a
PROJECT_DIR		= $(shell pwd)
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
CFLAGS			= -Wall -Wextra -Werror -g
INCLUDE			= -I$(LIBFT_DIR)/ft_printf -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -Iinclude
LDFLAGS			= -lmlx -L$(MINILIBX_DIR) -lXext -lX11 -lm 
MLX_CFLAGS		= CFLAGS='-O3 --std=gnu89 -g'

SRCS_PARSING	= src/parsing/parse_cub.c\
				  src/parsing/check_cub.c\
				  src/parsing/utils_cub.c\
				  src/parsing/check_textures.c\
				  src/parsing/parse_textures.c\
				  src/parsing/check_colors.c\
				  src/parsing/parse_colors.c\
				  src/parsing/parse_map.c

SRCS			= src/main.c\
				  src/utils.c\
				  src/window/create_window.c\
				  src/window/win_init_hooks.c\
				  src/window/show_window.c\
				  src/window/destroy_window.c\
				  src/window/draw_rectangle.c\
				  src/window/fill_rectangle.c\
				  src/window/sleep_ms.c\
				  src/window/draw_text.c\
				  src/window/draw_line.c\
				  src/window/window.c\
				  src/window/msgbox.c\
				  src/window/textbox.c\
				  src/window/image.c\
				  src/window/render_textbox.c\
				  $(SRCS_PARSING)

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

test: $(MINILIBX) $(LIBFT) $(filter-out obj/main.o, $(OBJS))
	$(CC) -o test_main $(CFLAGS) $(INCLUDE) $(filter %.o, $^) $(LIBFT) $(LDFLAGS)
	@./test_main

norm:
	norminette src include $(LIBFT_DIR) | grep Error || true

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean norm bonus all
