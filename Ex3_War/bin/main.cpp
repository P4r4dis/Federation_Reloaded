#include "../include/Federation.hpp"
#include "../include/WarpSystem.hpp"
#include "../include/Borg.hpp"

int	main()
{
	Federation::Starfleet::Ship 		UssKreog(289, 132, "Kreog", 6);
	Federation::Ship			 		independant(150, 230, "Greok");

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

	independant.setupCore(&core3);
	independant.checkCore();
    independant.move(1, UNICOMPLEX);
    independant.move(1);
    independant.move(EARTH);
    independant.move();
	
	Cube.move(1, VULCAN);
    Cube.move(1);
    Cube.move(UNICOMPLEX);
    Cube.move();
	return 0;
}