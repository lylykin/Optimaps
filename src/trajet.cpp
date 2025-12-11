/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "trajet.hpp"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Afficher(){
    std::cout << depart 
    <<" --> "<< arrivee
    <<" ("<< Transport2Str(trans)<<")" 
    << std::endl;
}

//------------------------------------------------- Surcharge d'opérateurs

Trajet & Trajet::operator=(const Trajet & traj)
{
    // cas spécial
    if(&traj == this)
    {
        return *this;
    }

    delete[] depart;
    delete[] arrivee;

    depart = new char[strlen(traj.depart)+1];
    arrivee = new char[strlen(traj.arrivee)+1];

    strcpy(depart, traj.depart );
    strcpy(arrivee, traj.arrivee);

    trans = traj.trans;


    return *this;
}


Trajet::Trajet(const Trajet& copie)
{

    // delete[] depart + delete[] arrivee non nécessaire vue qu'ils n'existent pas
    // cas spécial
    depart = new char[strlen(copie.depart)+1];
    arrivee = new char[strlen(copie.arrivee)+1];

    strcpy(depart, copie.depart );
    strcpy(arrivee, copie.arrivee);

    trans = copie.trans;
}

Trajet::Trajet(Ville vdepart, Ville varrivee, Transport transport)
    : trans(transport)
{
    size_t depart_len = strlen(vdepart);
    size_t arrivee_len = strlen(varrivee);

    depart = new char[depart_len + 1];
    arrivee = new char[arrivee_len + 1];

    strcpy(depart, vdepart );
    strcpy(arrivee, varrivee );
}

Trajet::~Trajet() 
{
    delete[] depart;
    delete[] arrivee;
}

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

