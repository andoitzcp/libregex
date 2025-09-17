#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(match, Case1)
{
    t_re **head;

    head = re_new("abc");
    cr_expect(match(head, "abc") == 1);
}

Test(match, Case2)
{
    t_re **head;

    head = re_new("abc");
    cr_expect(match(head, "abd") == 0);
}

Test(match, Case3)
{
    t_re **head;

    head = re_new("ab[cd]");
    cr_expect(match(head, "abd") == 1);
}

Test(match, Case4)
{
    t_re **head;

    head = re_new("ab[cd]");
    cr_expect(match(head, "aba") == 0);
}

Test(match, Case5)
{
    t_re **head;

    head = re_new("ab[A-Z]");
    cr_expect(match(head, "abJ") == 1);
}


Test(match, Case6)
{
    t_re **head;

    head = re_new("ab[A-Z]");
    cr_expect(match(head, "ab]") == 0);
}

Test(match, Case7)
{
    t_re **head;

    head = re_new("ab[A-Z]");
    cr_expect(match(head, "ab9") == 0);
}

Test(match, Case8)
{
    t_re **head;

    head = re_new("a.[A-Z]");
    cr_expect(match(head, "abZ") == 1);
}

Test(match, Case9)
{
    t_re **head;

    head = re_new("^[0-9][0-9][0-9],[0-9][0-9][0-9],[0-9][0-9][0-9]$");
    cr_expect(match(head, "123,456,789") == 1);
}

Test(match, Case10)
{
    t_re **head;

    head = re_new("^[0-9][0-9][0-9],[0-9][0-9][0-9],[0-9][0-9][0-9]$");
    cr_expect(match(head, "123,,456,789") == 0);
}

Test(match, Case11)
{
    t_re **head;

    head = re_new("^[0-9][0-9][0-9],.*,[0-9][0-9][0-9]$");
    cr_expect(match(head, "123,asdfasd456,789") == 1);
}

Test(match, Case12)
{
    t_re **head;

    head = re_new("^[0-9][0-9][0-9],.*,[0-9][0-9][0-9]$");
    cr_expect(match(head, "123,,789") == 1);
}

Test(match, Case13)
{
    t_re **head;

    head = re_new("abc");
    cr_expect(match(head, "01234980abc;lkahjsg79") == 1);
}
