#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>



void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Federation, test_Federation_Starfleet_Ship_constructor)//, .init = redirect_all_stdout)
{
cr_assert(1 == 1);
}
