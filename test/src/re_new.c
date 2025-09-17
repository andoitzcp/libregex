#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>


/* static void print_cs_arr(uint8_t *cs) */
/* { */
/*     int i; */
/*     int j; */
/*     int k; */

/*     i = 0; */
/*     k = 0; */
/*     printf("\tcs=\t0,1,2,3,4,5,6,7,8,9\n\n"); */
/*     while (i < 128) */
/*     { */
/*         printf("\t  %d\t%d", k, (cs)[i++]); */
/*         j = 0; */
/*         while (j++ < 9 && i < 128) */
/*             printf(",%d", (cs)[i++]); */
/*         printf("\n"); */
/*         k++; */
/*     } */
/* } */

/* static void print_re_node(t_re *node) */
/* { */
/*     printf("Node: %p\n", node); */
/*     printf("\ttype=%d\n", node->type); */
/*     printf("\tc=%c\n", node->c); */
/*     print_cs_arr((uint8_t *)node->cs); */
/*     printf("\tneg=%d\n", node->neg); */
/*     printf("\tminc=%ld\n", node->minc); */
/*     printf("\tmaxc=%ld\n", node->maxc); */
/*     printf("\trawlen=%ld\n", node->rawlen); */
/*     printf("\tnext=%p\n", node->next); */
/* } */

/* static void print_re_llist(t_re **head) */
/* { */
/*     t_re *node; */

/*     node = *head; */
/*     while(node != NULL) */
/*     { */
/*         print_re_node(node); */
/*         node = node->next; */
/*     } */
/* } */


Test(re_new, Case1)
{
    t_re **head;
    char *input = "[a-z]bc";

    head = re_new(input);
    (void)head;
    //print_re_llist(head);
    cr_expect(1 == 1);
}
