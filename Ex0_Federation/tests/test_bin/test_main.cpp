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

Test(Core, test_WarpSystem_Core_constructor)//, .init = redirect_all_stdout)
{
    WarpSystem::QuantumReactor  QR;

    WarpSystem::Core            core(&QR);
    cr_assert(core.checkReactor()->isStable() == true);
    core.checkReactor()->setStability(false);
    cr_assert(core.checkReactor()->isStable() == false);
    core.checkReactor()->setStability(true);
    cr_assert(core.checkReactor()->isStable() == true);
}

Test(Ship, test_setupCore, .init = redirect_all_stdout)
{
	Federation::Starfleet::Ship 	UssKreog(289, 132, "Kreog", 6);
	Federation::Ship 				Independent(150, 230, "Greok");
	WarpSystem::QuantumReactor 		QR;
	WarpSystem::QuantumReactor 		QR2;
	WarpSystem::Core 				core(&QR);
	WarpSystem::Core 				core2(&QR2);

    UssKreog.setupCore(&core);
    Independent.setupCore(&core2);

    cr_assert_stdout_eq_str(
    "The ship USS Kreog has been finished.\n"
    "It is 289 m in length and 132 m in width.\n"
    "It can go to Warp 6!\n"
    "The independent ship Greok just finished its construction.\n"
    "It is 150 m in length and 230 m in width.\n"
    "USS Kreog: The core is set.\n"
    "Greok: The core is set.\n"
    );
}

Test(Ship, test_checkCore, .init = redirect_all_stdout)
{
	Federation::Starfleet::Ship 	UssKreog(289, 132, "Kreog", 6);
	Federation::Ship 				Independent(150, 230, "Greok");
	WarpSystem::QuantumReactor 		QR;
	WarpSystem::QuantumReactor 		QR2;
	WarpSystem::Core 				core(&QR);
	WarpSystem::Core 				core2(&QR2);

	UssKreog.setupCore(&core);
	UssKreog.checkCore();
	Independent.setupCore(&core2);
	Independent.checkCore();
	QR.setStability(false);
	QR2.setStability(false);
	UssKreog.checkCore();
	Independent.checkCore();

    cr_assert_stdout_eq_str(
    "The ship USS Kreog has been finished.\n"
    "It is 289 m in length and 132 m in width.\n"
    "It can go to Warp 6!\n"
    "The independent ship Greok just finished its construction.\n"
    "It is 150 m in length and 230 m in width.\n"
    "USS Kreog: The core is set.\n"
    "USS Kreog: The core is stable at the time.\n"
    "Greok: The core is set.\n"
    "Greok: The core is stable at the time.\n"
    "USS Kreog: The core is unstable at the time.\n"
    "Greok: The core is unstable at the time.\n"
    );
}

Test(Main, test_main, .init = redirect_all_stdout)
{
	cr_assert(1 == 1);
}