NAME_CLIENT			= client
NAME_SERVER			= server
NAME_CLIENT_BONUS	= client_bonus
NAME_SERVER_BONUS	= server_bonus

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

SRC_DIR_BONUS			= ./bonus/src/
SRC_CLIENT_BONUS		= client_bonus.c
SRC_CLIENT_PATH_BONUS	= $(addprefix $(SRC_DIR_BONUS), $(SRC_CLIENT_BONUS))
SRC_SERVER_BONUS		= server_bonus.c
SRC_SERVER_PATH_BONUS	= $(addprefix $(SRC_DIR_BONUS), $(SRC_SERVER_BONUS))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

BIN						= ./bin/
BINARY_OUT_CLIENT		= $(addprefix $(BIN), $(NAME_CLIENT))
BINARY_OUT_SERVER		= $(addprefix $(BIN), $(NAME_SERVER))

BIN_BONUS				= ./bonus/bin/
BINARY_OUT_CLIENT_BONUS	= $(addprefix $(BIN_BONUS), $(NAME_CLIENT_BONUS))
BINARY_OUT_SERVER_BONUS	= $(addprefix $(BIN_BONUS), $(NAME_SERVER_BONUS))

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
	@ rm -f $(BINARY_OUT_CLIENT_BONUS) $(BINARY_OUT_SERVER_BONUS)
	@ rm -rf $(BIN_BONUS)
	@ echo "$(NAME_CLIENT_BONUS) binaries erased successfully!"
	@ echo "$(NAME_SERVER_BONUS) binaries erased successfully!"

bonus: $(BINARY_OUT_CLIENT_BONUS) $(BINARY_OUT_SERVER_BONUS)

$(BINARY_OUT_CLIENT_BONUS): $(SRC_CLIENT_PATH_BONUS)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_CLIENT_BONUS)
	@ mkdir -p $(BIN_BONUS)
	@ $(CC) $(CFLAGS) $(SRC_CLIENT_PATH_BONUS) -I $(HEADER_DIR_BONUS) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -o $(NAME_CLIENT_BONUS)
	@ mv $(NAME_CLIENT_BONUS) $(BIN_BONUS)
	@ echo "$(NAME_CLIENT_BONUS) compiled successfully!"

$(BINARY_OUT_SERVER_BONUS): $(SRC_SERVER_PATH_BONUS)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_SERVER_BONUS)
	@ mkdir -p $(BIN_BONUS)
	@ $(CC) $(CFLAGS) $(SRC_SERVER_PATH_BONUS) -I $(HEADER_DIR_BONUS) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -o $(NAME_SERVER_BONUS)
	@ mv $(NAME_SERVER_BONUS) $(BIN_BONUS)
	@ echo "$(NAME_SERVER_BONUS) compiled successfully!"

re: fclean all

.PHONY: all clean fclean re
