#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
        int     x;
    int     a[6];
    char    buffer[1024];
    char    *token;
    fgets(buffer, sizeof(buffer), stdin);
    x = 0;
    token = strtok(buffer, " ");
    while (token != NULL) {
        if (x >= 6)
            exit(1);
        a[x] = atoi(token);
        if (a[x] < 0 || a[x] > 10)
            exit(1);
        token = strtok(NULL, " ");
        x++;
    }
    while (x < 6)
        a[x++] = 0;
    
    printf("%d ",1 - a[0]);
    printf("%d ",1 - a[1]);
    printf("%d ",2 - a[2]);
    printf("%d ",2 - a[3]);
    printf("%d ",2 - a[4]);
    printf("%d ",8 - a[5]);
}