# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 13:22:33 by vluo              #+#    #+#              #
#    Updated: 2025/06/10 16:42:27 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	cub3d

SRC_DIR			=	parsing/

OBJ_DIR			=	obj/

INC				=	includes/

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

MINILIBFLAGS	=	-Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

RED				=	\e[31m

BLUE			=	\e[34m

RESET			=	\e[0m

SRC				=	$(SRC_DIR)parse_arg.c $(SRC_DIR)parse_color.c $(SRC_DIR)stock_file.c $(SRC_DIR)error.c $(SRC_DIR)utils.c $(SRC_DIR)main.c $(SRC_DIR)parse_color_01.c $(SRC_DIR)print_list.c $(SRC_DIR)init_data.c	\

OBJ				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

LIBFT			=	libft/libft.a

all				:	$(NAME)

$(LIBFT)		:
					$(MAKE) -C libft --no-print-directory

$(NAME)			:	$(LIBFT) $(OBJ_DIR) $(OBJ)
					@$(CC) $(CFLAGS) -I $(INC) $(OBJ) $(LIBFT) -o $(NAME)
					@clear
					@echo "Compilation Done"
					@echo ""
					@echo "........                                                                         ........"
					@echo ""
					@echo ""
					@echo ""
					@echo "........                                  mcauchy-                               ........"
					@echo "........                                   vluo                                  ........"
					@echo ""

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
					@echo "$(BLUE)minishell $(RESET): \e[92mCompiling\e[m $(notdir $<)...\n"

clean			:
					@$(MAKE) clean -C libft --no-print-directory
					@rm -rf $(OBJ_DIR)
					@echo "$(RED)- Objects deleted !$(RESET)"

fclean			:	clean
					@$(MAKE) fclean -C libft --no-print-directory
					@rm -rf $(NAME)
					@echo "$(RED)- Executable deleted !$(RESET)"

re				:	fclean
					@make all --no-print-directory

.PHONY			:	all clean fclean re