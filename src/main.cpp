#include <iostream>

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
                break;
            case OPTION_MODIF_TRAJET:
                std::cout<<"Modifier un trajet"<<std::endl;
                break;
            case OPTION_RECHERCHE_TRAJET:
                std::cout<<"Rechercher un trajet"<<std::endl;
                break;
            case OPTION_DISPLAY_ALL:
                std::cout<<"Afficher tous les trajets"<<std::endl;
                break;
            case OPTION_EXIT:
                std::cout<<"Au revoir!"<<std::endl;
                break;
            default:
                std::cout<<"Option invalide, réessayez."<<std::endl;
                break;
        }
    }

    
    return 0;
}