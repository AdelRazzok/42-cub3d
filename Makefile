NAME          = cub3D
INCLUDES      = include/
HEADER        = -I $(INCLUDES)
SRC_DIR       = src/
OBJ_DIR       = obj/

CC            = gcc
CFLAGS        = -Wall -Wextra -Werror

UTILS_DIR     = utils/
UTILS         = str_utils \
				str_utils2 \
				ft_split \
				ft_substr \
				get_next_line \
				get_next_line_utils \
				t_map_utils

PARSER_DIR	  = parser/
PARSER		  = parser parser_utils

SRC_FILES    += main error
SRC_FILES    += $(addprefix $(UTILS_DIR), $(UTILS))
SRC_FILES    += $(addprefix $(PARSER_DIR), $(PARSER))

SRC           = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ           = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE     = .cache_exists

#####

all:			$(NAME)

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					@echo "$(NAME) compiled!"


$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(UTILS_DIR)
					@mkdir -p $(OBJ_DIR)$(PARSER_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@rm -rf $(OBJ_CACHE)
					@echo "$(NAME) object files cleaned!"

fclean:			clean
					@rm -f $(NAME)
					@echo "$(NAME) executable files cleaned!"

re:				fclean all
					@echo "Cleaned and rebuilt everything for $(NAME)!"

.PHONY:			all clean fclean re
