#include <iostream>

#include "../ChaineCar/ChaineCar.h"
#include "../Armes/Arme.h"
#include "../Armes/ArmesSpecialisees.h"
#include "../Personnages/Personnage.h"
#include "../Personnages/PersonnageSpecialises.h"
#include "../Duel/Duel.h"
#include "Armee.h"

Armee::Armee(const char* nom_armee, int capa) {
	nom = nom_armee;
	if (capa <= 0) {
		capacite = 1;
	}
	else {
		capacite = capa;
	}
	nb_membres = 0;
	membres = new Personnage * [capacite];
	for (int i = 0; i < capacite; i++) {
		membres[i] = nullptr;
	}
}

bool Armee::Ajouter(Personnage* pers) {
	bool ajout = true;
	if (capacite > nb_membres && pers != nullptr) {
		membres[nb_membres] = pers;
		nb_membres++;
	}
	else {
		ajout = false;
	}
	return ajout;
}

void Armee::Afficher(void) const {
	std::cout << "\nArmee: " << nom << " (" << nb_membres << "/" << capacite << " membres)\n";
	for (int i = 0; i < nb_membres; i++) {
		membres[i]->Afficher();
	}
}

bool Armee::EstVaincue() const {
	bool rep = true;
	int i = 0;
	while (rep == true && i < nb_membres) {
		rep = !membres[i]->EstVivant();
		i++;
	}
	return rep;
}

Personnage* Armee::PremierVivant() const {
	Personnage* rep = nullptr;
	int i=0;
	while (rep == nullptr && i < nb_membres) {
		if (membres[i]->EstVivant()) {
			rep = membres[i];
		}
		i++;
	}

	return rep;
}

Personnage* Armee::ChoisirCibleSoin() const {
	Personnage* a_soigner = nullptr;
	if (nb_membres != 0) {
		a_soigner = membres[0];
		if (nb_membres > 0) {
			for (int i = 0; i < (nb_membres-1); i++) {
				if (membres[i]->GetPV() * membres[i + 1]->GetPVmax() > membres[i + 1]->GetPV() * membres[i]->GetPVmax()) {
					a_soigner = membres[i + 1];
				}
			}
		}
	}
	return a_soigner;
}

void Armee::Agir(Personnage& ennemi) {
	int i = 0;
	while(ennemi.EstVivant()&&i<nb_membres){
		if (membres[i]->EstVivant()) {
			membres[i]->Agir(ennemi, ChoisirCibleSoin());
		}
		i++;
	}
}

void Armee::Restaurer() {
	for (int i = 0; i < nb_membres; i++) {
		membres[i]->Restaurer();
	}
}

bool Armee::EquiperMembre(int indice, Arme* nouvellearme) {
	bool rep = false;
	if ((indice >= 0) && (indice < nb_membres)) {
		membres[indice]->Equiper(nouvellearme);
		rep = true;
	}
	return rep;
}