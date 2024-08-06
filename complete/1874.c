// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int max, *list, *dest, num, idx, idx2, ridx;
//     char    *result;
//     scanf("%d", &max);
//     num = 0;
//     list = malloc(sizeof(int) * max);
//     dest = malloc(sizeof(int) * max);
//     result = malloc(sizeof(char) * (max * 2 + 1));
//     while (num < max)
//     {
//         scanf("%d", &list[num++]);
//     }
//     num = 1;
//     idx = 0;
//     idx2 = 0;
//     ridx = 0;
//     while (1)
//     {
//         if (idx == 0 || list[idx2] > dest[idx - 1])
//         {
//             dest[idx] = num++;
//             idx++;
//             result[ridx++] = '+';
//         }
//         else if (list[idx2] == dest[idx - 1])
//         {
//             idx2++;
//             result[ridx++] = '-';
//             idx--;
//         }
//         else
//         {
//             printf("NO\n");
//             return (1);
//         }
//         if (ridx >= 2 * max)
//             break;
//     }
//     result[ridx] = '\0';
//     idx = 0;
//     while(idx < ridx)
//         printf("%c\n", result[idx++]);
//     return (0);
// }

#include <stdio.h>
#include <stdlib.h>

int push(char *result, int *list, int *dest, int *i, int *x, int y)
{
    dest[*x] = list[*i];
    result[*i + y] = '+';
    *i += 1;
    *x += 1;
    return (1);
}

int pop(char *result, int *dest2, int *dest, int *x, int *y, int i)
{
    dest2[*y] = dest[*x - 1];
    dest[*x - 1] = 0;
    result[i + *y] = '-';
    *x -= 1;
    *y += 1;
    return (1);
}

int dfs(char *result, int *list, int *dest, int *dest2, int *list2, int *i, int *x, int *y, int a)
{
    int re;
    int d;

    d = 0;
    if (*x > 0 && list2[*y] == dest[*x - 1])
        d = pop(result, dest2, dest, x, y, *i);
    else if (*i < a)
        d = push(result, list, dest, i, x, *y);
    return (d);
}

int main()
{
    int     a, *list, *list2, *dest, *dest2;
    char    *result;
    scanf("%d", &a);

    list = malloc(sizeof(int) * a);
    list2 = malloc(sizeof(int) * a);
    dest = malloc(sizeof(int) * a);
    dest2 = malloc(sizeof(int) * a);
    result = malloc(sizeof(char) * ((a * 2) + 1));
    result[2 * a] = '\0';
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &list2[i]);
        list[i] = i + 1;
    }

    int i, x, y;
    i = 0;
    x = 0;
    y = 0;
    while(1)
    {
        if (dfs(result, list, dest, dest2, list2, &i, &x, &y, a) == 0)
            break;
    }
    if(i + y == a * 2)
    {
        i = 0;
        while (i < a * 2)
            printf("%c\n",result[i++]);
    }
    else
        printf("NO\n");
    return (0);
}