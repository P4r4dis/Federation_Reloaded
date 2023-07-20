#include "../include/Federation.hpp"
#include "../include/WarpSystem.hpp"
#include "../include/Borg.hpp"

int	main()
{
	Federation::Starfleet::Ship 		UssKreog(289, 132, "Kreog", 6, 3);
	Federation::Ship			 		Independant(150, 230, "Greok");

	Federation::Starfleet::Captain 		James("James T. Kirk");
	Federation::Starfleet::Ensign	 	Ensign("Pavel Chekov");
	WarpSystem::QuantumReactor 			QR;
	WarpSystem::QuantumReactor 			QR2;
	WarpSystem::QuantumReactor 			QR3;

	WarpSystem::Core 					core(&QR);
	WarpSystem::Core 					core2(&QR2);
	WarpSystem::Core 					core3(&QR3);

	UssKreog.setupCore(&core);
	UssKreog.checkCore();
	UssKreog.promote(&James);
	Borg::Ship	 						Cube;
	Cube.setupCore(&core2);
	Cube.checkCore();

    UssKreog.move(1, VULCAN);
    UssKreog.move(1);
    UssKreog.move(UNICOMPLEX);
    UssKreog.move();

	Independant.setupCore(&core3);
	Independant.checkCore();
    Independant.move(1, UNICOMPLEX);
    Independant.move(1);
    Independant.move(EARTH);
    Independant.move();
	
	Cube.move(1, VULCAN);
    Cube.move(1);
    Cube.move(UNICOMPLEX);
    Cube.move();

    UssKreog.fire(&Cube);
    UssKreog.fire(&Cube);
    UssKreog.fire(&Cube);
    UssKreog.fire(&Cube);

    Cube.fire(&UssKreog);

    Cube.fire(&Independant);

    UssKreog.fire(&Cube);
    Cube.repair();
    UssKreog.fire(&Cube);
    Cube.repair();
	return 0;
}