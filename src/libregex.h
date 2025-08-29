#ifndef LIBREGEX_H_
#define LIBREGEX_H_

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#define BORRAR "borrar"

/* Struture definitions */

typedef enum e_type
{
    T_NOTSET,
    T_CHAR,
    T_CHARSET,
    T_STAR = '*',
    T_INTER = '?',
    T_PLUS = '+',
} t_type;

typedef struct s_re
{
    int8_t type;
    char c;
    char *cs;
    int8_t neg;
    size_t minc;
    size_t maxc;
} t_re;

/* Function prototypes */

int match(char *regex_str, char *str);

int parse(t_re *re, char *s);
ssize_t build_re_node(t_re *node, char *s, int type);

void ft_exit(t_re *re, char *s);
void get_charset(t_re *node, char *s);
int get_int_in_brackets(char *s);
char *ft_chrstrchr(char *s, char a, char b);

int8_t ft_isdigit(char c);
int8_t ft_isascii(char c);
int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);

#endif // LIBREGEX_H_
