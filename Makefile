NAME = so_long

AR = @ar
AR_FLAGS = -rcs

COMPILER = @gcc
COMPILER_FLAGS = -Wall -Werror -Wextra -Imlx -Iincludes/
COMPILER_LIBRARIES = -framework OpenGL -framework AppKit

# Configuration...

# Libft...
LIBFT			=	libft.a
LIBFT_FOLDER	=	./libraries/libft

# Minilibx
MINILIBX		=	libmlx.dylib
MINILIBX_FOLDER	=	./libraries/minilibx_macos

# libmlx.a libmlx.dylib

# Build Folder
BUILD_FOLDER	=	./build
BUILD_FILES		=	$(addprefix $(BUILD_FOLDER)/, $(LIBFT)) \
					$(MINILIBX)

# Source Files...
SOURCE_FOLDER	=	./srcs
SOURCE_FILES	=	utilities/color.c \
					utilities/ft_strcmpchr.c \
					utilities/get_next_line.c \
					utilities/draw.c \
					properties/server.c \
					properties/client.c \
					properties/map.c \
					modules/map_check.c \
					modules/map_parse.c \
					modules/events.c \
					modules/game.c \
					scripts/example.c \
					scripts/map_properties.c \
					developer_functions.c \
					so_long.c

# Object Files...
EXTRA_FOLDERS	=	$(SOURCE_FOLDER)
OBJECT_FOLDER	=	./objects
OBJECT_FILES	=	$(addprefix $(OBJECT_FOLDER)/, $(addprefix $(SOURCE_FOLDER)/, $(SOURCE_FILES:.c=.o)))

.PHONY =  $(NAME) $(LIBFT) all clean fclean re dev

# Compile the .c files to .o files...
$(OBJECT_FOLDER)/%.o: %.c
	@mkdir -p $(OBJECT_FOLDER) $(addprefix $(OBJECT_FOLDER)/, $(dir $<))
	@echo "Compiling \t$(notdir $<) (100%)"
	@$(COMPILER) $(COMPILER_FLAGS) -I/usr/include -I$(MINILIBX_FOLDER) -O3 -c $< -o $@

# Compile the program...
$(NAME): $(LIBFT) $(MINILIBX) $(OBJECT_FILES)
	@echo "Building \t$(NAME)... (100%)"
	$(COMPILER) $(COMPILER_FLAGS) $(OBJECT_FILES) $(BUILD_FILES) $(COMPILER_LIBRARIES) -o $(NAME)

# Compile a LIBFT...
$(LIBFT):
	@echo "Compiling \t$(LIBFT)..."
	@$(MAKE) all -C $(LIBFT_FOLDER)
	@mkdir -p $(BUILD_FOLDER)
	@mv $(addprefix $(LIBFT_FOLDER)/, $(LIBFT)) $(addprefix $(BUILD_FOLDER)/, $(LIBFT))

# Compile minilibx
$(MINILIBX):
	@echo "Compiling \t$(MINILIBX)..."
	@$(MAKE) -C $(MINILIBX_FOLDER)
	@$(MAKE) all -C $(MINILIBX_FOLDER)
	@mkdir -p $(BUILD_FOLDER)
	@mv $(addprefix $(MINILIBX_FOLDER)/, $(MINILIBX)) $(MINILIBX)

all: $(NAME)

# Remove the `object` folder and files...
clean:
	@$(MAKE) clean -C $(LIBFT_FOLDER)
	@rm -rf $(OBJECT_FILES) $(OBJECT_FOLDER)

# Remove the `object` and `build` folder and files...
fclean: clean
	@$(MAKE) fclean -C $(LIBFT_FOLDER)
	@rm -rf $(NAME) $(BUILD_FOLDER) $(MINILIBX)

# Clean the program up and re-compile it...
re: fclean all

# Re-compile the program and run the script...
dev: all
	@echo "Executing \t$(NAME)"
	@./$(NAME) ./resources/maps/simple_map.ber
