#pragma once

class ChaineCar {
private:
	char* p_str;
	unsigned int len;
public:
	ChaineCar(const char* = " ");

	ChaineCar& operator=(const ChaineCar&);

	unsigned int Getlen(void) const { return len; }
	char* Getstr(void) const { return p_str; }
	void Affiche(void) const;
	void MintoMaj(void);
	ChaineCar(const ChaineCar&);

	
	ChaineCar Ajoute(const ChaineCar&) const;
	ChaineCar Ajoute(const char*) const;
	ChaineCar operator+(const ChaineCar& ch)const;

	int operator==(const ChaineCar&)const;

	void Affiche(std::ostream&) const;

	~ChaineCar(void);
};

//Surcharge de la fonction operateur <<

std::ostream& operator<<(std::ostream&, const ChaineCar&);