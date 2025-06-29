NAME		= cub3D
NAME_BONUS	= cub3D_bonus

INC_DIR		= inc
INC_DIR_BNS	= inc_bonus
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

VPATH		= $(GNL_DIR)
VPATH		+= src:src/window:src/render:src/parser:src/utils/memory:src/utils/string
VPATH		+= src_bonus:src_bonus/window:src_bonus/render:src_bonus/parser:src_bonus/utils/memory:src_bonus/utils/string
SRCS		= main.c \
			win_init.c win_utils.c win_hooks.c \
			utils_map.c init_map.c init_map_data.c init_map_textures.c parse_rgb.c map_validator.c init_player.c \
			draw.c render.c raycaster.c input.c dda.c \
			ft_calloc.c ft_memcpy.c \
			ft_atol.c ft_split.c ft_strchr.c ft_strdup.c ft_strlen.c ft_strtrim.c str_arr.c
BONUS_SRCS	= main_bonus.c \
			win_init_bonus.c win_utils_bonus.c win_hooks_bonus.c \
			utils_map_bonus.c init_map_bonus.c init_map_data_bonus.c init_map_textures_bonus.c parse_rgb_bonus.c map_validator_bonus.c init_player_bonus.c \
			draw_bonus.c render_bonus.c raycaster_bonus.c input_bonus.c dda_bonus.c minimap_bonus.c \
			ft_calloc_bonus.c ft_memcpy_bonus.c \
			ft_atol_bonus.c ft_split_bonus.c ft_strchr_bonus.c ft_strdup_bonus.c ft_strlen_bonus.c ft_strtrim_bonus.c str_arr_bonus.c
OBJS		= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(BUILD_DIR)/,$(BONUS_SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror -I$(MLX_DIR) -I$(GNL_DIR)
LDFLAGS		= -L$(MLX_DIR)
LDLIBS		= -lmlx -lm
RM			= rm -rf
ifeq ($(UNAME),Linux)
	LDLIBS	+= -lXext -lX11 
else ifeq ($(UNAME),Darwin)
	LDLIBS	+= -framework OpenGL -framework AppKit
endif

all: $(NAME)

bonus: CFLAGS += -I$(INC_DIR_BNS)
bonus: $(NAME_BONUS)

$(MLX):
	@make -C $(MLX_DIR)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): CFLAGS += -I$(INC_DIR)
$(NAME): $(GNL_OBJS) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(GNL_OBJS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(NAME_BONUS): $(GNL_OBJS) $(BONUS_OBJS) $(MLX)
	$(CC) $(CFLAGS) $(GNL_OBJS) $(BONUS_OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME_BONUS)

clean:
	$(RM) $(BUILD_DIR)
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
