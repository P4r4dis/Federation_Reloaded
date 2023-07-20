#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Federation.hpp"
#include "../test_include/test_WarpSystem.hpp"
#include "../test_include/test_Borg.hpp"
#include "../test_include/test_Admiral.hpp"

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

Test(Borg_Ship, test_Ship_constructor, .init = redirect_all_stdout)
{
    Borg::Ship	 Cube;

    cr_assert_stdout_eq_str(
    "We are the Borgs."
    " Lower your shields and surrender yourselves unconditionally.\n"
    "Your biological characteristics and technologies will be assimilated.\n"
    "Resistance is futile.\n"
    );
}

Test(Borg_Ship, test_Borg_Ship_setupCore, .init = redirect_all_stdout)
{
    Borg::Ship	                Cube;
    WarpSystem::QuantumReactor  QR;
    WarpSystem::Core 			core(&QR);
    Cube.setupCore(&core);

    cr_assert_stdout_eq_str(
    "We are the Borgs."
    " Lower your shields and surrender yourselves unconditionally.\n"
    "Your biological characteristics and technologies will be assimilated.\n"
    "Resistance is futile.\n"
    );
}

Test(Borg_Ship, test_Borg_Ship_checkCore, .init = redirect_all_stdout)
{
    Borg::Ship	                Cube;
    WarpSystem::QuantumReactor  QR;
    WarpSystem::Core 			core(&QR);
    Cube.setupCore(&core);
    Cube.checkCore();
    cr_assert_stdout_eq_str(
    "We are the Borgs."
    " Lower your shields and surrender yourselves unconditionally.\n"
    "Your biological characteristics and technologies will be assimilated.\n"
    "Resistance is futile.\n"
    "Everything is in order.\n"
    );
}

Test(Federation_Starfleet_Captain, test_Captain)//, .init = redirect_all_stdout)
{
    Federation::Starfleet::Captain  James("James T. Kirk");

    cr_assert(James.getName() == "James T. Kirk");
    cr_assert(James.getAge() == 0);
    James.setAge(21);
    cr_assert(James.getAge() == 21);
}

Test(Federation_Starfleet_Ship, test_Ship_promote, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship 		UssKreog(289, 132, "Kreog", 6);
	Federation::Starfleet::Captain 		James("James T. Kirk");

    UssKreog.promote(&James);

    cr_assert_stdout_eq_str(
    "The ship USS Kreog has been finished.\n"
    "It is 289 m in length and 132 m in width.\n"
    "It can go to Warp 6!\n"
    "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
    );
}

Test(Federation_Starfleet_Ensign, test_Ensign_constructor, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ensign   Ensign("Pavel Chekov");

    cr_assert_stdout_eq_str("Ensign Pavel Chekov, awaiting orders.\n");
}



Test(Federation, test_Federation_Starfleet_Ship_move, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
	WarpSystem::QuantumReactor 			QR;
	WarpSystem::Core 					core(&QR);
    UssKreog.setupCore(&core);
    cr_assert(UssKreog.getLength() == 289);
    cr_assert(UssKreog.getWidth() == 132);
    cr_assert(UssKreog.getName() == "Kreog");
    cr_assert(UssKreog.getMaxWarp() == 6);

    cr_assert(UssKreog.getHome() == EARTH);
    cr_assert(UssKreog.move(1, VULCAN) == true);
    cr_assert(UssKreog.getLocation() == VULCAN);

    cr_assert(UssKreog.getHome() == EARTH);
    cr_assert(UssKreog.move(1) == true);
    cr_assert(UssKreog.getLocation() == EARTH);

    cr_assert(UssKreog.getHome() == EARTH);
    cr_assert(UssKreog.move(UNICOMPLEX) == true);
    cr_assert(UssKreog.getLocation() == UNICOMPLEX);

    cr_assert(UssKreog.getHome() == EARTH);
    cr_assert(UssKreog.move() == true);
    cr_assert(UssKreog.getLocation() == EARTH);

	cr_assert_stdout_eq_str(
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "USS Kreog: The core is set.\n"
    );
}

Test(Federation, test_Federation_Ship_move, .init = redirect_all_stdout)
{
    Federation::Ship UssKreog(150, 230, "Greok");
	WarpSystem::QuantumReactor 			QR;
	WarpSystem::Core 					core(&QR);
    UssKreog.setupCore(&core);
    cr_assert(UssKreog.getLength() == 150);
    cr_assert(UssKreog.getWidth() == 230);
    cr_assert(UssKreog.getName() == "Greok");

    cr_assert(UssKreog.getHome() == VULCAN);
    cr_assert(UssKreog.move(1, UNICOMPLEX) == true);
    cr_assert(UssKreog.getLocation() == UNICOMPLEX);

    cr_assert(UssKreog.getHome() == VULCAN);
    cr_assert(UssKreog.move(1) == true);
    cr_assert(UssKreog.getLocation() == VULCAN);

    cr_assert(UssKreog.getHome() == VULCAN);
    cr_assert(UssKreog.move(UNICOMPLEX) == true);
    cr_assert(UssKreog.getLocation() == UNICOMPLEX);

    cr_assert(UssKreog.getHome() == VULCAN);
    cr_assert(UssKreog.move() == true);
    cr_assert(UssKreog.getLocation() == VULCAN);
    
	cr_assert_stdout_eq_str(
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
        "Greok: The core is set.\n"
    );
}

Test(Borg, test_Borg_Ship_move, .init = redirect_all_stdout)
{    
    Borg::Ship	                Cube;
    WarpSystem::QuantumReactor  QR;
    WarpSystem::Core 			core(&QR);
    Cube.setupCore(&core);

    cr_assert(Cube.getHome() == UNICOMPLEX);
    cr_assert(Cube.move(1, VULCAN) == true);
    cr_assert(Cube.getLocation() == VULCAN);

    cr_assert(Cube.getHome() == UNICOMPLEX);
    cr_assert(Cube.move(1) == true);
    cr_assert(Cube.getLocation() == UNICOMPLEX);

    cr_assert(Cube.getHome() == UNICOMPLEX);
    cr_assert(Cube.move(VULCAN) == true);
    cr_assert(Cube.getLocation() == VULCAN);

    cr_assert(Cube.getHome() == UNICOMPLEX);
    cr_assert(Cube.move() == true);
    cr_assert(Cube.getLocation() == UNICOMPLEX);

    cr_assert_stdout_eq_str(
    "We are the Borgs."
    " Lower your shields and surrender yourselves unconditionally.\n"
    "Your biological characteristics and technologies will be assimilated.\n"
    "Resistance is futile.\n"
    );
}

Test(Federation, test_Federation_Starfleet_Ship_constructorV2, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    cr_assert(UssKreog.getLength() == 289);
    cr_assert(UssKreog.getWidth() == 132);
    cr_assert(UssKreog.getName() == "Kreog");
    cr_assert(UssKreog.getMaxWarp() == 6);
    cr_assert(UssKreog.getHome() == EARTH);
    cr_assert(UssKreog.getLocation() == EARTH);
    cr_assert(UssKreog.getShield() == 100);
    cr_assert(UssKreog.getTorpedo() == 0);
    UssKreog.setShield(150);
    cr_assert(UssKreog.getShield() == 150);
    UssKreog.setTorpedo(10);
    cr_assert(UssKreog.getTorpedo() == 10);

    Federation::Starfleet::Ship UssKreog2(289, 132, "Kreog", 6, 10);
    cr_assert(UssKreog2.getTorpedo() == 10);

    Federation::Starfleet::Ship UssKreog3;

	cr_assert_stdout_eq_str(
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 10 torpedoes ready.\n"
        "The ship USS Entreprise has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
    );
}


Test(Federation, test_Federation_Starfleet_Ship_fire, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 3);
	Federation::Starfleet::Captain 		James("James T. Kirk");
    UssKreog.promote(&James);
    Borg::Ship borg;


    cr_assert(borg.getShield() == 100);
    UssKreog.fire(&borg);
    cr_assert(borg.getShield() == 50);
    cr_assert(UssKreog.getTorpedo() == 2);
    UssKreog.fire(&borg);
    cr_assert(borg.getShield() == 0);
    cr_assert(UssKreog.getTorpedo() == 1);
    UssKreog.fire(&borg);
    cr_assert(borg.getShield() == 0);
    cr_assert(UssKreog.getTorpedo() == 0);
    UssKreog.fire(&borg);

    Federation::Starfleet::Ship UssKreog2(289, 132, "Kreog", 6, 3);
	Federation::Starfleet::Captain 		James2("James T. Kirk");
    UssKreog2.promote(&James2);

    UssKreog2.fire(3, &borg);
    cr_assert(borg.getShield() == 0);
    cr_assert(UssKreog.getTorpedo() == 0);
    UssKreog2.fire(3, &borg);

	cr_assert_stdout_eq_str(
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 3 torpedoes ready.\n"
        "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
        "We are the Borgs."
        " Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "Kreog: Firing on target. 2 torpedoes remaining.\n"
        "Kreog: Firing on target. 1 torpedoes remaining.\n"
        "Kreog: Firing on target. 0 torpedoes remaining.\n"
        "Kreog: No more torpedo to fire, James T. Kirk!\n"
        "Kreog: No enough torpedoes to fire, James T. Kirk!\n"
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 3 torpedoes ready.\n"
        "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
        "Kreog: Firing on target. 0 torpedoes remaining.\n"
        "Kreog: No more torpedo to fire, James T. Kirk!\n"
        "Kreog: No enough torpedoes to fire, James T. Kirk!\n"
    );
}

Test(Ship, test_Federation_Ship_getCore, .init = redirect_all_stdout)
{
	Federation::Ship 				Independent(150, 230, "Greok");
	WarpSystem::QuantumReactor 		QR2;
	WarpSystem::Core 				core2(&QR2);

    Independent.setupCore(&core2);
    cr_assert(Independent.getCore() != nullptr);
    cr_assert(Independent.getCore()->checkReactor()->isStable() == true);

    cr_assert_stdout_eq_str(
    "The independent ship Greok just finished its construction.\n"
    "It is 150 m in length and 230 m in width.\n"
    "Greok: The core is set.\n"
    );
}

Test(Borg, test_Borg_Ship_customCtor, .init = redirect_all_stdout)
{    
    Borg::Ship	                Cube(30, 10);

    cr_assert(Cube.getShield() == 100);
    Cube.setShield(150);
    cr_assert(Cube.getShield() == 150);

    cr_assert(Cube.getWeaponFrequency() == 30);
    Cube.setWeaponFrequency(50);
    cr_assert(Cube.getWeaponFrequency() == 50);

    cr_assert(Cube.getRepair() == 10);
    Cube.setRepair(20);
    cr_assert(Cube.getRepair() == 20);

    cr_assert_stdout_eq_str(
    "We are the Borgs."
    " Lower your shields and surrender yourselves unconditionally.\n"
    "Your biological characteristics and technologies will be assimilated.\n"
    "Resistance is futile.\n"
    );
}

Test(Borg, test_Borg_Ship_fire, .init = redirect_all_stdout)
{    
    Borg::Ship	                Cube(30, 10);
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 3);
	Federation::Ship 			Independent(150, 230, "Greok");

    cr_assert(UssKreog.getShield() == 100);
    Cube.fire(&UssKreog);
    cr_assert(UssKreog.getShield() == 70);

    cr_assert(Independent.getShield() == 100);
    Cube.fire(&Independent);
    cr_assert(Independent.getShield() == 70);

    cr_assert_stdout_eq_str(
    "We are the Borgs."
    " Lower your shields and surrender yourselves unconditionally.\n"
    "Your biological characteristics and technologies will be assimilated.\n"
    "Resistance is futile.\n"
    "The ship USS Kreog has been finished.\n"
    "It is 289 m in length and 132 m in width.\n"
    "It can go to Warp 6!\n"
    "Weapons are set: 3 torpedoes ready.\n"
    "The independent ship Greok just finished its construction.\n"
    "It is 150 m in length and 230 m in width.\n"
    "Firing on target with 30 GW frequency.\n"
    "Firing on target with 30 GW frequency.\n"
    );
}

Test(Borg, test_Borg_Ship_repair, .init = redirect_all_stdout)
{    
    Borg::Ship	                Cube(30, 1);
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 3);

    cr_assert(Cube.getShield() == 100);
    UssKreog.fire(&Cube);
    cr_assert(Cube.getShield() == 50);
    Cube.repair();
    cr_assert(Cube.getShield() == 100);
    UssKreog.fire(&Cube);
    Cube.repair();
    cr_assert(Cube.getShield() == 50);

    cr_assert_stdout_eq_str(
    "We are the Borgs."
    " Lower your shields and surrender yourselves unconditionally.\n"
    "Your biological characteristics and technologies will be assimilated.\n"
    "Resistance is futile.\n"
    "The ship USS Kreog has been finished.\n"
    "It is 289 m in length and 132 m in width.\n"
    "It can go to Warp 6!\n"
    "Weapons are set: 3 torpedoes ready.\n"
    "Kreog: Firing on target. 2 torpedoes remaining.\n"
    "Begin shield re-initialisation... Done. Awaiting further instructions.\n"
    "Kreog: Firing on target. 1 torpedoes remaining.\n"
    "Energy cells depleted, shield weakening.\n"
    );
}

// Test(Main, test_War_main)//, .init = redirect_all_stdout)
// {
// 	Federation::Starfleet::Ship 		UssKreog(289, 132, "Kreog", 6, 3);
//     Federation::Ship 			        Independent(150, 230, "Greok");

// 	Federation::Starfleet::Captain 		James("James T. Kirk");
// 	Federation::Starfleet::Ensign	 	Ensign("Pavel Chekov");
// 	WarpSystem::QuantumReactor 			QR;
// 	WarpSystem::QuantumReactor 			QR2;
// 	WarpSystem::Core 					core(&QR);
// 	WarpSystem::Core 					core2(&QR2);
// 	UssKreog.setupCore(&core);
// 	UssKreog.checkCore();
// 	UssKreog.promote(&James);
// 	Borg::Ship	 						Cube;
// 	Cube.setupCore(&core2);
// 	Cube.checkCore();
//     cr_assert(UssKreog.getHome() == EARTH);
//     cr_assert(UssKreog.move(1, UNICOMPLEX) == true);
//     cr_assert(UssKreog.getLocation() == UNICOMPLEX);

//     cr_assert(UssKreog.getHome() == EARTH);
//     cr_assert(UssKreog.move(1) == true);
//     cr_assert(UssKreog.getLocation() == EARTH);

//     cr_assert(UssKreog.getHome() == EARTH);
//     cr_assert(UssKreog.move(UNICOMPLEX) == true);
//     cr_assert(UssKreog.getLocation() == UNICOMPLEX);

//     cr_assert(UssKreog.getHome() == EARTH);
//     cr_assert(UssKreog.move() == true);
//     cr_assert(UssKreog.getLocation() == EARTH);

//     cr_assert(Cube.getHome() == UNICOMPLEX);
//     cr_assert(Cube.move(1, VULCAN) == true);
//     cr_assert(Cube.getLocation() == VULCAN);

//     cr_assert(Cube.getHome() == UNICOMPLEX);
//     cr_assert(Cube.move(1) == true);
//     cr_assert(Cube.getLocation() == UNICOMPLEX);

//     cr_assert(Cube.getHome() == UNICOMPLEX);
//     cr_assert(Cube.move(VULCAN) == true);
//     cr_assert(Cube.getLocation() == VULCAN);

//     cr_assert(Cube.getHome() == UNICOMPLEX);
//     cr_assert(Cube.move() == true);
//     cr_assert(Cube.getLocation() == UNICOMPLEX);

//      cr_assert(Cube.getShield() == 100);
//     UssKreog.fire(&Cube);
//     cr_assert(Cube.getShield() == 50);
//     cr_assert(UssKreog.getTorpedo() == 2);
//     UssKreog.fire(&Cube);
//     cr_assert(Cube.getShield() == 0);
//     cr_assert(UssKreog.getTorpedo() == 1);
//     UssKreog.fire(&Cube);
//     cr_assert(Cube.getShield() == 0);
//     cr_assert(UssKreog.getTorpedo() == 0);
//     UssKreog.fire(&Cube);

//     cr_assert(UssKreog.getShield() == 100);
//     Cube.fire(&UssKreog);
//     cr_assert(UssKreog.getShield() == 80);

//     cr_assert(Independent.getShield() == 100);
//     Cube.fire(&Independent);
//     cr_assert(Independent.getShield() == 80);

//     cr_assert(Cube.getShield() == 0);
//     UssKreog.fire(&Cube);
//     cr_assert(Cube.getShield() == 0);
//     Cube.repair();
//     cr_assert(Cube.getShield() == 100);
//     UssKreog.fire(&Cube);
//     Cube.repair();
//     cr_assert(Cube.getShield() == 100);
//     // cr_assert_stdout_eq_str(
//     // "The ship USS Kreog has been finished.\n"
//     // "It is 289 m in length and 132 m in width.\n"
//     // "It can go to Warp 6!\n"
//     // "Ensign Pavel Chekov, awaiting orders.\n"
//     // "USS Kreog: The core is set.\n"
//     // "USS Kreog: The core is stable at the time.\n"
//     // "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
//     // "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
//     // "Your biological characteristics and technologies will be assimilated.\n"
//     // "Resistance is futile.\n"
//     // "Everything is in order.\n"
//     // );
// }

Test(Admiral, test_Federation_Starfleet_Admiral, .init = redirect_all_stdout)
{
    Federation::Starfleet::Admiral     admiral("Paradis");

    cr_assert(admiral.getName() == "Paradis");
    cr_assert_stdout_eq_str(
        "Admiral Paradis ready for action.\n"
    );
}

Test(Admiral, test_Federation_Starfleet_Admiral_move, .init = redirect_all_stdout)
{
    Federation::Starfleet::Admiral     admiral("Paradis");
    Federation::Starfleet::Ship         UssKreog(289, 132, "Kreog", 6, 3);
	WarpSystem::QuantumReactor 			QR;
	WarpSystem::Core 					core(&QR);
    
    cr_assert(admiral.getName() == "Paradis");

    UssKreog.setupCore(&core);

    cr_assert(admiral.move(&UssKreog, VULCAN)  == VULCAN);
    cr_assert(UssKreog.getLocation() == VULCAN);

    cr_assert_stdout_eq_str(
        "Admiral Paradis ready for action.\n"
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 3 torpedoes ready.\n"
        "USS Kreog: The core is set.\n"
    );
}