SRC = mandatory/lst_func.c mandatory/parse.c mandatory/push_swap.c mandatory/error_handeling.c \
		mandatory/rules.c \
		mandatory/lil_sort.c mandatory/utils.c \
		mandatory/chunks.c

BSRC = bonus/checker.c bonus/get_next_line_utils.c bonus/get_next_line.c \
		bonus/lst_func.c bonus/parse.c bonus/rules.c bonus/error_handeling.c

LBFTSRC = libft/ft_strlen.c libft/ft_split.c libft/ft_substr.c libft/ft_strdup.c \
			libft/ft_strlcpy.c libft/ft_isdigit.c

LBFTOBJ = $(LBFTSRC:.c=.o)
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CCFLAGS = cc -Wall -Wextra -Werror

NAME = push_swap

BNAME = checker


all : $(NAME)

bonus : $(BNAME)

$(NAME) : $(OBJ) $(LBFTOBJ)
	cc $(OBJ) $(LBFTOBJ) -o $(NAME)

$(BNAME) : $(BOBJ) $(LBFTOBJ)
	cc $(BOBJ) $(LBFTOBJ) -o $(BNAME)

libft/%.o : libft/%.c libft/libft.h
	$(CCFLAGS) -c $< -o $@

mandatory/%.o : mandatory/%.c mandatory/push_swap.h
	$(CCFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/checker.h
	$(CCFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(LBFTOBJ) $(BOBJ)

fclean : clean
	$(RM) $(NAME) $(BNAME)

re : fclean all