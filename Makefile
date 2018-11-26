# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchancri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:09:40 by lchancri          #+#    #+#              #
#    Updated: 2018/05/09 21:45:02 by lchancri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	lem-in

LIB		=	libft/libft.a

FLAG	=	-Wall -Wextra -Werror

#------------------------------------------------------------------------------#
#-----------------------------------C_FILE-------------------------------------#
#------------------------------------------------------------------------------#

C_PATH	=	lem_in_src

C_FILE	=	lem_in.c\
			lem_in_tools.c\
			lem_in_tools2.c\
			algo.c\
			algo_tools.c\
			algo_tools2.c\
			fourmi.c\
			fourmi_tools.c\
			fourmi_tools2.c\
			fourmi_tools3.c\
			ft_parsing.c\
			ft_parsing2.c\
			ft_check_line.c\
			ft_tools.c\
			ft_tools2.c\
			ft_tools3.c\
			bonus.c\
			bonusbis.c\
			ft_putstri.c\
			ft_strjoinfree.c\

C_SRC	=	$(addprefix $(C_PATH)/, $(C_FILE))

#------------------------------------------------------------------------------#
#-----------------------------------O_FILE-------------------------------------#
#------------------------------------------------------------------------------#

O_PATH	=	lem_in_obj

O_FILE	=	$(C_FILE:.c=.o)

O_SRC	=	$(addprefix $(O_PATH)/, $(O_FILE))

#------------------------------------------------------------------------------#
#-----------------------------------INCLUDE------------------------------------#
#------------------------------------------------------------------------------#

I_PATH	=	include

I_FILE	=	lem_in.h\

I_SRC	=	$(addprefix $(I_PATH)/, $(I_FILE))

#------------------------------------------------------------------------------#
#-----------------------------------REGLE--------------------------------------#
#------------------------------------------------------------------------------#

all: $(LIB) $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(O_PATH) $(O_SRC)
	@gcc $(FLAG) -o $(NAME) $(O_SRC) $(LIB)

$(O_PATH):
	@mkdir -p $(O_PATH)

$(addprefix $(O_PATH)/, %.o): $(addprefix $(C_PATH)/, %.c) $(I_PATH)
	gcc $(FLAG) -Iinclude -o $@ -c $<

clean:
	@rm -Rf $(O_SRC)
	@make clean -C libft
	@rm -Rf $(O_PATH) 2>/dev/null || true

fclean: clean
	@make fclean -C libft
	@rm -Rf $(NAME)

re: fclean all

.PHONY: clean fclean re all $(LIB)
