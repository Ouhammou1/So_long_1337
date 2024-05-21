#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <mlx.h>
#include <stdlib.h>


// Function to handle key events
int handle_key(int key, void *param)
{
    printf("------>>>>> %d \n", key);
    if (key == 53)  // Escape key
        exit(0);
    return 0;
}

// Function to draw shapes using while loops
void draw_shapes(void *mlx, void *win)
{
    int x, y;

    // Draw a white line
    x = 100;
    while (x < 700)
    {
        mlx_pixel_put(mlx, win, x, 300, 0xFFFFFF);
        x++;
    }

    // Draw a red rectangle
    y = 100;
    while (y < 200)
    {
        x = 200;
        while (x < 400)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFF0000);
            x++;
        }
        y++;
    }

    // Draw a green rectangle
    y = 400;
    while (y < 500)
    {
        x = 300;
        while (x < 500)
        {
            mlx_pixel_put(mlx, win, x, y, 0x00FF00);
            x++;
        }
        y++;
    }
}

int main()
{
    void *mlx;
    void *win;

    // Initialize MiniLibX
    mlx = mlx_init();
    
    // Create a new window
    win = mlx_new_window(mlx, 800, 600, "MiniLibX Example");

    // Draw shapes in the window
    draw_shapes(mlx, win);

    // Set up key event handling
    mlx_key_hook(win, handle_key, NULL);

    // Enter the event loop to keep the window open
    mlx_loop(mlx);

    return 0;
}
