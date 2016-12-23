# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2015/04/29 20:13:26 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc_$(HOSTTYPE).so
LINKNAME	=	libft_malloc.so
CC			=	gcc -Wall -Werror -Wdeprecated-declarations -Wextra
LIB			=	-L libft/ -lft
INC			=	libft/includes/

CCO		=	gcc -shared -o
#CCO			=	gcc -o
FLAGS		=	-Wall -Werror -Wextra -fPIC -Wdeprecated-declarations
#FLAGS		=	-Wall -Werror -Wextra -Wdeprecated-declarations


C_FILES	=	free.c\
			malloc.c\
			realloc.c\
			util_malloc.c\
			mmap.c\
			mmap.c\
			m_tiny.c\
			m_small.c\
			m_large.c\
			rlimit.c\
			t_malloc_t.c t_malloc_z.c\
			show_alloc_mem.c\
			show_alloc_mem_ex.c\
			m_tree.c\
			m_tree_zone.c #main.c

O_FILES	=	free.o\
			malloc.o\
			realloc.o\
			util_malloc.o\
			mmap.o\
			m_tiny.o\
			m_small.o\
			m_large.o\
			rlimit.o\
			t_malloc_t.o t_malloc_z.o\
			show_alloc_mem.o\
			show_alloc_mem_ex.o\
			m_tree.o\
			m_tree_zone.o #main.o

all		: $(NAME)

$(NAME)	:
	@make -C libft/
	@$(CC) $(FLAGS) -c $(C_FILES) -I $(INC)
	@$(CCO) $(NAME) $(O_FILES) $(LIB)
	@ln -s $(NAME) $(LINKNAME)
	@cp $(NAME) test/

clean	:
	@make -C libft/ clean
	@/bin/rm -f $(O_FILES)

fclean	: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.so
	@/bin/rm -f test/*.so

re		: fclean all
