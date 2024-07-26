#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int is_grup_str(char *str)
{
    int    alpha[26], i;

    i = 0;
    while (i < 26)
        alpha[i++] = 0;
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        if(alpha[str[i] - 'a'] == 0)
            alpha[str[i] - 'a'] = 1;
        else if (str[i] == str[i - 1])
            alpha[str[i] - 'a'] = 1;
        else
            return (0);
        i++;
    }
    return (1);
}

int main()
{
    char    str[1024];
    int     i, x, result;

    if(fgets(str, sizeof(str), stdin) == NULL)
        exit(0);
    i = 0;
    x = atoi(str);
    result = 0;
    while (i < x)
    {
        if(fgets(str, sizeof(str), stdin) == NULL)
            exit(0);
        result += is_grup_str(str);
        i++;
    }
    printf("%d\n", result);
}