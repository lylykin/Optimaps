#include <iostream>

#include "catalogue.hpp"

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
        {
            case OPTION_AJOUT_TRAJET:
                std::cout<<"Ajouter un trajet"<<std::endl;
                std::cin>>v_a;
                std::cin>>v_b;
                std::cin>>t;
                traj = new Trajet((Ville)v_a, (Ville)v_b, Transport::AUTO);
                std::cout<<"trajet créé. ajout au catalogue"<<std::endl;
                //#FIXME : implémenter un string2trans dans transport pour personnaliser
                catalogue.AjouterTrajet(traj);
                //#FIXME : place out of range
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