#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Federation.hpp"
#include "../test_include/test_WarpSystem.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Federation, test_Federation_Starfleet_Ship_constructor, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    cr_assert(UssKreog.getLength() == 289);
    cr_assert(UssKreog.getWidth() == 132);
    cr_assert(UssKreog.getName() == "Kreog");
    cr_assert(UssKreog.getMaxWarp() == 6);

    Federation::Ship            Independent(150, 230, "Greok");
	cr_assert_stdout_eq_str(
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
    );
}

Test(QuantumReactor, test_WarpSystem_QuantumReactor_constructor)//, .init = redirect_all_stdout)
{
    WarpSystem::QuantumReactor  QR;

    cr_assert(QR.isStable() == true);
    QR.setStability(false);
    cr_assert(QR.isStable() == false);
    QR.setStability(true);
    cr_assert(QR.isStable() == true);
}

Test(Main, test_main)//, .init = redirect_all_stdout)
{
	cr_assert(1 == 1);
}