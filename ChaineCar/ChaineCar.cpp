#include<iostream>

#include"ChaineCar.h"

//Constructeur
ChaineCar::ChaineCar(const char* ch) {

	//1.Determiner la taille de ch

	for (len = 0; ch[len] != '\0'; len++) {}

	//2. Creer la zone memoire de taille len caracteres

	p_str = new char[len];

	//3. Copie des elements de ch dans la zone pointee par p_str.

	for (unsigned int i = 0; i < len; i++) {
		p_str[i] = ch[i];
	}

}

ChaineCar::~ChaineCar(void) {
	delete [] p_str;
}

void ChaineCar::Affiche(void) const {
	for (unsigned int i = 0; i < len; i++) {
		std::cout << p_str[i];
	}
}

void ChaineCar::MintoMaj(void) {
	for (unsigned int i = 0; i < len; i++) {
		//Si c'est une minuscule
		if (p_str[i] >= 'a' && p_str[i] <= 'z') {
			p_str[i] = p_str[i] - 'a' + 'A';
		}
	}
}

//Constructeur de copie
ChaineCar::ChaineCar(const ChaineCar& ch) {
	//1.Taille nouvelle zone
	len = ch.len;
	//2. Allocation nouvelle zone
	p_str = new char[len];
	//3. Copie des elements de ch dans la zone
	for (unsigned int i = 0; i < len; i++) {
		p_str[i] = ch.p_str[i];
	}
}

ChaineCar& ChaineCar::operator=(const ChaineCar& ch) {
	len = ch.len;
	delete[] p_str;
	p_str = new char[len];
	for (unsigned int i = 0; i < len; i++) {
		p_str[i] = ch.p_str[i];
	}
	return *this;
}

ChaineCar ChaineCar::Ajoute(const ChaineCar& ch) const{

	ChaineCar concat; 
	concat.len = len + ch.len;
	delete[] concat.p_str;
	concat.p_str = new char[concat.len];
	for (unsigned int i = 0; i < len; i++) {
		concat.p_str[i] = p_str[i];
	}
	for (unsigned int i = 0; i < len; i++) {
		concat.p_str[len + i] = ch.p_str[i];
	}
	return concat; //On ne retourne pas la reference car concat va etre detruite donc on va etre oblige de copier concat dans une autre ChaineCar
}

ChaineCar ChaineCar::operator+(const ChaineCar& ch)const {
	return Ajoute(ch);
}

//Definition fonction operator<<

std::ostream& operator<<(std::ostream& f, const ChaineCar& str) {
	str.Affiche(f);
	return f;
}

void ChaineCar::Affiche(std::ostream& flux) const {
	for (unsigned int i = 0; i < len; i++) {
		flux << p_str[i];
	}
}


int ChaineCar::operator==(const ChaineCar& ch)const {
	int rep = 1;
	if (len == ch.len) {
		for (unsigned int i = 0; i < len; i++) {
			if (ch.p_str[i] != p_str[i]) {
				rep = 0;
			}
		}
	}
	else {
		rep = 0;
	}
	return rep;
}
