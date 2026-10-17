#include<iostream>

#include"../ChaineCar/ChaineCar.h"
#include"../Armes/Arme.h"
#include"../Armes/ArmesSpecialisees.h"
#include"../Personnages/Personnage.h"
#include"../Personnages/PersonnageSpecialises.h"

int main() {

	Personnage Gaston("Gaston", 40, 1);
	Guerrier Borin("Borin", 105, 7);
	Mage Lyra("Lyra", 83, 3, 35);
	Soigneur Legolas("Legolas", 80, 2, 30);

	ArmeCorpsACorps* Epee = new ArmeCorpsACorps("Epee de fer",3);
	ArmeMagique* Baton = new ArmeMagique("Baton d'ambre", 5);
		
	Borin.Equiper(Epee);
	Lyra.Equiper(Baton);

	Gaston.Afficher();
	Borin.Afficher();
	Lyra.Afficher();
	Legolas.Afficher();

	Borin.RecevoirDegats(20);
	std::cout << Borin.Getrage();
	//Borin.Agir(Gaston);
	std::cout << Borin.Getrage();
	Gaston.Afficher();
	Lyra.Agir(Gaston);
	std::cout << Lyra.Getmana();
	Gaston.Afficher();
	Gaston.RecevoirSoin(18);
	Legolas.Agir(Borin, &Gaston);
	Borin.Afficher();
	Gaston.Afficher();
	std::cout << Legolas.Getmana();

	Legolas.Restaurer();
	Borin.Restaurer();
	Lyra.Restaurer();
	Borin.Afficher();
	Lyra.Afficher();
	Legolas.Afficher();

	return 0;
}