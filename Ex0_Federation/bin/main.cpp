int	main()
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
	
	return 0;
}