#include "libregex.h"

/*
** Takes a string 's' and 2 delimiter characters 'a' and 'b' and an scape
** character 'sc'.
** Returns a heap allocated strign inside the boundaries of 'a'
** and 'b'. If 'sc' before 'a' or 'b' this are scaped.
** If a string is not encountered a heap allocated empty string is returned.
** Returns NULL on error.
*/
char *ft_chrstrchr(char *s, char a, char b, char sc)
{
    char *p;
    char *q;
    char *r;
    size_t i;

    if (ft_strlen(s) < 3)
        return (ft_strdup(""));
    p = ft_strchresc(s, a, sc);
    q = ft_strchresc(p + 1, b, sc);
    if (q == NULL || p == NULL)
        return (NULL);
    r = ft_calloc(q - p, sizeof(char));
    i = 0;
    while (++p < q)
    {
        //if (*p == '\\')
            //p++;
        r[i] = *p;
        i++;
    }
    return(r);
}
