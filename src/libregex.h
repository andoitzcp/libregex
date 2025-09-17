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
    T_BEGIN = '^',
    T_END = '$',
    T_DOT = '.',
    T_STAR = '*',
    T_INTER = '?',
    T_PLUS = '+',
    T_NOTVALID
} t_type;

typedef struct s_re
{
    int8_t type;
    char c;
    uint8_t cs[128];
    int8_t neg;
    size_t minc;
    size_t maxc;
    size_t rawlen;
    struct s_re *next;
} t_re;

/* Function prototypes */

int match(t_re **head, char *str);
int matchhere(t_re *re, char *str);
int matchstar(t_re *re1, t_re *re2, char *str);
int is_charmatch(t_re *node, char *str);

t_re **re_new(char *s);
int8_t parse(t_re **head, char *s);
t_re *build_re_node(char *s);
void get_node_type(t_re *node, char *s);
void get_node_c(t_re *node, char *s);

void ft_exit(t_re **head, char *s);
//int8_t get_charset(t_re *node, char *s);
int8_t get_charset(uint8_t *cs, const char *s);
int8_t get_reps(size_t *n, const char *s);

int8_t	ft_isdigit(char c);
int8_t	ft_isascii(char c);
int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strchresc(const char *s, int c, int sc);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char *ft_chrstrchr(char *s, char a, char b, char sc);

#endif // LIBREGEX_H_
