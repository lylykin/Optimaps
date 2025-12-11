//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------------ Include système
using namespace std;
#include <iostream>
#include <cstring>

//---------------------------------------------------------- Include personnel
#include "trajet.hpp"

//----------------------------------------------------------------- Constantes

//--------------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Méthodes publiques
void Trajet::Afficher ( ) const
// Mode d'emploi :
// Affiche le trajet (ville de départ, ville d'arrivée et moyen de transport)
{
    cout << depart 
    <<" --> "<< arrivee
    <<" ("<< Transport2Str(trans)<<")";
} //----- Fin de Afficher

//----------------------------------------------------- Surcharge d'opérateurs

Trajet & Trajet::operator = ( const Trajet & traj )
// Mode d'emploi :
// Opérateur d'affectation par copie
//
// Contrat :
// Crée une copie depuis traj
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
} //----- Fin de operator =

//------------------------------------------------ Constructeurs - destructeur

Trajet::Trajet ( const Trajet & copie )
// Mode d'emploi :
// Constructeur de copie
{

    // delete[] depart + delete[] arrivee non nécessaire vue qu'ils n'existent pas
    // cas spécial
    depart = new char[strlen(copie.depart)+1];
    arrivee = new char[strlen(copie.arrivee)+1];

    strcpy(depart, copie.depart );
    strcpy(arrivee, copie.arrivee);

    trans = copie.trans;
} //----- Fin de Trajet (constructeur de copie)

Trajet::Trajet ( const char * nom_depart, const char * nom_arrivee, Transport transport )
    : trans(transport)
// Mode d'emploi :
// Construit un trajet avec les paramètres fournis
//
// Contrat :
// Crée une copie des chaînes de caractères départ et arrivée
{
    size_t depart_len = strlen(nom_depart);
    size_t arrivee_len = strlen(nom_arrivee);

    depart = new char[depart_len + 1];
    arrivee = new char[arrivee_len + 1];

    strcpy(depart, nom_depart );
    strcpy(arrivee, nom_arrivee );
} //----- Fin de Trajet

Trajet::~Trajet ( )
{
    delete[] depart;
    delete[] arrivee;
} //----- Fin de ~Trajet

//---------------------------------------------------------------------- PRIVE

//--------------------------------------------------------- Méthodes protégées

