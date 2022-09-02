NAME := so_long.out

OBJS := main.c\


CFLAGS := -Wall -Wextra -Werror -Imlx -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L mlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all :
	$(MAKE) -C ./libft all
	cp ./libft/libft.a ./
	arch -x86_64 gcc -L ./mlx -lmlx -framework OpenGL -framework AppKit main.c libft.a so_long.c valid_map.c move.c

re :
	make fclean
	make all

clean :
	rm -f *.o
	rm -f libft/*.o

fclean : clean
	rm -f libft/libft.a
	rm -f $(NAME)

.PHONY : all clean fclean bonus re
