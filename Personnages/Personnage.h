

class Personnage {
private:
	ChaineCar nom;
	int PV;
	int PVmax;
	int force;
	Arme* armeequipee;
public:
	Personnage(const char*, int, int);

	const ChaineCar& GetNom(void) const { return nom; }
	int GetPV(void) const { return PV; }
	int GetPVmax(void) const { return PVmax; }
	int GetForce(void) const { return force; }
	virtual void Afficher(void) const;

	bool EstVivant(void) const {
		bool vivant;
		if (PV > 0) {
			vivant = true;
		}
		else {
			vivant = false;
		}
		return vivant;
	}

	bool PossedeArme(void) const {
		bool possede;
		if (armeequipee == nullptr) {
			possede = false;
		}
		else {
			possede = true;
		}
		return possede;
	}

	virtual void RecevoirDegats(int);
	void Attaquer(Personnage&) const;
	void Equiper(Arme*);
	Arme* AbandonnerArme(void);
	bool RecupererArme(Personnage&);

	virtual void Restaurer(void) { PV = PVmax; }
	void RecevoirSoin(int);
	void Attaquer(Personnage&, int, const char*) const;
	virtual void Agir(Personnage&, Personnage* = nullptr);
	virtual ~Personnage();
};