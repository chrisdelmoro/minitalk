NAME_CLIENT		= client
NAME_SERVER		= server
NAME_BONUS		= minitalk_bonus

LIBFT_DIR		= ./libs/libft/
LIBFT 			= $(LIBFT_DIR)/libft.a
HEADER_LIBFT	= $(addprefix $(LIBFT_DIR), include/)

HEADER_DIR		= ./include/
HEADER			= minitalk.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR_BONUS	= ./bonus/include/
HEADER_BONUS		= minitalk_bonus.h
HEADER_PATH			= $(addprefix $(HEADER_DIR_BONUS), $(HEADER_BONUS))

SRC_DIR			= ./src/
SRC_CLIENT		= client.c
SRC_CLIENT_PATH	= $(addprefix $(SRC_DIR), $(SRC_CLIENT))
SRC_SERVER		= server.c
SRC_SERVER_PATH	= $(addprefix $(SRC_DIR), $(SRC_SERVER))

SRC_DIR_BONUS	= ./bonus/src/
SRC_BONUS		=	client_bonus.c \
					server_bonus.c
SRC_PATH_BONUS	= $(addprefix $(SRC_DIR_BONUS), $(SRC_BONUS))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

BIN						= ./bin/
BINARY_OUT_CLIENT		= $(addprefix $(BIN), $(NAME_CLIENT))
BINARY_OUT_SERVER		= $(addprefix $(BIN), $(NAME_SERVER))

BIN_BONUS			= ./bonus/bin/
BINARY_OUT_BONUS	= $(addprefix $(BIN_BONUS), $(NAME_BONUS))

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

all: $(BINARY_OUT_CLIENT) $(BINARY_OUT_SERVER)

$(BINARY_OUT_CLIENT): $(SRC_CLIENT_PATH)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_CLIENT)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_CLIENT_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -o $(NAME_CLIENT)
	@ mv $(NAME_CLIENT) $(BIN)
	@ echo "$(NAME_CLIENT) compiled successfully!"

$(BINARY_OUT_SERVER): $(SRC_SERVER_PATH)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_SERVER)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_SERVER_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -o $(NAME_SERVER)
	@ mv $(NAME_SERVER) $(BIN)
	@ echo "$(NAME_SERVER) compiled successfully!"

clean:
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ echo "libft object files erased successfully!"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ rm -f $(BINARY_OUT_CLIENT) $(BINARY_OUT_SERVER)
	@ rm -rf $(BIN)
	@ echo "$(NAME_CLIENT) binaries erased successfully!"
	@ echo "$(NAME_SERVER) binaries erased successfully!"
	@ rm -f $(BINARY_OUT_BONUS)
	@ rm -rf $(BIN_BONUS)
	@ echo "$(NAME_BONUS) binaries erased successfully!"

bonus: $(BINARY_OUT_BONUS)

$(BINARY_OUT_BONUS): $(SRC_PATH_BONUS)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_BONUS)
	@ mkdir -p $(BIN_BONUS)
	@ $(CC) $(CFLAGS) $(SRC_PATH_BONUS) -I $(HEADER_DIR_BONUS) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -o $(NAME_BONUS)
	@ mv $(NAME_BONUS) $(BIN_BONUS)
	@ echo "$(NAME_BONUS) compiled successfully!"

valgrind:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -g -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

valgrind_bonus:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_BONUS)
	@ mkdir -p $(BIN_BONUS)
	@ $(CC) $(CFLAGS) $(SRC_PATH_BONUS) -I $(HEADER_DIR_BONUS) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -g -o $(NAME_BONUS)
	@ mv $(NAME_BONUS) $(BIN_BONUS)
	@ echo "$(NAME_BONUS) compiled successfully!"

re: fclean all

.PHONY: all clean fclean re
