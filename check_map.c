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
        while (vers->av[i][j])
        {
            if (vers->av[i][j] != '1' && vers->av[i][j] != '0' && vers->av[i][j] != 'P' && vers->av[i][j] != 'E' && vers->av[i][j] != 'C')
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
        while (vers->av[i][j])
        {
            if(vers->av[i][j] == 'P')
                p++;
            if(vers->av[i][j] == 'E')
                e++;
        j++;
        }
        i++;
    }
    if(p != 1 || e != 1)
    {
        printf("Error deplcat E or P\n");
        exit(0);
    }
}

void    chack_wall(t_game *vers )
{
    int i;
    int j;
    vers->len_colon = ft_strlen(vers->av[0]) -1;
    i =0;
    j=0;
    while (vers->av[i][j])
    {
        if (vers->av[i][j] != '1' || vers->av[vers->count_len -1][j] != '1')
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
        if (vers->av[i][j] != '1' || vers->av[i][vers->len_colon] != '1')
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

    vers->len_colon = ft_strlen(vers->av[0]);
    i = 0;
    while (i < vers->count_len)
    {
        if(vers->len_colon != ft_strlen(vers->av[i]) )
        {
            printf("Error ->> length\n");
            exit(0);
        }
        vers->len_colon = ft_strlen(vers->av[i]);
        i++;
    }

    return ;
}