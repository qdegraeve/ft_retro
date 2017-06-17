# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mressier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/12 11:36:38 by mressier          #+#    #+#              #
#    Updated: 2017/06/17 09:41:12 by mressier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_retro

FLAGS = -Wall -Wextra -Werror
INCLUDES= -I includes/ -lncurses

CPP_DIR=sources

O_DIR = .tmp/

### TO COMPLETE ###

CORE = main.cpp
SRC_CORE = $(addprefix $(CPP_DIR)/, $(CORE))

### END ###

CPP_SRC= $(SRC_CORE)


O_FILES = $(CPP_SRC:%.cpp=$(O_DIR)%.o)

all: prepare $(NAME)

prepare:
	@mkdir -p $(O_DIR)
	@mkdir -p $(O_DIR)$(CPP_DIR)

$(O_DIR)%.o: %.cpp
	@printf "[\033[32;1m $(NAME) \033[0m]\t\033[31;1m$<\033[0m\\n"
	@clang++ $(FLAGS) -o $@ -c $<

$(NAME): $(O_FILES)
	@clang++ $(FLAGS) -o $(NAME) $(O_FILES)
	@printf "[\033[32;1m Run \033[0m]\033[31;1m $(NAME) \033[0m\\n"

clean:
	@rm -rf $(O_DIR)
	@printf "[\033[32;1m Delete \033[0m] $(O_FILES) \033[0m\\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[\033[32;1m Delete \033[0m] $(NAME) \033[0m\\n"

re: fclean all
