#include "so_long.h"
void    check_fil_name(char *s)
{
    int i =0;

    while (s[i])
    {
        if (s[i] == '.')
        {
            i++;
            break;
        }
        i++;
    }
    if(ft_strcmp(s+i,"ber") != 0)
    {
        printf("Error File Name : \n");
        exit(0);
    }
    
}
void    check_caracteres(t_game *vers )
{
    int i;
    int j;

    i=0;
    while ( i <  vers->count_len)
    {
        j=0;
        while (vers->map[i][j])
        {
            if (vers->map[i][j] != '1' && vers->map[i][j] != '0' && vers->map[i][j] != 'P' && vers->map[i][j] != 'E' && vers->map[i][j] != 'C')
            {
                printf("Error -->>  duplicates characters\n");
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void    check_duplcat_char(t_game *vers )
{
    int i ;
    int j ;
    int p ;
    int e;
    i =0;
    e =0;
    p =0;
    while ( i < vers->count_len)
    {
        j =0;
        while (vers->map[i][j])
        {
            if(vers->map[i][j] == 'P')
                p++;
            if(vers->map[i][j] == 'E')
                e++;
        j++;
        }
        i++;
    }
    if(p != 1 || e != 1)
    {
        printf("Error deplicat E or P\n");
        exit(0);
    }
}

void    chack_wall(t_game *vers )
{
    int i;
    int j;
    vers->len_colon = ft_strlen(vers->map[0]) -1;
    i =0;
    j=0;
    while (vers->map[i][j])
    {
        if (vers->map[i][j] != '1' || vers->map[vers->count_len - 1][j] != '1')
        {
            printf("Error ->> Wall ->> Line\n");
            exit(0);
        }
        j++; 
    }
    i=0;
    j=0;
    while (i < vers->count_len)
    {
        if (vers->map[i][j] != '1' || vers->map[i][vers->len_colon] != '1')
        {
            printf("Error ->> Wall ->> Colone  \n");
            exit(0);
        }
        i++; 
    }
}
    

void check_length(t_game *vers )
{
    int i;

    vers->len_colon = ft_strlen(vers->map[0]);
    i = 0;
    while (i < vers->count_len)
    {
        if(vers->len_colon != ft_strlen(vers->map[i]) )
        {
            printf("Error ->> length\n");
            exit(0);
        }
        vers->len_colon = ft_strlen(vers->map[i]);
        i++;
    }

    return ;
}