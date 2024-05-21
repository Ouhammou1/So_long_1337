#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../MLX42/include/MLX42/MLX42.h"




void    libriry_m_l_x(char **av, int count)
{


    (void) av;
    void *mlx;
    void *win;
    int i = 0;
    t_game new;

    new.len = ft_strlen(av[0]);
    mlx = mlx_init();
    new.img = mlx_xpm_file_to_image(mlx, "./collect.xpm", &new.a , &new.b);

    new.x_width = new.a * new.len;
    new.y_height = new.b * count;
    win = mlx_new_window(mlx, new.x_width ,new.y_height ,"SO_LOOOOONG");   


    new.len_img_x = 0;
    new.len_img_y = 0;
    while (i < count)
    {
        int j =0;
        while (av[i][j] != '\0')
        {
            if( av[i][j] == '1')
            {
                mlx_put_image_to_window(mlx, win, new.img, new.len_img_x , new.len_img_y);
            }
                new.len_img_x+=new.a;
            printf("j == %d   ----->>> new.len_img_x == %d  -->>>>>> new.len_img_y == %d \n", j,new.len_img_x , new.len_img_y);
            j++;
        }
        new.len_img_y+=new.b;
        new.len_img_x = 0;
        i++;
    }
    

    printf(" x = %d \n y = %d \n", new.a, new.b);
    mlx_loop(mlx) ;

}































// static void ft_hook(void* param)
// {
//     (void) param;
//     // const mlx_t* mlx = param;
//     // int i =0;
//     // while(i < 10000000)
//     // {
// 	//     printf("i == %d   --->>>> WIDTH: %d | HEIGHT: %d\n",i, mlx->width, mlx->height);
//     //     i++;
//     // }
// }
// int main()
// {
//     int  WIDTH = 900;
//     int  HEIGHT = 500;

//     void *mlx ;
//     void *win;
//     (void )win;

//     mlx = mlx_init(WIDTH, HEIGHT, "SO_LOONG", true);
//     mlx_image_t *img ;

//     img  = mlx_new_image(mlx, 256, 256);
//     mlx_put_pixel(img, 0, 0, 0xFF0000FF);
//     mlx_loop_hook(mlx, ft_hook, mlx);

//     mlx_loop(mlx);
//      mlx_terminate(mlx);

//     return 0;
// }



// int key_hook(int keycode, void *param)
// {
//     printf("Touche pressée: %d\n", keycode);
//     if (keycode == 65307) // 65307 est le code pour la touche Échap
//     {
//         exit(0);
//     }
//     return 0;
// }
// int key_hook(int keycode , void *param)
// {
//     printf("touche sur clavier est : %d \n",keycode);
//     if(keycode == 53)
//     {
//         exit(0);
//     }
//     return 0;
// }
// int main(int ac , char **av)
// {
//     void    *mlx;
//     void    *win;
//     int i =0;

//     mlx= mlx_init();
//     win = mlx_new_window(mlx,900,600,"SO_LONG");
//         mlx_string_put(mlx,win , 400 ,50,  0xFFFFFF ,"Appuyez sur ESC pour quitter");
//     while (i < 900)
//     {
//         mlx_pixel_put(mlx,win,i,90,0xFF0000);
//         mlx_pixel_put(mlx,win,90,i,0x0000FF);
//         mlx_key_hook(win , key_hook, NULL);
//        i++;
//     }
    
//     mlx_loop(mlx);

//     return 0;
// }



// int main(int ac, char **av)
// {

//     // printf("av --> %s\n", av[1]);
//     // char *mtr;
//     // char *str =get_line(0);
//     // int fd = open(av[1]);

//     void    *mlx;
//     void    *win;

//     int a;
//     int b;

//     mlx = mlx_init();
//     // win = mlx_new_window(mlx, 1200, 600, "test");
//     // void *img = mlx_xpm_file_to_image(mlx, "./collect.xpm", &a, &b);
//     // int i = 0;
//     // while (i < 1200)
//     // {
//     //     mlx_pixel_put(mlx, win, i, 200, 0xffffff);
//     //     i++;
//     // }
//     // mlx_put_image_to_window(mlx, win, img, 20, 200);
//     // printf("a = %d\n", a);
//     // printf("b = %d\n", b);
//     // mlx_loop(mlx);
//     return 0;
// }


// #include "mlx.h"

// int main(void)
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 800, 600, "Hello World");
//     mlx_pixel_put(mlx, win, 400, 300, 0xFF0000); // Rouge (Hexadécimal: 0xRRGGBB)
//     mlx_loop(mlx);
//     return (0);
// }
