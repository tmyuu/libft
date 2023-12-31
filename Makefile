# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:33:15 by ymatsui           #+#    #+#              #
#    Updated: 2023/12/04 12:20:16 by ymatsui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS = $(SRCS:.c=.o)
OBJB = $(BONUS:.c=.o)
ifdef BONUS_FLAG
	OBJS += $(OBJB)
endif

all: $(NAME)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Creating archive $(NAME)"
	@ar rcs $(NAME) $(OBJS)

clean:
	@echo "Cleaning mandatory object files..."
	@for obj in $(OBJS); do \
		if [ -f $$obj ]; then \
			echo "Cleaning $$obj"; \
			/bin/rm -f $$obj; \
		else \
			echo "$$obj is already cleaned"; \
		fi \
	done
	@echo "Cleaning bonus object files..."
	@for obj in $(OBJB); do \
		if [ -f $$obj ]; then \
			echo "Cleaning $$obj"; \
			/bin/rm -f $$obj; \
		else \
			echo "$$obj is already cleaned"; \
		fi \
	done

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "Cleaning $(NAME)"; \
		/bin/rm -f $(NAME); \
	else \
		echo "$(NAME) is already cleaned"; \
	fi

re:
	@$(MAKE) fclean all

bonus:
	@echo "Making bonus files"
	@make BONUS_FLAG=1 all

.PHONY: all clean fclean re bonus
