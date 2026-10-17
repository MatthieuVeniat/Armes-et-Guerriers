
class ArmeCorpsACorps : public Arme {
public:
	ArmeCorpsACorps(const char* name, int b);
	virtual int CalculerDegats(int puissanceBase) const { return Arme::GetBonusDegats() + puissanceBase + 2; };
	virtual const char* GetType(void)const { return "corps a corps"; }
};

class ArmeDistance : public Arme {
public:
	ArmeDistance(const char* name, int b);
	virtual int CalculerDegats(int puissanceBase) const { return Arme::GetBonusDegats() + puissanceBase + 1; };
	virtual const char* GetType(void)const { return "arme distance"; }
};

class ArmeMagique : public Arme {
public:
	ArmeMagique(const char* name, int b);
	virtual int CalculerDegats(int puissanceBase) const { return 2*Arme::GetBonusDegats() + puissanceBase; };
	virtual const char* GetType(void)const { return "arme magique"; }
};

class ArmeDeBase : public Arme {
public:
	ArmeDeBase(const char* name, int b);
	virtual int CalculerDegats(int puissanceBase) const { return Arme::GetBonusDegats() + puissanceBase; };
	virtual const char* GetType(void)const { return "arme de base"; }
};
