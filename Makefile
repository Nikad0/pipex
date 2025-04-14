NAME =  pipex

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR)

LIBFT_DIR = libft

LIBFT = libft.a

FLAG_RL = -L/usr/local/lib -I/usr/local/include

SRC_DIR = srcs

BUILD_DIR = .build

SRC_FILES = main.c    \
            pipex.c   \
			getters.c \
			
INCLUDES = includes

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJ:.o=.d)

all : $(NAME)


$(NAME) :  $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) $(OPTI_FLAGS) $(LIBFT_DIR)/$(LIBFT) $(EXT_FLAGS) $(FLAG_RL)

$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c includes/pipex.h Makefile | $(BUILD_DIR) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

clean :
	$(MAKE) -C $(LIBFT_DIR)/ clean
	$(RM) -r $(BUILD_DIR)
 
fclean : clean
	$(MAKE) -C $(LIBFT_DIR)/ fclean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: FORCE fclean clean re all
FORCE: