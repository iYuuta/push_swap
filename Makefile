SRC = mandatory/lst_func.c mandatory/parse.c mandatory/push_swap.c \
		mandatory/push_to_a.c mandatory/push_to_b.c mandatory/rules.c \
		mandatory/sort_10_5_3.c mandatory/sort_biggie.c mandatory/utils.c

LBFTSRC = libft/ft_strlen.c libft/ft_split.c libft/ft_substr.c libft/ft_strdup.c \
			libft/ft_strlcpy.c libft/ft_atoi.c

LBFTOBJ = $(LBFTSRC:.c=.o)
OBJ = $(SRC:.c=.o)

CCFLAGS = cc -Wall -Wextra -Werror

NAME = push_swap


all : $(NAME)

$(NAME) : $(OBJ) $(LBFTOBJ)
	cc $(OBJ) $(LBFTOBJ) -o $(NAME)

libft/%.o : libft/%.c libft/libft.h
	$(CCFLAGS) -c $< -o $@

mandatory/%.o : mandatory/%.c push_swap.h
	$(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(LBFTOBJ)

fclean : clean
	rm $(NAME)

re : fclean all