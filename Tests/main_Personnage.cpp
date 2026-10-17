#include<iostream>

#include"../ChaineCar/ChaineCar.h"
#include"../Armes/Arme.h"
#include"../Armes/ArmesSpecialisees.h"
#include"../Personnages/Personnage.h"

int main() {
	Personnage aria("Aria", 70, 7);
	Personnage grik("Grik", 52, 5);

	/*aria.Afficher();
	if (aria.PossedeArme()) {
		std::cout << " arme equipee";
	}
	else {
		std::cout << " Pas arme equipee\n";
	}

	aria.RecevoirDegats(0);
	aria.Afficher();

	if (aria.EstVivant()) {
		std::cout << " vivant\n";
	}
	else {
		std::cout << " mort\n";
	}
	grik.Afficher();
	aria.Attaquer(grik);
	grik.Afficher();*/


	ArmeMagique* Couteau=new ArmeMagique("Couteau de tempete", 3);
	aria.Equiper(Couteau);
	aria.Afficher();
	grik.Afficher();
	
	aria.Attaquer(grik);

	grik.RecevoirSoin(4);
	grik.Afficher();

	aria.Afficher();
	grik.Attaquer(aria, 8, "Malediction");
	aria.Afficher();

	aria.Agir(grik);

	return 0;
}