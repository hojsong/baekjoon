#include <unistd.h>
#include <stdio.h>

int main()
{
    int min, max, i, j;
    int list[1000001] = {0, };

    scanf("%d %d", &min, &max);
    list[1] = 1;
    i = 1;
    while (++i <= max)
    {
        j = 1;
        while (++j * i <= max)
        {
            list[i * j] = 1;
        }
    }
    i = min;
    while (i <= max)
    {
        if (list[i] != 1)
            printf("%d\n", i);
        i++;
    }
    return (0);
}