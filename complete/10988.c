#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char    str[102];
    int     i, x;

    if(fgets(str, sizeof(str), stdin) == NULL)
        exit(0);
    i = 0;
    x = strlen(str);
    str[x - 1] = '\0';
    x--;
    while (i < x / 2)
    {
        if(str[i] != str[x - i - 1])
        {
            printf("0\n");
            exit(0);
        }
        i++;
    }
    printf("1\n");
}