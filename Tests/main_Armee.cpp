#include <iostream>


#include "../ChaineCar/ChaineCar.h"
#include "../Armes/Arme.h"
#include "../Armes/ArmesSpecialisees.h"
#include "../Personnages/Personnage.h"
#include "../Personnages/PersonnageSpecialises.h"
#include "../Duel/Duel.h"
#include "../Armee/Armee.h"

int main() {
	Personnage* perso = new Soigneur("Test", 38, 2, 60);
	Armee compagnie("Compagnie de l'Aube", 3);
	compagnie.Afficher();
	compagnie.Ajouter(new Guerrier("Borin", 105, 7));
	compagnie.Afficher();
	compagnie.Ajouter(new Mage("Lyra", 82, 5, 35));
	compagnie.Afficher();
	compagnie.Ajouter(new Soigneur("Mira", 88, 4, 50));

	if (!compagnie.Ajouter(perso)) {
		delete perso;
		std::cout << "Perso detruit";
	}
	
	std::cout << std::endl<<compagnie.GetMembre(-1)<<std::endl;
	std::cout << compagnie.GetMembre(3)<<std::endl;

	compagnie.Afficher();

	return 0;
}