NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(PATH)/get_next_line.c  $(PATH)/get_next_line_utils.c so_long.c $(PATH1)/ft_split.c $(PATH1)/ft_substr.c $(PATH1)/ft_strdup.c \
		 check_map.c  $(PATH1)/ft_strcmp.c  len_collectible.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

# .PHONY: all, clean, fclean, re, libmlx























#include "so_long.h"

#include <mlx.h>
void	delet_image_with_indices(t_game *vers , int a,  int b) 
{
    // int  i = 0;
    vers->len_colon = ft_strlen(vers->av[0]);
    vers->img = mlx_xpm_file_to_image(vers->img, "./image/uu/new.xpm", &vers->a, &vers->b);

    vers->len_img_x = vers->a * b;
    vers->len_img_y = vers->b * a;
    mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);

}

void	put_image_with_indices(t_game *vers , int a,  int b) 
{
    // int  i = 0;
    vers->len_colon = ft_strlen(vers->av[0]);
    vers->img = mlx_xpm_file_to_image(vers->img, "./image/uu/2.xpm", &vers->a, &vers->b);

    vers->len_img_x = vers->a * b;
    vers->len_img_y = vers->b * a;
    mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);

}






void direct_right(t_game *vers ,  int a ,  int b )
{
    // pos.pos_ply_y +=1;
    // b+=1;
    if(vers->av[a][b+1] == 'X')
    {
        b++;
        put_image_with_indices( vers ,   a,   b) ;
        b-=1;
        delet_image_with_indices(vers ,   a,   b) ;
    }
    // else    
    //     b-=1;
    b++;
}
void direct_left(t_game *vers ,  int a ,  int b )
{
    // pos.pos_ply_y -=1;
    b-=1;
    if(vers->av[a][b] == 'X')
    {
        put_image_with_indices( vers , a, b) ;
        b +=1;
        delet_image_with_indices(vers , a, b) ;
    }
    else    
        b+=1;
    b++;
}
int handle_key(int keycode, void *param)
{
    t_game *vers ;
    vers = param;
    t_game pos;
    pos  = position_player( *vers);

    static int a ;
    a = pos.pos_ply_x;
    static int b ;
    b = pos.pos_ply_y;

    printf("keycode: %d\n",keycode);
    if(keycode == 53 )
        exit(0);
    if(keycode == 2 )
    {
        direct_right(vers , a , b);
    }
     if(keycode == 0 )
    {
        direct_left(vers , a , b);
    }


    
    // int i=0;
    // while (i < 12)
    // {
    //     printf("-->> %s \n",vers->av[i]);
    //     i++;
    // }
    
    return 0;
}




// void moves_player(t_game *vers )
// {
//     (void) vers ;
// }