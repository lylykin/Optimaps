#include <iostream>

#include "catalogue.hpp"
#include "transport.hpp"

enum UIOptions
{
    OPTION_AJOUT_TRAJET = 1,
    OPTION_MODIF_TRAJET,
    OPTION_RECHERCHE_TRAJET,
    OPTION_RECHERCHE_PROFONDEUR,
    OPTION_DISPLAY_ALL,
    OPTION_EXIT
};

void test()
{

    // test1 : affichage d'un trajet => concluant

    // Ville a besoin d'une allocation dynamique pour eviter un crash
    Trajet *traj = new Trajet((Ville) "Ville_dep", (Ville) "Ville_arr", Transport::AUTO);
    // traj.Afficher();

    // test2 : affichage de liste chainée=> ne marche pas
    ListeChainee list ;
    list.AjouterNoeud(traj);
    list.Afficher();
}

int main()
{
    // test();
    // return 0;

    std::cout << "- Opti traj - " << std::endl;

    int user_choice = 0;
    Catalogue catalogue ;
    Noeud *traj;
    char *v_a = new char[50];
    char *v_b = new char[50];
    char *t = new char[30];

    while (user_choice != OPTION_EXIT)
    {
        std::cout << "========================================" << std::endl;
        std::cout << "[1] Ajouter un trajet" << std::endl;
        std::cout << "[2] Modifier un trajet" << std::endl;
        std::cout << "[3] Rechercher un trajet" << std::endl;
        std::cout << "[4] Rechercher un trajet (profondeur)" << std::endl;
        std::cout << "[5] Afficher tous les trajets" << std::endl;
        std::cout << "[6] Quitter" << std::endl;

        std::cout << ">";
        std::cin >> user_choice;

        switch (user_choice)
        // #FIXME : dans le cas ou l'utilisateur rentre autre chose qu'un chiffre, boucle à l'infini!!
        {
        case OPTION_AJOUT_TRAJET:
        {
            std::cout << "Ajout d'un trajet" << std::endl;
            std::cout << "Ville de départ : " << std::endl;
            std::cin >> v_a;
            std::cout << "Ville d'arrivée : " << std::endl;
            std::cin >> v_b;
            std::cout << "Mode de transport : " << std::endl;
            std::cin >> t;
            traj = new Trajet(v_a, v_b, Transport::AUTO);
            std::cout << "Trajet créé. Ajout au catalogue" << std::endl;
            catalogue.AjouterTrajet(traj);
            // #FIXME : cleanup des méthodes redondantes
            break;
        }
        case OPTION_MODIF_TRAJET:
        {
            // #FIXME : supprimer cette option car non demandée
            std::cout << "Modifier un trajet : option non implémentée car non demandé:)" << std::endl;

            break;
        }
        case OPTION_RECHERCHE_TRAJET:
        {
            std::cout << "Ville de départ : " << std::endl;
            std::cin >> v_a;
            std::cout << "Ville d'arrivée : " << std::endl;
            std::cin >> v_b;

            Noeud *result = catalogue.Recherche((Ville)v_a, (Ville)v_b);
            if (result != nullptr)
            {
                std::cout << "Trajet trouvé :" << std::endl;
                result->Afficher();
            }
            else
            {
                std::cout << "Aucun trajet trouvé. (essayez la recherche profondeur ?)" << std::endl;
            }

            break;
        }
     
        case OPTION_RECHERCHE_PROFONDEUR:
        {
            std::cout << "Ville de départ : " << std::endl;
            std::cin >> v_a;
            std::cout << "Ville d'arrivée : " << std::endl;
            std::cin >> v_b;

            Pile result = catalogue.RechercheProfondeur((Ville)v_a, (Ville)v_b);
            if (result.taille() > 0)
            {
                result.Afficher();
            }
            else
            {
                std::cout << "Aucun trajet trouvé." << std::endl;
            }

            break;
        }
        case OPTION_DISPLAY_ALL:
        {
            std::cout << "Afficher tous les trajet : " << std::endl;
            catalogue.Afficher();
            // #FIXME : problème d'affichage
            break;
        }
        case OPTION_EXIT:
        {
            std::cout << "Au revoir!" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Option invalide, réessayez." << std::endl;
            break;
        }
        }
    }

    delete[] v_a;
    delete[] v_b;
    delete[] t;
    return 0;
}