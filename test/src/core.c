#include "utils.h"
#include <criterion/criterion.h>

Test(core, ft_chrstrchr)
{
    char *input;
    char *expected;
    char *result;
    int i = 0;

    i++;
    input = "this is [not] a test";
    expected = "not";
    result = ft_chrstrchr(input, '[', ']', '\\');
    cr_expect(strcmp(result, expected) == 0, "Case %d\n\tinput:%s\n\texpectec:%s\n\tresult:%s\n", i, input, expected, result);

    i++;
    input = "this is [^A-Z] a test";
    expected = "^A-Z";
    result = ft_chrstrchr(input, '[', ']', '\\');
    cr_expect(strcmp(result, expected) == 0, "Case %d\n\tinput:%s\n\texpectec:%s\n\tresult:%s\n", i, input, expected, result);

    i++;
    input = "this is [\\[asdf] a test";
    expected = "\\[asdf";
    result = ft_chrstrchr(input, '[', ']', '\\');
    cr_expect(strcmp(result, expected) == 0, "Case %d\n\tinput:%s\n\texpectec:%s\n\tresult:%s\n", i, input, expected, result);

    i++;
    input = "this is [as\\]df] a test";
    expected = "as\\]df";
    result = ft_chrstrchr(input, '[', ']', '\\');
    cr_expect(strcmp(result, expected) == 0, "Case %d\n\tinput:%s\n\texpectec:%s\n\tresult:%s\n", i, input, expected, result);

    i++;
    input = "[a-zA-Z+*]";
    expected = "a-zA-Z+*";
    result = ft_chrstrchr(input, '[', ']', '\\');
    cr_expect(strcmp(result, expected) == 0, "Case %d\n\tinput:%s\n\texpectec:%s\n\tresult:%s\n", i, input, expected, result);

    i++;
    input = "{2}";
    expected = "2";
    result = ft_chrstrchr(input, '{', '}', '\\');
    cr_expect(strcmp(result, expected) == 0, "Case %d\n\tinput:%s\n\texpectec:%s\n\tresult:%s\n", i, input, expected, result);
}
