
class Arme {
private:
	ChaineCar nom;
	int bonusdegats;
public:
	Arme(const char*, int);
	const ChaineCar& GetNom(void) const { return nom; }
	int GetBonusDegats(void) const { return bonusdegats; }
	void Afficher(void) const;
	virtual int CalculerDegats(int puissanceBase) const { return bonusdegats + puissanceBase; };
	virtual const char* GetType(void)const { return "arme de base"; }
	virtual ~Arme() {};

};

