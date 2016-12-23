# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2014/09/09 10:19:28 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libft.a
CC		=	gcc
ARRC	=	ar rc
RANLIB	=	ranlib
FLAGS	=	-Wall -Werror -Wextra -c
INC		=	includes/

C_FILES	= ft_atoi.c
C_FILES	+= ft_error.c
C_FILES	+= ft_bzero.c
C_FILES	+= ft_isalpha.c
C_FILES	+= ft_isalnum.c
C_FILES	+= ft_isascii.c
C_FILES	+= ft_isdigit.c
C_FILES	+= ft_isprint.c
C_FILES	+= ft_memccpy.c
C_FILES	+= ft_memchr.c
C_FILES	+= ft_memcmp.c
C_FILES	+= ft_memcpy.c
C_FILES	+= ft_memmove.c
C_FILES	+= ft_memset.c
C_FILES	+= ft_putchar.c
C_FILES	+= ft_putstr.c
C_FILES	+= ft_strcat.c
C_FILES	+= ft_strchr.c
C_FILES	+= ft_strcmp.c
C_FILES	+= ft_strcpy.c
C_FILES	+= ft_strdup.c
C_FILES	+= ft_strlcat.c
C_FILES	+= ft_strlen.c
C_FILES	+= ft_strncat.c
C_FILES	+= ft_strncmp.c
C_FILES	+= ft_strncpy.c
C_FILES	+= ft_strnstr.c
C_FILES	+= ft_strrchr.c
C_FILES	+= ft_strstr.c
C_FILES	+= ft_tolower.c
C_FILES	+= ft_toupper.c

C_FILES	+= ft_memalloc.c
C_FILES	+= ft_memdel.c
C_FILES	+= ft_strnew.c
C_FILES	+= ft_strdel.c
C_FILES	+= ft_strclr.c
C_FILES	+= ft_striter.c
C_FILES	+= ft_striteri.c
C_FILES	+= ft_strmap.c
C_FILES	+= ft_strmapi.c
C_FILES	+= ft_strequ.c
C_FILES	+= ft_strnequ.c
C_FILES	+= ft_strsub.c
C_FILES	+= ft_strjoin.c
C_FILES	+= ft_strtrim.c
C_FILES	+= ft_strsplit.c
C_FILES	+= ft_itoa.c
C_FILES	+= ft_putendl.c
C_FILES	+= ft_putnbr.c
C_FILES	+= ft_putchar_fd.c
C_FILES	+= ft_putstr_fd.c
C_FILES	+= ft_putendl_fd.c
C_FILES	+= ft_putnbr_fd.c

C_FILES	+= ft_lstnew.c
C_FILES	+= ft_lstdelone.c
C_FILES	+= ft_lstdel.c
C_FILES	+= ft_lstadd.c
C_FILES	+= ft_lstiter.c
C_FILES	+= ft_lstmap.c
C_FILES += ft_pow.c
C_FILES += ft_sqrt.c
C_FILES += ft_strrev.c

O_FILES	= ft_atoi.o
O_FILES	+= ft_error.o
O_FILES	+= ft_bzero.o
O_FILES	+= ft_isalpha.o
O_FILES	+= ft_isalnum.o
O_FILES	+= ft_isascii.o
O_FILES	+= ft_isdigit.o
O_FILES	+= ft_isprint.o
O_FILES	+= ft_memccpy.o
O_FILES	+= ft_memchr.o
O_FILES	+= ft_memcmp.o
O_FILES	+= ft_memcpy.o
O_FILES	+= ft_memmove.o
O_FILES	+= ft_memset.o
O_FILES	+= ft_putchar.o
O_FILES	+= ft_putstr.o
O_FILES	+= ft_strcat.o
O_FILES	+= ft_strchr.o
O_FILES	+= ft_strcmp.o
O_FILES	+= ft_strcpy.o
O_FILES	+= ft_strdup.o
O_FILES	+= ft_strlcat.o
O_FILES	+= ft_strlen.o
O_FILES	+= ft_strncat.o
O_FILES	+= ft_strncmp.o
O_FILES	+= ft_strncpy.o
O_FILES	+= ft_strnstr.o
O_FILES	+= ft_strrchr.o
O_FILES	+= ft_strstr.o
O_FILES	+= ft_tolower.o
O_FILES	+= ft_toupper.o

O_FILES	+= ft_memalloc.o
O_FILES	+= ft_memdel.o
O_FILES	+= ft_strnew.o
O_FILES	+= ft_strdel.o
O_FILES	+= ft_strclr.o
O_FILES	+= ft_striter.o
O_FILES	+= ft_striteri.o
O_FILES	+= ft_strmap.o
O_FILES	+= ft_strmapi.o
O_FILES	+= ft_strequ.o
O_FILES	+= ft_strnequ.o
O_FILES	+= ft_strsub.o
O_FILES	+= ft_strjoin.o
O_FILES	+= ft_strtrim.o
O_FILES	+= ft_strsplit.o
O_FILES	+= ft_itoa.o
O_FILES	+= ft_putendl.o
O_FILES	+= ft_putnbr.o
O_FILES	+= ft_putchar_fd.o
O_FILES	+= ft_putstr_fd.o
O_FILES	+= ft_putendl_fd.o
O_FILES	+= ft_putnbr_fd.o

O_FILES	+= ft_lstnew.o
O_FILES	+= ft_lstdelone.o
O_FILES	+= ft_lstdel.o
O_FILES	+= ft_lstadd.o
O_FILES	+= ft_lstiter.o
O_FILES	+= ft_lstmap.o
O_FILES += ft_pow.o
O_FILES += ft_sqrt.o
O_FILES += ft_strrev.o

all		: $(NAME)

$(NAME)	:
	@$(CC) $(FLAGS) $(C_FILES) -I $(INC)
	@$(ARRC) $(NAME) $(O_FILES)
	@$(RANLIB) $(NAME)

clean	:
	@/bin/rm -f $(O_FILES)

fclean	: clean
	@/bin/rm -f $(NAME)

re		: fclean all
