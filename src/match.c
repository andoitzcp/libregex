#include "libregex.h"

ssize_t build_re_node(t_re *node, char *s, int type)
{
    char *p;
    char *q;

    node->type = type;
    if (type == T_CHAR)
        node->c = *s;
    if (type == T_CHARSET)
        node->cs = get_charset(s);
    p = ft_strchr(s, '{');
    node->minc = get_int_in_brackets(p);
    if (node->minc == -1)
        return (-1);
    p = ft_strchr(p, '}');
    q = p + 1;
    node->minc = get_int_in_brackets(q);
    if (node->minc == -1)
        return (-1);
    q = ft_strchr(q, '}');
    if (q != NULL)
        return (q - s + 1);
    if (p != NULL)
        return (p - s + 1);
    if (type == T_CHAR)
        return (1);
    if (type == T_CHARSET)
        return (ft_strlen(node->cs) + node->neg + 2);

}

int parse(t_re *re, char *s)
{
    t_re *p;
    char *c;
    size_t i;
    size_t len;

    re = malloc(sizeof(t_re) * ft_strlen(s));
    if (!re)
        ft_exit(re, "Malloc error");
    ft_memset((void *)re, '\0', sizeof(t_re) * ft_strlen(s));
    p = re;
    i = 0;
    while (s[i] != '\0')
    {
        c = ft_strchr("*?+", s[i]);
        if (!ft_isascii(s[i]))
            return(0);
        else if (s[i] == '\\')
            len = build_re_node(re + i, s + 1, T_CHAR) + 1;
        else if (s[i] == '[')
            len = build_re_node(re + i, s, T_CHARSET);
        else if (c != NULL)
            len = build_re_node(re + i, s, *c);
        else
            len = build_re_node(re + i, s, T_CHAR);
        if (len == -1)
            return (0);
        i += len;
    }
    return (1);
}

int match(char *regex_str, char *str)
{
    t_re *re;

    if (!parse(&re, str))
        ft_exit(&re, "Invalid regex string!");
}
