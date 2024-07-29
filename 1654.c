#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int     x, sum, a[2], list[10001], max, dest, dest2, dest3, result, d;
    char    str[1024];
    char    *token;
    scanf("%d %d", &a[0], &a[1]);
    x = 0;
    max = 0;
    while (x < a[0])
    {
        scanf("%d", &list[x]);
        if (max < list[x])
            max = list[x];
        // sum += list[x];
        x++;
    }
    dest2 = 1;
    dest3 = max;
    // d = 0;
    while (1)
    {
        // d++;
        dest = (dest3 + dest2) / 2;
        result = 0;
        x = 0;
        while (x < a[0])
        {
            result += list[x] / dest;
            x++;
        }
        if (result == a[1] && dest3 - dest <= 1)
            break;
        if (result < a[1])
            dest3 = dest - 1;
        else
            dest2 = dest + 1;
    }
    printf("%d\n", dest);
    // printf("%d %d\n", d, dest);
}
