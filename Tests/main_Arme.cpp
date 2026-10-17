#include<iostream>


#include"../ChaineCar/ChaineCar.h"
#include"../Armes/Arme.h"

int main() {
	Arme test1("Hache coupante", 2);
	Arme test2("Epee legendaire", 30);
	test1.Afficher();
	std::cout << std::endl;
	test2.Afficher();
	std::cout << std::endl;
	return 0;
}