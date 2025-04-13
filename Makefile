# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/12 15:32:36 by cade-oli          #+#    #+#              #
#    Updated: 2025/04/13 18:01:10 by cade-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	= make
SERVER	= server
CLIENT	= client

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#
SRC_PATH	= src
INC_PATH	= inc
LIBS_PATH	= lib
BUILD_PATH	= .build

LIBFT_PATH	= $(LIBS_PATH)/libft

SRC_SERVER	= $(addprefix $(SRC_PATH)/, server.c server_utils.c)
SRC_CLIENT	= $(addprefix $(SRC_PATH)/, client.c client_utils.c)

OBJS_SERVER	= $(patsubst $(SRC_PATH)/%.c,$(BUILD_PATH)/%.o,$(SRC_SERVER))
OBJS_CLIENT	= $(patsubst $(SRC_PATH)/%.c,$(BUILD_PATH)/%.o,$(SRC_CLIENT))

# DEPS = $(OBJS:.o=.d)

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror -g

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#
AR			= ar rcs
RM			= rm -rf
MKDIR_P		= mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

##@ minitalk Compilation Rules 🏗

all: deps $(SERVER) $(CLIENT)			## Compile All

$(SERVER): $(BUILD_PATH) $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT_PATH)/libft.a -I$(LIBFT_PATH) -o $(SERVER)

$(CLIENT): $(BUILD_PATH) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT_PATH)/libft.a -I$(LIBFT_PATH) -o $(CLIENT)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(BUILD_PATH) folder:$(D) $(_SUCCESS)"

deps: 			## Download/Update libft
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found $(YEL)🖔$(D)"; \
	fi
	@echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"

get_libft:		## Get Libft module
	@echo "* [$(CYA)Getting Libft$(D)]"
	git clone git@github.com:carolcortes/libft.git $(LIBFT_PATH)
	$(MAKE) extra -C $(LIBFT_PATH)
	@echo "* $(GRN)Libft submodule download$(D): $(_SUCCESS)"

##@ Clean-up Rules 󰃢

clean:
	$(RM) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME) $(LIBS_PATH) $(TEMP_PATH)

re: fclean all

help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(MAG)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(MAG)%-15s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#
# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)

