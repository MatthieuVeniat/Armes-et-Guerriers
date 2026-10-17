#include<iostream>

#include"../ChaineCar/ChaineCar.h"
#include"../Armes/Arme.h"
#include"Personnage.h"

Personnage::Personnage(const char* name, int pvm, int f) {
	nom = name;
	if (pvm <= 0) {
		PVmax = 1;
	}
	else {
		PVmax= pvm;
	}
	PV = PVmax;
	if (f <= 0) {
		force = 1;
	}
	else {
		force = f;
	}

	// Pas d'arme equipee
	armeequipee = nullptr;
}

void Personnage::Afficher(void)const {
	// Aria: 70 / 70 PV, force 7, arme : Epee d'entrainement (+3 degats)
	std::cout << nom << " : " << PV << "/" << PVmax << " PV, force " << force << ", arme : ";
	if (armeequipee == nullptr) {
		std::cout << "aucune arme";
	}
	else {
		armeequipee->Afficher();
	}
	std::cout << std::endl;
}

Personnage::~Personnage(void) {
	delete armeequipee; 
}

void Personnage::RecevoirDegats(int nb_degats) {
	if (nb_degats > 0) {
		if (nb_degats >= PV) {
			PV = 0;
		}
		else {
			PV -= nb_degats;
		}
	}
}

void Personnage::Attaquer(Personnage& cible) const {
	int degats = force;
	if (EstVivant() && cible.EstVivant()) {
		if (armeequipee != nullptr) {
			degats = armeequipee->CalculerDegats(degats);
		}
		cible.RecevoirDegats(degats);
		std::cout << nom << " attaque " << cible.nom << " et inflige " << degats<<" degats.\n";
	}
}

void Personnage::Equiper(Arme* nouvellearme) {
	if (nouvellearme != armeequipee) {
		delete armeequipee;
		armeequipee = nouvellearme;
	}
}

Arme* Personnage::AbandonnerArme(void) {
	Arme* temp = armeequipee;
	armeequipee = nullptr; // On indique que le personnage ne possede plus d'arme
	return temp;
}

bool Personnage::RecupererArme(Personnage& vaincu) {
	bool recupOK;
	if (!vaincu.EstVivant() && vaincu.PossedeArme()) {
		recupOK = true;
		Equiper(vaincu.AbandonnerArme());
	}
	else {
		recupOK = false;
	}
	return recupOK;
}

void Personnage::RecevoirSoin(int PVsup) {
	if ((PV + PVsup) <= PVmax) {
		PV = PV + PVsup;
	}
	else {
		PV = PVmax;
	}
}

void Personnage::Attaquer(Personnage& cible,int puissance, const char* nom_attaque) const {
	int degats = puissance;
	if (EstVivant() && cible.EstVivant()) {
		if (armeequipee != nullptr) {
			degats = armeequipee->CalculerDegats(degats);
		}
		cible.RecevoirDegats(degats);
		std::cout << nom << " realise l'attaque '" <<nom_attaque<< "' sur " << cible.nom << " et inflige " << degats << " degats.\n";
	}
}

void Personnage::Agir(Personnage& ennemi, Personnage* aSoigner) {
	Attaquer(ennemi);
}