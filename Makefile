NAME            = cub3D
INCLUDES        = include/
SRC_DIR         = src/
OBJ_DIR         = obj/
LIBMLX          = lib/MLX42

HEADER          = -I $(INCLUDES)  -I $(LIBMLX)/include/MLX42
LIBS            = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

CC              = gcc
CFLAGS          = -Wall -Wextra -Werror -g

UTILS_DIR       = utils/
UTILS           = str_utils \
				  str_utils2 \
				  ft_split \
				  ft_substr \
				  get_next_line \
				  get_next_line_utils \
				  t_map_utils

PARSER_DIR	    = parser/
PARSER		    = parser \
		  		  parser_utils \
		  		  parser_utils2 \
		  		  parser_handler

SCENE_DIR	    = scene/
SCENE           = window commands

SRC_FILES      += main error
SRC_FILES      += $(addprefix $(UTILS_DIR), $(UTILS))
SRC_FILES      += $(addprefix $(PARSER_DIR), $(PARSER))
SRC_FILES      += $(addprefix $(SCENE_DIR), $(SCENE))

SRC             = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ             = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE       = .cache_exists

#####

all:			libmlx $(NAME)

libmlx:
					@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
					@echo "$(NAME) compiled!"


$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(UTILS_DIR)
					@mkdir -p $(OBJ_DIR)$(PARSER_DIR)
					@mkdir -p $(OBJ_DIR)$(SCENE_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@rm -rf $(OBJ_CACHE)
					@rm -rf $(LIBMLX)/build
					@echo "$(NAME) object files cleaned!"

fclean:			clean
					@rm -f $(NAME)
					@echo "$(NAME) executable files cleaned!"

re:				fclean all
					@echo "Cleaned and rebuilt everything for $(NAME)!"

.PHONY:			all clean fclean re
