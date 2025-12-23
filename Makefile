# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

# ---- EXECUTABLE ---- #
NAME_CLIENT = client
NAME_SERVER = server

# ---- COLORS ---- #
RESET       = \033[0m
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# ---- COMPILATION ---- #
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I ./

# ---- DIRECTORIES ---- #
SRC_DIR = src

# ---- SOURCES ---- #
COMMON_SRC = ft_atoi.c ft_itoa.c ft_strlen.c verif_param.c
CLIENT_SRC = client.c
SERVER_SRC = server.c

# ---- OBJECT ---- #
COMMON_OBJ = $(addprefix $(SRC_DIR)/, $(COMMON_SRC:.c=.o))
CLIENT_OBJ = $(addprefix $(SRC_DIR)/, $(CLIENT_SRC:.c=.o))
SERVER_OBJ = $(addprefix $(SRC_DIR)/, $(SERVER_SRC:.c=.o))

# ---- RULES ---- #
all: $(NAME_CLIENT) $(NAME_SERVER) banner

banner :
	@echo "$(RED)___  ____       _  $(YELLOW)_____     _ _    "
	@echo "$(RED)|  \/  (_)     (_) $(YELLOW)_   _|   | | |   "
	@echo "$(RED)| .  . |_ _ __  _  $(YELLOW) | | ___ | | | __"
	@echo "$(RED)| |\/| | | |_ \| | $(YELLOW) | |/ _ || | |/ / "
	@echo "$(RED)| |  | | | | | | | $(YELLOW) | | ()_|| | |  < "
	@echo "$(RED)\_|  |_/_|_| |_|_| $(YELLOW) \_/\___||_|_|\_\ "

$(NAME_CLIENT): $(CLIENT_OBJ) $(COMMON_OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJ) $(COMMON_OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME_SERVER)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(COMMON_OBJ)

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re banner
