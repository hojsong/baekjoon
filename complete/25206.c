#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void    check_str(char **str, int i)
{
    int x;

    x = 0;
    while (x < i)
    {
        if (strcmp(str[x], str[i]) == 0)
            exit(1);
        x++;
    }
}

int is_pass(char *token)
{
    if (token[0] == 'P')
        return (1);
    return (0);
}

float   change_pint(char *token)
{
    if(token[0] == 'A')
    {
        if (token[1] == '+')
            return (4.5);
        else if (token[1] == '0')
            return (4.0);
    }
    else if(token[0] == 'B')
    {
        if (token[1] == '+')
            return (3.5);
        else if (token[1] == '0')
            return (3.0);
    }
    else if(token[0] == 'C')
    {
        if (token[1] == '+')
            return (2.5);
        else if (token[1] == '0')
            return (2.0);
    }
    else if(token[0] == 'D')
    {
        if (token[1] == '+')
            return (1.5);
        else if (token[1] == '0')
            return (1.0);
    }
    return 0;
}

float extrasum(float dest, int *count, char *token)
{
    float point;

    if(is_pass(token))
    {
        *count -= (int)dest;
        return 0;
    }
    point = change_pint(token);
    return (dest * point);
}

int main()
{
    int     x, i, count, len;
    float   dest;
    float   sum;
    char    *str[20];
    char    buffer[1024];
    char    *token;

    count = 0;
    i = 0;
    sum = 0;
    while (i < 20)
    {
        fgets(buffer, sizeof(buffer), stdin);
        x = 0;
        len = strlen(buffer);
        buffer[len - 1] = '\0';
        token = strtok(buffer, " ");
        while (token != NULL) 
        {
            if (x >= 3)
                exit(1);
            if (x == 0)
            {
                str[i] = strdup(token);
                check_str(str, i);
            }
            else if (x == 1)
            {
                dest = atof(token);
                count += (int)dest;
            }
            else if (x == 2)
                sum += extrasum(dest, &count, token);
            token = strtok(NULL, " ");
            x++;
        }
        i++;
    }
    if (count == 0)
        return (0);
    printf("%f", sum / (float)count);
    return (0);
}