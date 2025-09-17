#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(build_re_node, Case1)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));
    input_s = "abc";
    input_type = T_CHAR;
    expected->type =input_type;
    expected->c = *input_s;
    expected->neg = 0;
    expected->minc = 0;
    expected->maxc = 0;
    expected->rawlen = 1;

    result = build_re_node(input_s);


    //cr_expect(expected->type == result->type);
    //cr_expect(expected->c == result->c);
    //cr_expect(memcmp(expected->cs, result->cs, 128 * sizeof(uint8_t)) == 0);
    //cr_expect(expected->neg == result->neg);
    //cr_expect(expected->minc == result->minc);
    //cr_expect(expected->maxc == result->maxc);
    //cr_expect(expected->rawlen == result->rawlen);
    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case2)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[abc]";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "abc");
    expected->neg = 0;
    expected->minc = 0;
    expected->maxc = 0;
    expected->rawlen = 5;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case3)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[^abc]";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "abc");
    expected->neg = 1;
    expected->minc = 0;
    expected->maxc = 0;
    expected->rawlen = 6;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case4)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[^a-z]";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "a-z");
    expected->neg = 1;
    expected->minc = 0;
    expected->maxc = 0;
    expected->rawlen = 6;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case5)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[^a-z+\\-]";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "a-z+\\-");
    expected->neg = 1;
    expected->minc = 0;
    expected->maxc = 0;
    expected->rawlen = 9;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case6)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[^a-z+\\-]{1}";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "a-z+\\-");
    expected->neg = 1;
    expected->minc = 1;
    expected->maxc = 0;
    expected->rawlen = 12;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case7)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[a-z+\\-]{1234}";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "a-z+\\-");
    expected->neg = 0;
    expected->minc = 1234;
    expected->maxc = 0;
    expected->rawlen = 14;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case8)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[a-z+\\-]{-1234}";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "a-z+\\-");
    expected->neg = 0;
    expected->minc = 1234;
    expected->maxc = 0;
    expected->rawlen = 15;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    (void)expected;
    cr_expect(result == NULL, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case9)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[a-z+\\-]{12x34}";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "a-z+\\-");
    expected->neg = 0;
    expected->minc = 1234;
    expected->maxc = 0;
    expected->rawlen = 15;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result == NULL, "");
    (void)expected;

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case10)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[a-z+\\-]{1234}{5678}";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "a-z+\\-");
    expected->neg = 0;
    expected->minc = 1234;
    expected->maxc = 5678;
    expected->rawlen = 20;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    /* cr_expect(expected->type == result->type); */
    /* cr_expect(expected->c == result->c); */
    /* cr_expect(memcmp(expected->cs, result->cs, 128 * sizeof(uint8_t)) == 0); */
    /* cr_expect(expected->neg == result->neg); */
    /* cr_expect(expected->minc == result->minc); */
    /* cr_expect(expected->maxc == result->maxc); */
    /* cr_expect(expected->rawlen == result->rawlen); */

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case11)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "[a-z+\\-]{1234}{678}";
    input_type = T_CHARSET;
    expected->type =input_type;
    get_charset(expected->cs, "a-z+\\-");
    expected->neg = 0;
    expected->minc = 1234;
    expected->maxc = 678;
    expected->rawlen = 19;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result == NULL, "");
    (void)expected;

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case12)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "a{2}{5}bc";
    input_type = T_CHAR;
    expected->type =input_type;
    expected->c = *input_s;
    expected->neg = 0;
    expected->minc = 2;
    expected->maxc = 5;
    expected->rawlen = 7;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case13)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "+{2}{5}bc";
    input_type = T_PLUS;
    expected->type =input_type;
    expected->c = 0;
    expected->neg = 0;
    expected->minc = 0;
    expected->maxc = 0;
    expected->rawlen = 1;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    (void)expected;
    cr_expect(result == NULL, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case14)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "*bc";
    input_type = T_STAR;
    expected->type =input_type;
    expected->c = 0;
    expected->neg = 0;
    expected->minc = 0;
    expected->maxc = 0;
    expected->rawlen = 1;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}

Test(build_re_node, Case15)
{
    char *input_s;
    int input_type;
    t_re *expected;
    t_re *result;

    expected = calloc(1, sizeof(t_re));

    input_s = "?bc";
    input_type = T_INTER;
    expected->type =input_type;
    expected->c = 0;
    expected->neg = 0;
    expected->minc = 0;
    expected->maxc = 0;
    expected->rawlen = 1;

    result = build_re_node(input_s);

    //print_re_node(expected);
    //print_re_node(result);

    cr_expect(result != NULL, "");
    cr_expect(memcmp(expected, result, sizeof(t_re)) == 0, "");

    free(expected);
    free(result);
    expected = NULL;
    result = NULL;
}
