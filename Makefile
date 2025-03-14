NAME =     pipex

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR) -g3

OPTI_FLAGS = -Ofast -march=native -flto -fno-signed-zeros -funroll-loops

DFLAGS = -MMD -MP

LIBFT_DIR = libft

LIBFT = libft.a

FLAG_RL = -L/usr/local/lib -I/usr/local/include -lreadline

MLX = libmlx.a

SRC_DIR = srcs

BUILD_DIR = .build

SRC_FILES = main.c \
            pipex.c\
			
INCLUDES = includes

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJ:.o=.d)

.PHONY: all
all : $(NAME)


$(NAME) :  $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) $(OPTI_FLAGS) $(LIBFT_DIR)/$(LIBFT) $(EXT_FLAGS) $(FLAG_RL)
.PHONY: mlx

.PHONY: libf
$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

.PHONY: clean
clean :
	$(MAKE) -C $(LIBFT_DIR)/ clean
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean : clean
	$(MAKE) -C $(LIBFT_DIR)/ fclean
	$(RM) $(NAME)

.PHONY: re
re : fclean
	$(MAKE) all

.PHONY: FORCE
FORCE: