#include<iostream>

#include"../ChaineCar/ChaineCar.h"
#include"Arme.h"

void Arme::Afficher(void) const {
	std::cout << nom << " [" << GetType()<<", bonus " << bonusdegats << "]";
}

Arme::Arme(const char* name, int bonus) {
	nom = name; //Conversion forcee de name de char* en ChaineCar
	if (bonus < 0) {
		bonusdegats = 0;
	}
	else {
		bonusdegats = bonus;
	}
}
