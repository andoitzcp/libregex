#include "libregex.h"

void ft_exit(t_re **head, char *s)
{
    t_re *node;
    t_re *p;

    node = *head;
    while (node != NULL)
    {
        p = node;
        node = node->next;
        free(p);
    }
    perror(s);
}

int8_t is_valid_range(const char *s)
{
    if (*(s + 1) != '-')
        return (0);
    if (*s > *(s + 2))
        return (0);
    return (1);
}

int8_t get_charset(uint8_t *cs, const char *s)
{
    uint8_t i;
    uint8_t c;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\\')
            i++;
        else if (s[i + 1] == '-')
        {
            if (is_valid_range(s + i) == 0)
                return (1);
            c = (uint8_t)s[i];
            if (c > 127)
                return (1);
            while (c < (uint8_t)s[i + 2])
                cs[c++] = 1;
            i += 2;
        }
        if (s[i] != '\0')
            cs[(uint8_t)s[i++]] = 1;
    }
    return (0);
}

int8_t get_reps(size_t *n, const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
    {
        if (!ft_isdigit(s[i]))
            return(1);
        i++;
    }
    *n = ft_atoi(s);
    return (0);
}
