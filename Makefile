NAME := so_long

OBJS := main.c\
		so_long.c\
		valid_map.c\
		move.c


CFLAGS := -Wall -Wextra -Werror -Imlx -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS)

all :
	@$(MAKE) -C ./libft all
	@cp ./libft/libft.a ./
	@arch -x86_64 gcc -L ./mlx -lmlx -framework OpenGL -framework AppKit main.c libft.a so_long.c valid_map.c move.c -o so_long

re :
	make fclean
	make all

clean :
	rm -f *.o
	rm -f libft/*.o

fclean : clean
	rm -f libft/libft.a
	rm -f libft.a
	rm -f $(NAME)

.PHONY : all clean fclean bonus re
