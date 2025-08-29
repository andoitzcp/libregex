#include "libregex.h"

void ft_exit(t_re *re, char *s)
{
    free(re);
    perror(s);
}

void get_charset(t_re *node, char *s)
{
    char *tmp;
    char *aux;

    tmp = ft_chrstrchr(s, '[', ']');
    if (*tmp == '^')
    {
        node->neg = 1;
        aux = ft_strdup(tmp + 1);
        free(tmp);
        tmp = NULL;
    }
}

char *expand_sequence(char *s)
{
    char c;
    char *e;
    uint8_t len;
    uint8_t i;

    if (!ft_isascii(s[0]) || ft_isascii(s[2]) || s[1] != '-')
        return (NULL);
    len = s[1] - s[0];
    if (len < 1)
        return (NULL);
    e = (char *)malloc(sizeof(char) * len + 1);
    if (!e)
        return (NULL);
    c = s[0];
    i = 0;
    while (i < len)
    {
        e[i] = c;
        i++;
        c++;
    }
    e[len] = '\0';
}

int get_int_in_brackets(char *s)
{
    size_t i;

    if (!s)
        return (0);
    if (*s != '{')
        return (0);
    i = 0;
    while (s[i] != '}')
    {
        if (s[i] == '\0')
            return (-1);
        if(!ft_isdigit(s[i]))
            return (-1);
    }
    if (i < 2)
        return (-1);
    return (ft_atoi(s + 1));

}

char *ft_chrstrchr(char *s, char a, char b)
{
    char *p;

    p = ft_strchr(s, a);
    if (p == NULL)
        return (NULL);
    while (1)
    {
        p = ft_strchr(s, b);
        if (p == NULL)
            return (NULL);
        if (*(p - 1) == '\\')
            continue;
        else
            break;
    }
    return (ft_strndup(s + 1, p - s));

}
