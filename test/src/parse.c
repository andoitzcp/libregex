#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

/* Test(parse, Case1) */
/* { */
/*     char *input_s = "abc"; */
/*     t_re *expected; */
/*     t_re *result; */
/*     int8_t retval; */

/*     expected = calloc(1, sizeof(t_re)); */
/*     expected->type = T_CHAR; */
/*     expected->c = 'a'; */
/*     expected->neg = 0; */
/*     expected->minc = 0; */
/*     expected->maxc = 0; */
/*     expected->rawlen = 1; */

/*     expected->next = calloc(1, sizeof(t_re)); */
/*     expected->next->type = T_CHAR; */
/*     expected->next->c = 'b'; */
/*     expected->next->neg = 0; */
/*     expected->next->minc = 0; */
/*     expected->next->maxc = 0; */
/*     expected->next->rawlen = 1; */

/*     expected->next->next = calloc(1, sizeof(t_re)); */
/*     expected->next->next->type = T_CHAR; */
/*     expected->next->next->c = 'c'; */
/*     expected->next->next->neg = 0; */
/*     expected->next->next->minc = 0; */
/*     expected->next->next->maxc = 0; */
/*     expected->next->next->rawlen = 1; */

/*     retval = parse(&result, input_s); */

/*     cr_expect(retval == 0); */
/*     while (expected != NULL || result != NULL) */
/*     { */
/*         cr_expect(expected->type == result->type); */
/*         cr_expect(expected->c == result->c, "%c,%c\n", expected->c, result->c); */
/*         cr_expect(memcmp(expected->cs, result->cs, 128 * sizeof(uint8_t)) == 0); */
/*         cr_expect(expected->neg == result->neg); */
/*         cr_expect(expected->minc == result->minc); */
/*         cr_expect(expected->maxc == result->maxc); */
/*         cr_expect(expected->rawlen == result->rawlen); */

/*         expected = expected->next; */
/*         result = result->next; */
/*     } */

/* } */

/* Test(parse, Case2) */
/* { */
/*     char *input_s = "ab[^a-zA-Z]{1}{3}c"; */
/*     t_re *expected; */
/*     t_re *result; */
/*     int8_t retval; */

/*     expected = calloc(1, sizeof(t_re)); */
/*     expected->type = T_CHAR; */
/*     expected->c = 'a'; */
/*     expected->neg = 0; */
/*     expected->minc = 0; */
/*     expected->maxc = 0; */
/*     expected->rawlen = 1; */

/*     expected->next = calloc(1, sizeof(t_re)); */
/*     expected->next->type = T_CHAR; */
/*     expected->next->c = 'b'; */
/*     expected->next->neg = 0; */
/*     expected->next->minc = 0; */
/*     expected->next->maxc = 0; */
/*     expected->next->rawlen = 1; */

/*     expected->next->next = calloc(1, sizeof(t_re)); */
/*     expected->next->next->type = T_CHARSET; */
/*     expected->next->next->c = 0; */
/*     get_charset(expected->next->next->cs, "a-zA-Z"); */
/*     expected->next->next->neg = 1; */
/*     expected->next->next->minc = 1; */
/*     expected->next->next->maxc = 3; */
/*     expected->next->next->rawlen = 15; */

/*     expected->next->next->next = calloc(1, sizeof(t_re)); */
/*     expected->next->next->next->type = T_CHAR; */
/*     expected->next->next->next->c = 'c'; */
/*     expected->next->next->next->neg = 0; */
/*     expected->next->next->next->minc = 0; */
/*     expected->next->next->next->maxc = 0; */
/*     expected->next->next->next->rawlen = 1; */

/*     retval = parse(&result, input_s); */

/*     cr_expect(retval == 0); */
/*     while (expected != NULL || result != NULL) */
/*     { */
/*         cr_expect(expected->type == result->type); */
/*         cr_expect(expected->c == result->c, "%c,%c\n", expected->c, result->c); */
/*         cr_expect(memcmp(expected->cs, result->cs, 128 * sizeof(uint8_t)) == 0); */
/*         cr_expect(expected->neg == result->neg); */
/*         cr_expect(expected->minc == result->minc); */
/*         cr_expect(expected->maxc == result->maxc); */
/*         cr_expect(expected->rawlen == result->rawlen); */

/*         expected = expected->next; */
/*         result = result->next; */
/*     } */

/* } */
