#include <iostream>

#include"../ChaineCar/ChaineCar.h"
#include "../Armes/Arme.h"
#include "../Personnages/Personnage.h"
#include "../Armee/Armee.h"
#include "CombatGroupe.h"

bool CombatGroupe::Combattre(Armee& armee, Personnage& ennemi, int nombreToursMaximum)
{
    bool victoire;
    int tour;

    victoire = false;
    tour = 1;

    std::cout << "\n========================================\n";
    std::cout << armee.GetNom() << " affronte " << ennemi.GetNom() << '\n';

    while (!armee.EstVaincue() && ennemi.EstVivant() && tour <= nombreToursMaximum)
    {
        Personnage* cibleEnnemi;

        std::cout << "\nTour " << tour << '\n';
        armee.Agir(ennemi);

        if (ennemi.EstVivant() && !armee.EstVaincue())
        {
            cibleEnnemi = armee.PremierVivant();
            if (cibleEnnemi != nullptr)
            {
                ennemi.Agir(*cibleEnnemi);
            }
        }

        armee.Afficher();
        std::cout << "\nEnnemi :\n";
        ennemi.Afficher();
        tour = tour + 1;
    }

    if (!ennemi.EstVivant() && !armee.EstVaincue())
    {
        victoire = true;
        std::cout << "\nVictoire de l'armee.\n";
    }
    else
    {
        std::cout << "\nDefaite de l'armee.\n";
    }

    return victoire;
}
