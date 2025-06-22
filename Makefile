NAME		= cub3D

INC_DIR		= inc
LIB_DIR		= lib
BUILD_DIR	= build

UNAME		= $(shell uname -s)

GNL_DIR		= $(LIB_DIR)/get_next_line
GNL_SRCS	= $(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c
GNL_OBJS	= $(addprefix $(BUILD_DIR)/, $(notdir $(GNL_SRCS:.c=.o)))
ifeq ($(UNAME),Linux)
	MLX_DIR	= $(LIB_DIR)/minilibx-linux
else ifeq ($(UNAME),Darwin)
	MLX_DIR	= $(LIB_DIR)/minilibx-macos
endif
MLX			= $(MLX_DIR)/libmlx.a

VPATH		= src:src/window:src/render
SRCS		= main.c \
			win_init.c win_utils.c win_hooks.c
OBJS		= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(GNL_DIR)
LDFLAGS		= -L$(MLX_DIR)
LDLIBS		= -lmlx -lm
RM			= rm -rf
ifeq ($(UNAME),Linux)
	LDLIBS	+= -lXext -lX11 
else ifeq ($(UNAME),Darwin)
	LDLIBS	+= -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
	$(RM) $(BUILD_DIR)
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
