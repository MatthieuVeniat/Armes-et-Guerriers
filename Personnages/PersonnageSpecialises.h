class Guerrier : public Personnage {
private:
	int rage;
public:
	Guerrier(const char* name, int pvm, int f) : Personnage(name, pvm, f) {
		rage = 0;
	}
	virtual void RecevoirDegats(int);
	virtual void Agir(Personnage&, Personnage* = nullptr);
	virtual void Restaurer(void) {
		Personnage::Restaurer();
		rage = 0;
	}
	int Getrage(void) const { return rage; }
	const char* GetClasse(void) const { return "Guerrier"; }
	virtual void Afficher(void) const;
};

class Mage : public Personnage {
private:
	int mana;
	int mana_max;
public:
	Mage(const char* name, int pvm, int f, int manamax) : Personnage(name, pvm, f) {
		mana_max = manamax;
		mana = mana_max;
	}
	virtual void Agir(Personnage&, Personnage* = nullptr);
	virtual void Restaurer(void) {
		Personnage::Restaurer();
		mana = mana_max;
	}
	int Getmana_max(void) const { return mana_max; }
	int Getmana(void) const { return mana; }
	const char* GetClasse(void) const { return "Mage"; }
	virtual void Afficher(void) const;
};

class Soigneur : public Personnage {
private:
	int mana;
	int mana_max;
public:
	Soigneur(const char* name, int pvm, int f, int manamax) : Personnage(name, pvm, f) {
		mana_max = manamax;
		mana = mana_max;
	}
	virtual void Agir(Personnage&, Personnage* = nullptr);
	virtual void Restaurer(void) {
		Personnage::Restaurer();
		mana = mana_max;
	}
	void Soigner(Personnage&) ;
	int Getmana_max(void) const { return mana_max; }
	int Getmana(void) const { return mana; }
	const char* GetClasse(void) const { return "Soigneur"; }
	virtual void Afficher(void) const;
};