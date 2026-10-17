#include<iostream>
using namespace std;

#include"../ChaineCar/ChaineCar.h"

int main(void)
{
	ChaineCar nom("DUPLANTIS"), prenom("Armand");
	//ChaineCar nomprenom;
	//nomprenom = prenom.Ajoute(nom);
	ChaineCar specialite("Perche");
	ChaineCar sportif;
	sportif = nom + " " + prenom + ": " + specialite;// Concatenation
	cout << sportif << endl;// Affichage
	return 0;
}

