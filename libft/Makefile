NAME	= libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRCS =\
$(FT_PRINTF_DIR)/ft_printf.c\
$(FT_PRINTF_DIR)/ft_printf_ops.c\
$(FT_PRINTF_DIR)/ft_vprintf_ops.c\
$(FT_PRINTF_DIR)/temp_sprintf.c\
$(FT_PRINTF_DIR)/padding.c\
$(FT_PRINTF_DIR)/precision_int.c\
$(FT_PRINTF_DIR)/get_hex.c\
$(FT_PRINTF_DIR)/write_ops.c\
$(FT_PRINTF_DIR)/parse_spec.c\
$(FT_PRINTF_DIR)/print_char.c\
$(FT_PRINTF_DIR)/print_hex_lower.c\
$(FT_PRINTF_DIR)/print_hex_upper.c\
$(FT_PRINTF_DIR)/print_int.c\
$(FT_PRINTF_DIR)/print_percent.c\
$(FT_PRINTF_DIR)/print_ptr.c\
$(FT_PRINTF_DIR)/print_str.c\
$(FT_PRINTF_DIR)/print_uint.c\

EM_SRCS=\
ft_atod.c\
ft_atol.c\
ft_darr.c\
ft_dstr.c\
ft_isspace.c\
ft_realloc.c\
ft_split_fn.c\
ft_str_ref.c\
ft_strchr_fn.c\
ft_strndup.c\
ft_strrchr_fn.c\
ft_strtrim_fn.c\
ft_panic.c\
ft_utoa.c\
$(FT_PRINTF_SRCS)\


SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c  \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c \
		ft_free_tab.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		ft_strjoin_free.c ft_putstr_tab_fd.c ft_strdup_tab.c \
		ft_printerr.c ft_strcmp.c $(EM_SRCS) ft_sort_tab.c \
		ft_push_tab.c ft_atoll.c

OBJS		= $(SRCS:%.c=obj/%.o)

SRCS_BONUS  = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS_BONUS  = $(SRCS_BONUS:%.c=obj/%.o)

SRCS_ALL	= $(SRCS) $(SRCS_BONUS)
OBJS_ALL	= $(OBJS) $(OBJS_BONUS)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -g

AR	= ar
ARFLAGS	= rcs

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

obj/%.o: %.c libft.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -I. -c $< -o $@

bonus: $(NAME) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS_ALL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
