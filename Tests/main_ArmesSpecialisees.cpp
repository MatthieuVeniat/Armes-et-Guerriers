#include<iostream>


#include"../ChaineCar/ChaineCar.h"
#include"../Armes/Arme.h"
#include"../Armes/ArmesSpecialisees.h"

int main() {
	ArmeCorpsACorps epee("Excalibure", 4);
	ArmeDistance Arc("Longbow", 4 );
	ArmeMagique Couteau("Couteau de tempete", 4);
	ArmeDeBase Pierre("Pierre", 4);
	epee.Afficher();
	Arc.Afficher();
	Couteau.Afficher();
	std::cout<<Pierre.CalculerDegats(6);
	return 0;
}