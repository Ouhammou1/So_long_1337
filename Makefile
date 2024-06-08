PATH=get_next_line
PATH1=libft

CC = cc 
MLX= -lmlx -framework OpenGL -framework AppKit
CFLAGS=-Wall -Wextra -Werror
CFILES= $(PATH)/get_next_line.c  $(PATH)/get_next_line_utils.c so_long.c $(PATH1)/ft_split.c $(PATH1)/ft_substr.c $(PATH1)/ft_strdup.c  ft_putstr.c  \
$(PATH1)/ft_putnbr.c  $(PATH1)/ft_putchar.c  check_map.c  $(PATH1)/ft_strcmp.c  len_collectible.c background_image.c check_move_plyer.c \
moves_player.c  direction_down.c direction_left.c  direction_right.c direction_up.c  

NAME = so_long.a
HEADER= so_long.h

object=$(CFILES:.c=.o)

output = so_long

all:$(output)

$(output): $(NAME) $(HEADER)
	$(CC) $(CFLAGS)  $(MLX) so_long.c $(NAME) -o $(output)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS)   -c $< -o $@

$(NAME):  $(object) 
	ar rcs $(NAME) $(object)

clean : 
	rm -rf $(object)

fclean: clean
	rm -rf $(NAME) $(output)
re : fclean all

