#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int is_cro(char *str, int i)
{
    if (str[i] == 'c')
    {
        if (str[i + 1] == '=' || str[i + 1] == '-')
            return (2);
    }
    else if (str[i] == 'd')
    {
        if (str[i + 1] == '-')
            return (2);
        else if (str[i + 1] == 'z' && str[i + 2] == '=')
            return (3);
    }
    else if (str[i + 1] == 'j')
    {
        if (str[i] == 'l' || str[i] == 'n')
            return (2);
    }
    else if (str [i + 1] == '=')
    {
        if (str[i] == 's' || str[i] == 'z')
            return (2);
    }
    return (0);
}



int main()
{
    char    str[102];
    int     i, x, y, result;

    if(fgets(str, sizeof(str), stdin) == NULL)
        exit(0);
    i = 0;
    x = strlen(str);
    str[x - 1] = '\0';
    x--;
    result = 0;
    while (i < x)
    {
        y = is_cro(str, i);
        if (y)
        {
            i += y;
        }
        else
            i++;
        result++;
    }
    printf("%d\n", result);    
}