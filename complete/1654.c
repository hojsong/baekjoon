#include <stdio.h>
#include <stdlib.h>

int main()
{
    int     i, a, b, *list, cnt, result;
    long long dest, dest2, dest3;
    scanf("%d %d", &a, &b);
    i = 0;
    dest3 = 0;
    list = malloc(sizeof(int) * a);
    while (i < a)
    {
        scanf("%d", &list[i]);
        if (dest3 < list[i])
            dest3 = list[i];
        i++;
    }
    dest2 = 1;
    result = 0;
    while (1)
    {
        i = 0;
        cnt = 0;
        dest = (dest3 + dest2) / 2;
        while (i < a)
        {
            cnt+= list[i] / dest;
            i++;
        }
        if (cnt< b)
            dest3 = dest - 1;
        else
        {
            if (result < dest)
                result = dest;
            dest2 = dest + 1;
        }
        if (dest2 > dest3)
            break;
    }
    free(list);
    printf("%d", result);
}
