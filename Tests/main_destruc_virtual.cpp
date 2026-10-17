#include <iostream>


#include "../ChaineCar/ChaineCar.h"
#include "../Armes/Arme.h"
#include "../Armes/ArmesSpecialisees.h"
#include "../Personnages/Personnage.h"
#include "../Personnages/PersonnageSpecialises.h"
#include "../Duel/Duel.h"

int main() {
	Arme* arme = new ArmeMagique("Baton magique", 7);
	delete arme;
}