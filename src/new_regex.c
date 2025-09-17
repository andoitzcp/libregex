#include "libregex.h"

void get_node_type(t_re *node, char *s)
{
    if (ft_strchr(".*?+", *s) != NULL)
    {
        node->type = (int8_t)*s;
        node->rawlen = 1;
    }
    else if (*s == '\\')
        node->type = T_CHAR;
    else if (*s == '[')
    {
        node->type = T_CHARSET;
    }
    else if (ft_isascii(*s))
        node->type = T_CHAR;
    else
        node->type = T_NOTVALID;
}

void get_node_c(t_re *node, char *s)
{
    if (node->type != T_CHAR)
        return ;
    node->rawlen = 1;
    if (*s == '\\')
    {
        if (s[1] == '\0')
            return ;
        node->rawlen = 2;
        node->c = s[1];
    }
    else
        node->c = *s;
    return ;
}

uint8_t get_node_cs_neg(t_re *node, char *s)
{
    char *t;

    if (node->type != T_CHARSET)
        return (0);
    t = ft_chrstrchr(s, '[', ']', '\\');
    node->neg = (*t == '^');
    node->rawlen = ft_strlen(t) + 2;
    if(get_charset(node->cs, t + node->neg) != 0)
        return (free(t), 1);
    return (free(t), 0);
}

uint8_t get_node_minc(t_re *node, char *s)
{
    char *t;

    if (s[node->rawlen] != '{')
        return (0);
    if (node->type != T_CHAR && node->type != T_CHARSET)
        return (1);
    t = ft_chrstrchr(s + node->rawlen, '{', '}', '\\');
    node->rawlen += ft_strlen(t) + 2;
    if (get_reps(&(node->minc), t) != 0)
        return (free(t), 1);
    return (free(t), 0);
}

uint8_t get_node_maxc(t_re *node, char *s)
{
    char *t;

    if (s[node->rawlen] != '{')
        return (0);
    if (node->type != T_CHAR && node->type != T_CHARSET)
        return (1);
    t = ft_chrstrchr(s + node->rawlen, '{', '}', '\\');
    node->rawlen += ft_strlen(t) + 2;
    if (get_reps(&(node->maxc), t) != 0)
        return (free(t), 1);
    return (free(t), 0);
}

uint8_t check_node(t_re *node)
{
    if (node->type == T_NOTVALID)
        return (1);
    return (node->minc > node->maxc && node->maxc != 0);
}

t_re *build_re_node(char *s)
{
    t_re *node;

    node = ft_calloc(sizeof(t_re), 1);
    if (!node)
        return (NULL);
    get_node_type(node, s);
    get_node_c(node, s);
    if (get_node_cs_neg(node, s) != 0)
        return (free(node), NULL);
    if (get_node_minc(node, s) != 0)
        return (free(node), NULL);
    if (get_node_maxc(node, s) != 0)
        return (free(node), NULL);
    if (check_node(node) != 0)
        return (free(node), NULL);
    node->next = NULL;
    return(node);
}

void append_re_node(t_re **head, t_re *node)
{
    t_re *current;

    current = *head;
    if (current == NULL)
    {
        *head = node;
        return ;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = node;
}

void check_begin_end(t_re **head)
{
    t_re *node;

    node = *head;
    if (node->c == '^')
    {
        node->type = T_BEGIN;
        node->c = 0;
    }
    while(node->next != NULL)
        node = node->next;
    if (node->c == '$')
    {
        node->type = T_END;
        node->c = 0;
    }
}

t_re **re_new(char *s)
{
    t_re **head;
    t_re *node;
    size_t i;

    head = malloc(sizeof(t_re *));
    if (!head)
        return(perror("Malloc error"), NULL);
    *head = NULL;
    i = 0;
    while (s[i] != '\0')
    {
        node = build_re_node(s + i);
        if (node == NULL)
            return (perror("not a valid regex"), NULL);
        append_re_node(head, node);
        i += node->rawlen;
    }
    check_begin_end(head);
    return (head);
}
