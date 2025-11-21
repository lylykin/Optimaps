//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "liste_chainee.hpp"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeChainee AjouterTete(const Trajet & trajet){
    
}


//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

ListeChainee::ListeChainee(){
    tete = nullptr;
    taille = 0;
}

ListeChainee::~ListeChainee()
{

    Noeud *res = tete;
    while (res != nullptr) 
    {
        res = res->getSuivant();        
        delete tete;
        tete = res;
    }
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

