#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char    buffer[1024];
    int     i, x, y, z;

    fgets(buffer, sizeof(buffer), stdin);
    i = atoi(buffer);

    x = 0;
    while(x < i)
    {
        z = 0;
        while (z < i - x - 1)
            buffer[z++] = ' ';
        y = 0;
        while (y < (x + 1) * 2 - 1)
        {
            buffer[z++] = '*';
            y++;
        }
        buffer[z] = '\0';
        printf("%s\n",buffer);
        x++;
    }
    x--;
    while(--x >= 0)
    {
               z = 0;
        while (z < i - x - 1)
            buffer[z++] = ' ';
        y = 0;
        while (y < (x + 1) * 2 - 1)
        {
            buffer[z++] = '*';
            y++;
        }
        buffer[z] = '\0';
        printf("%s\n",buffer);
    }
}