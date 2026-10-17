class Armee {
private:
	ChaineCar nom;
	Personnage** membres; // Pointeur qui pointe vers des cases qui contiennent des personnages dynamiques (Guerriers, Mages...)
	// membres est une adresse de la premiere case d'un tableau qui contient des adresses de Personnage (nom (qui est une adresse d'une zone de caracteres), force, PV...).
	int nb_membres;
	int capacite;
public:
	Armee(const char* nom_armee, int capa);
	const ChaineCar GetNom() const { return nom; }
	int GetNombreMembres() const { return nb_membres; }

	bool Ajouter(Personnage* nouveau);
	Personnage* GetMembre(int indice) const {
		Personnage* rep = nullptr;
		if (indice >= 0 && indice <= nb_membres) {
			rep = membres[indice];
		}
		return rep;
	}
	void Afficher(void) const;
	~Armee(void) {
		for (int i = 0; i < nb_membres; i++) {
			delete membres[i]; // Est appele: le destrcuteur de Personnage, puis arme, puis nom du personnage, nom de l'arme ect...
		}
		delete [] membres;
	}
	bool EstVaincue() const;
	Personnage* PremierVivant() const;
	Personnage* ChoisirCibleSoin() const;
	void Agir(Personnage& ennemi);
	void Restaurer();
	bool EquiperMembre(int indice, Arme* nouvellearme);
};