#include <iostream>

#include "../ChaineCar/ChaineCar.h"
#include "../Armes/Arme.h"
#include "../Personnages/Personnage.h"
#include "Duel.h"

Personnage* Duel::Combattre(Personnage& premier, Personnage& second, Personnage* cibleSoinPremier, Personnage* cibleSoinSecond)
{
    Personnage* vainqueur;
    int tour;

    vainqueur = nullptr;
    tour = 1;

    std::cout << "\n=== Duel specialise ===\n";

    while (premier.EstVivant()
           && second.EstVivant()
           && tour <= 50)
    {
        std::cout << "\nTour " << tour << '\n';

        premier.Agir(second, cibleSoinPremier);

        if (second.EstVivant())
        {
            second.Agir(premier, cibleSoinSecond);
        }

        premier.Afficher();
        second.Afficher();

        tour = tour + 1;
    }

    if (premier.EstVivant() && !second.EstVivant())
    {
        vainqueur = &premier;
    }
    else
    {
        if (second.EstVivant() && !premier.EstVivant())
        {
            vainqueur = &second;
        }
    }

    if (vainqueur != nullptr)
    {
        std::cout << "Vainqueur : " << vainqueur->GetNom() << '\n';
    }
    else
    {
        std::cout << "Duel interrompu sans vainqueur.\n";
    }

    return vainqueur;
}
