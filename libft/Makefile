# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 23:03:18 by ayagoumi          #+#    #+#              #
#    Updated: 2019/03/31 21:47:39 by ayagoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean :
	rm -rf *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
