#include <iostream>

#include "../ChaineCar/ChaineCar.h"
#include "../Armes/Arme.h"
#include "../Armes/ArmesSpecialisees.h"
#include "../Personnages/Personnage.h"
#include "../Personnages/PersonnageSpecialises.h"
#include "../Armee/Armee.h"
#include "../CombatGroupe/CombatGroupe.h"


// Fonctions appelées dans le main, manipulant Armée et Personnage
// Déclaration implicite via la définition directement dans le main.cpp

bool AjouterMembre(Armee& armee, Personnage* candidat)
{
    bool ajoute;

    ajoute = armee.Ajouter(candidat);
    if (!ajoute)
    {
        delete candidat;
    }
    return ajoute;
}

bool DonnerButin(Armee& armee, int indice, Personnage& ennemi)
{
    Arme* butin;
    bool equipee;

    butin = ennemi.AbandonnerArme();
    equipee = armee.EquiperMembre(indice, butin);
    if (!equipee)
    {
        delete butin;
    }
    return equipee;
}

int main()
{
    Armee compagnie("Compagnie de l'Aube", 3);
    bool creationCorrecte=true;

    // Si l'ajout des membres pose problème
    if (!AjouterMembre(compagnie, new Guerrier("Borin", 120, 7)))
    {
        creationCorrecte = false;
    }
    if (!AjouterMembre(compagnie, new Mage("Lyra", 85, 5, 40)))
    {
        creationCorrecte = false;
    }
    if (!AjouterMembre(compagnie, new Soigneur("Mira", 95, 4, 48)))
    {
        creationCorrecte = false;
    }

    // Si l'armée a bien été remplie, on peut équiper les armes de départ aux différents membres
    if (creationCorrecte)
    {
	CombatGroupe c;// Attributs vide, simplement utilisé pour appeler la méthode Combattre

        compagnie.EquiperMembre(0,new ArmeCorpsACorps("Epee d'entrainement", 1));
        compagnie.EquiperMembre(1,new ArmeMagique("Baton d'apprenti", 1));
        compagnie.EquiperMembre(2,new ArmeDistance("Sceptre use", 1));

        std::cout << "=== Etat initial de l'armee ===\n";
        compagnie.Afficher();

        std::cout << "\n=== Essai premature contre le mage du pont ===\n";
        {
            Mage magePont("Mage du pont", 380, 12, 50);
	    bool victoire;
            magePont.Equiper(new ArmeMagique("Orbe du pont", 5));
            victoire = c.Combattre(compagnie, magePont, 30);
            if(!victoire)
            {
               std::cout<<"\tPas de Miracle ! Vous n'etes pas pret!!\n";
            }
        }
        compagnie.Restaurer();

        std::cout << "\n=== Recherche d'equipement chez les gobelins ===\n";
        for (int i = 0; i < compagnie.GetNombreMembres(); i = i + 1)
        {
            Guerrier chefGobelin("Chef gobelin", 135, 7);
            bool victoire;

            chefGobelin.Equiper(new ArmeCorpsACorps("Hache gobeline", 4));
            victoire = c.Combattre(compagnie, chefGobelin, 30);
            if (victoire)
            {
                DonnerButin(compagnie, i, chefGobelin);
            }
            compagnie.Restaurer();
        }

        std::cout << "\n=== Le mage du pont doit etre vaincu plusieurs fois ===\n";
        for (int i = 0; i < compagnie.GetNombreMembres(); i = i + 1)
        {
            Mage magePont("Mage du pont", 380, 12, 50);
            bool victoire;

            magePont.Equiper(new ArmeMagique("Orbe du pont", 6));
            victoire = c.Combattre(compagnie, magePont, 30);
            if (victoire)
            {
                DonnerButin(compagnie, i, magePont);
            }
            compagnie.Restaurer();
        }

        std::cout << "\n=== Gardien final ===\n";
        {
            Guerrier gardien("Gardien du donjon", 430, 16);
            bool victoireFinale;

            gardien.Equiper(new ArmeCorpsACorps("Marteau du gardien", 8));
            victoireFinale = c.Combattre(compagnie, gardien, 40);
            if (victoireFinale)
            {
                std::cout << "\nDonjon termine !\n";
            }
            else
            {
                std::cout << "\nLe gardien protege encore le donjon.\n";
            }
        }
    }
    else
    {
        std::cout << "Impossible de constituer l'armee.\n";
    }

    return 0;
}
