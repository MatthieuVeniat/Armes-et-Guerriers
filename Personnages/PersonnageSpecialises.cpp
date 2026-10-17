#include<iostream>

#include"../ChaineCar/ChaineCar.h"
#include"../Armes/Arme.h"
#include"Personnage.h"
#include"PersonnageSpecialises.h"

void Guerrier::RecevoirDegats(int nb_degats) {
	Personnage::RecevoirDegats(nb_degats);
	if ((rage + nb_degats) <= 100) {
		rage += nb_degats;
	}
	else {
		rage = 100;
	}
}

void Guerrier::Agir(Personnage& e, Personnage* a) {
	if (rage >= 20) {
		Attaquer(e, GetForce() + 6, "Frappe de rage");
		rage = rage - 20;
	}
	else {
		Attaquer(e);
	}
}

void Mage::Agir(Personnage& e, Personnage* a) {
	if (mana >= 10) {
		Attaquer(e, GetForce() + 7, "Boule de feu");
		mana = mana - 10;
	}
	else {
		Attaquer(e);
	}
}

void Soigneur::Agir(Personnage& e, Personnage* a) {
	if (a->EstVivant() && a->GetPV() < (a->GetPVmax() / 2) && mana >= 8) {
		Soigner(*a);
	}
	else {
		if (mana >= 6) {
			Attaquer(e, GetForce() + 3, "Eclat Sacre");
			mana -= 6;
		}
		else {
			Attaquer(e);
		}
	}
}

void Guerrier::Afficher(void) const {
	Personnage::Afficher();
	std::cout << "  " << GetClasse() << " - " << "Rage : " << Getrage() << "/100\n";
}

void Mage::Afficher(void) const {
	Personnage::Afficher();
	std::cout << "  " << GetClasse() << " - " << "Mana : " << Getmana() << "/" << Getmana_max() << "\n";
}

void Soigneur::Afficher(void) const {
	Personnage::Afficher();
	std::cout << "  " << GetClasse() << " - " << "Mana : " << Getmana() << "/" << Getmana_max() << "\n";
}

void Soigneur::Soigner(Personnage& a) {
	if (mana >= 8) {
		a.RecevoirSoin(16);
		mana -= 8;
		std::cout << this->GetNom() << " soigne " << a.GetNom() << " de 16 PV.\n";
	}
}