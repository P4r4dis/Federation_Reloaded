#include "../include/Federation.hpp"
#include "../include/WarpSystem.hpp"
#include "../include/Borg.hpp"

int	main()
{
	Federation::Starfleet::Ship 		UssKreog(289, 132, "Kreog", 6);
	Federation::Starfleet::Captain 		James("James T. Kirk");
	Federation::Starfleet::Ensign	 	Ensign("Pavel Chekov");
	WarpSystem::QuantumReactor 			QR;
	WarpSystem::QuantumReactor 			QR2;
	WarpSystem::Core 					core(&QR);
	WarpSystem::Core 					core2(&QR2);
	UssKreog.setupCore(&core);
	UssKreog.checkCore();
	UssKreog.promote(&James);
	Borg::Ship	 						Cube;
	Cube.setupCore(&core2);
	Cube.checkCore();
	
	return 0;
}