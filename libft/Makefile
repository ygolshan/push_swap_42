# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 16:27:58 by ygolshan          #+#    #+#              #
#    Updated: 2023/04/28 15:42:07 by ygolshan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

MANDATORY_SRCS = ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c  ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
					ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
					ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c\
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

M_OBJS = $(MANDATORY_SRCS:.c=.o)

LIBCR   = ar -rc
CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror -g

all: $(NAME)

.c.o: 
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME): $(M_OBJS)
	@$(LIBCR) $(NAME) $(M_OBJS)
	
clean:
	@$(RM)

fclean: clean
		@$(RM) $(NAME)

re: fclean  all

