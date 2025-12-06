#include <iostream>

#include "catalogue.hpp"
#include "transport.hpp"

enum UIOptions   
{
    OPTION_AJOUT_TRAJET = 1,
    OPTION_MODIF_TRAJET,
    OPTION_RECHERCHE_TRAJET,
    OPTION_DISPLAY_ALL,
    OPTION_EXIT
};

int main(){


    std::cout<<"- Opti traj - "<<std::endl;

    int user_choice = 0;
    Catalogue catalogue = Catalogue();
    Noeud *traj;
    char * v_a = new char[50],*v_b = new char[50], *t = new char[30];

    while(user_choice != OPTION_EXIT)
    {
        std::cout<<"========================================" << std::endl;
        std::cout<<"[1] Ajouter un trajet"<<std::endl;
        std::cout<<"[2] Modifier un trajet"<<std::endl;
        std::cout<<"[3] Rechercher un trajet"<<std::endl;
        std::cout<<"[4] Afficher tous les trajets"<<std::endl;
        std::cout<<"[5] Quitter"<<std::endl;

        std::cout<< ">";
        std::cin >> user_choice ;

        
        switch(user_choice)
        //#FIXME : dans le cas ou l'utilisateur rentre autre chose qu'un chiffre, boucle à l'infini!!
        {
            case OPTION_AJOUT_TRAJET:
                std::cout<<"Ajout d'un trajet"<<std::endl;
                std::cout<<"Ville de départ : "<<std::endl;
                std::cin>>v_a;
                std::cout<<"Ville d'arrivée : "<<std::endl;
                std::cin>>v_b;
                std::cout<<"Mode de transport : "<<std::endl;
                std::cin>>t;
                traj = new Trajet((Ville) v_a, (Ville) v_b, Transport::AUTO);
                //traj = new Trajet((Ville)v_a, (Ville)v_b, Str2Transport(&t));
                //j'arrive pas a l'utiliser aled
                std::cout<<"Trajet créé. Ajout au catalogue"<<std::endl;
                catalogue.AjouterTrajet(traj);
                //#FIXME : cleanup des méthodes redondantes              
                break;
            case OPTION_MODIF_TRAJET:
                std::cout<<"Modifier un trajet : option non implémentée car non demandé:)"<<std::endl;
                break;
            case OPTION_RECHERCHE_TRAJET:
                std::cout<<"Rechercher un trajet : en debug ^^"<<std::endl;
                break;
            case OPTION_DISPLAY_ALL:
                std::cout<<"Afficher tous les trajet : en debug^^"<<std::endl;
                catalogue.Afficher();
                //#FIXME : soit l'affichage est foireux, soit la créationd des trajets l'est. debug individuellement
                break;
            case OPTION_EXIT:
                std::cout<<"Au revoir!"<<std::endl;
                break;
            default:
                std::cout<<"Option invalide, réessayez."<<std::endl;
                break;
        }
    }

    delete []v_a; delete[] v_b; delete[] t;
    return 0;
}