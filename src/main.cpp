#include <iostream>

#include "catalogue.hpp"
#include "transport.hpp"

enum UIOptions
{
    OPTION_AJOUT_TRAJET_SIMPLE = 1,
    OPTION_AJOUT_TRAJET_COMPOSE,
    OPTION_RECHERCHE_TRAJET,
    OPTION_RECHERCHE_PROFONDEUR,
    OPTION_DISPLAY_ALL,
    OPTION_SAVE_CATALOG,
    OPTION_LOAD_CATALOG,
    OPTION_EXIT
};

int main()
{

    std::cout << "- Opti traj - " << std::endl;

    int user_choice = 0;
    Catalogue catalogue;
    Noeud *traj;
    char *v_a = new char[50];
    char *v_b = new char[50];
    char *t = new char[30];
    while (user_choice != OPTION_EXIT)
    {
        std::cout << "========================================" << std::endl;
        std::cout << "[1] Ajouter un trajet sans escale (simple)" << std::endl;
        std::cout << "[2] Ajouter un trajet avec escale (composé)" << std::endl;
        std::cout << "[3] Rechercher un trajet" << std::endl;
        std::cout << "[4] Rechercher un trajet (profondeur)" << std::endl;
        std::cout << "[5] Afficher tous les trajets" << std::endl;
        std::cout << "[6] Sauvegarder le catalogue" << std::endl;
        std::cout << "[7] Charger le catalogue à partir d'un fichier" << std::endl;
        std::cout << "[8] Quitter" << std::endl;

        std::cout << ">";
        std::cin >> user_choice;

        switch (user_choice)
        // #FIXME : dans le cas ou l'utilisateur rentre autre chose qu'un chiffre, boucle à l'infini (possiblilé d'amélioration)
        {
        case OPTION_AJOUT_TRAJET_SIMPLE:
        {
            std::cout << "Ajout d'un trajet sans escale" << std::endl;
            std::cout << "Ville de départ : " << std::endl;
            std::cin >> v_a;
            std::cout << "Ville d'arrivée : " << std::endl;
            std::cin >> v_b;
            std::cout << "Mode de transport : " << std::endl;
            std::cin >> t;
            traj = new Trajet(v_a, v_b, Str2Transport(t));
            std::cout << "Trajet créé. Ajout au catalogue" << std::endl;
            catalogue.AjouterTrajet(traj);
            break;
        }
        case OPTION_AJOUT_TRAJET_COMPOSE:
        {
            ListeChainee *liste_traj = new ListeChainee();

            // Ajout des trajets
            std::cout << "Ajout d'un trajet avec escale. Une fois la ville de destination finale tapée, taper 'Q'. " << std::endl;
            std::cout << "Ville de départ : " << std::endl;
            std::cin >> v_a;

            do
            {
                std::cout << "Ville suivante : " << std::endl;
                std::cin >> v_b;
                if (strcasecmp(v_b, "Q") == 0)
                {
                    break;
                }
                std::cout << "Mode de transport : " << std::endl;

                std::cin >> t;
                traj = new Trajet(v_a, v_b, Str2Transport(t));
                liste_traj->AjouterFin(traj);

                strcpy(v_a, v_b);

            } while (strcasecmp(v_b, "Q") != 0);
            std::cout << "Trajet créé. Ajout au catalogue" << std::endl;
            catalogue.AjouterTrajet(liste_traj);

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
                std::cout << std::endl;
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
        case OPTION_SAVE_CATALOG:
        {
            std::ofstream fic("./catalogue.txt");

            catalogue.EnregistrerCatalogue(fic);
            fic.close();
            break;
        }
        case OPTION_LOAD_CATALOG:
        {
            std::ifstream fic("catalogue.txt");
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