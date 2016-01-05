
SRC_PATH	=	src/
OBJ_PATH	=	obj/

SRCS		=	$(shell ls $(SRC_PATH) | grep .c$$)
OBJS		=	$(patsubst %.c, $(OBJ_PATH)%.o,$(SRCS)) 

LNAME		=	libft.a
LDIR		=	libft/
MLX_DIR		=	minilibx_macos/
MLX			=	libmlx.a
HEADER		=	-I./$(MLX_DIR) -I./includes -I./$(LDIR)includes
LIBS		=	-framework OpenGL -framework AppKit
FLAGS		=	-O3 -Wall -Wextra -Werror
NAME		=	scop

CC			=	gcc

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LDIR)
	@make -C $(MLX_DIR)
	@$(CC) $(FLAGS) $(HEADER) $(LDIR)$(LNAME) $(MLX_DIR)$(MLX) $(LIBS) $(OBJS) -o $(NAME)

$(patsubst %, $(OBJ_PATH)%,%.o): $(SRC_PATH)$(notdir %.c)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(FLAGS) $(HEADER) "$<" -o "$@"

clean:
	@make -C $(LDIR) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LDIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
