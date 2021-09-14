# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juasanto <juasanto>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 10:44:34 by juasanto          #+#    #+#              #
#    Updated: 2021/09/09 17:25:18 by jcsantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test norm

#VPATH = %.o obj
#VPATH = %.c sources

NAME 		=	pipex
LIB_DIR		=	libft/
SRCS_DIR	=	sources/
OBJ_DIR		=	obj/
SRCS		=	pipex.c \
				pipex_util1.c \
				pipex_util2.c \
				pipex_util3.c \
				pipex_util4.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

LFLAGS = -I includes/
SNAITI =  -fsanitize=address -fno-omit-frame-pointer -O1
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
RM = rm -rf
AR = ar rc
RANLIB = ranlib
NORM = /usr/local/bin/norminette

RESET	= \033[0m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
PINK	= \033[35m
CYAN	= \033[36m



all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		@mkdir -p $(OBJ_DIR)
		gcc -c $(CFLAGS) $(LFLAGS) $< -o $@

$(NAME): $(OBJS)
		@echo "$(YELLOW)=========== Compilando $(NAME) ==========="
		$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS)
		@echo "=========== DONE ==========$(RESET)"

clean:
		@echo "$(PINK)========== CLEAN =========="
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		@echo "$(PINK)=========== DONE ===========$(RESET)"

fclean: clean
		@echo "$(RED)========== FCLEAN =========="
		$(RM) $(NAME)
		@echo "$(RED)=========== DONE ===========$(RESET)"

re: fclean all

norm: all
		$(NORM) $(SRC);

