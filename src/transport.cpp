//---------- Réalisation de la classe <Transport> (fichier Transport.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------------ Include système
using namespace std;
#include <iostream>
#include <string.h>

//---------------------------------------------------------- Include personnel
#include "transport.hpp"

//----------------------------------------------------------------- Constantes

//--------------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Méthodes publiques

const char * Transport2Str ( Transport val )
// Mode d'emploi :
// Convertit un Transport en chaîne de caractères
//
// Contrat :
// val doit être un Transport valide
//
{
    switch (val)
    {
    case Transport::AUTO:
        return "auto";
    case Transport::TRAIN:
        return "train";
    case Transport::METRO:
        return "metro";
    case Transport::BATEAU:
        return "bateau";
    case Transport::VELO:
        return "velo";
    default:
        return "inconnu";
    }
} //----- Fin de Transport2Str

Transport Str2Transport ( const char * val )
// Mode d'emploi :
// Convertit une chaîne de caractères en Transport
//
// Contrat :
// val doit être un Transport valide
//
{
    // formattage de la chaine de caractère

    if (strncasecmp(val,"AUTO", strlen(val))==0)
    {
        return Transport::AUTO;
    }
    else if (strncasecmp(val, "TRAIN", strlen(val))==0)
    {
        return Transport::TRAIN;
    }
    else if (strncasecmp(val,"METRO",strlen(val)) == 0)
    {
        return Transport::METRO;
    }
    else if (strncasecmp(val,"BATEAU", strlen(val))==0)
    {
        return Transport::BATEAU;
    }
    else if (strncasecmp(val,"VELO", strlen(val))==0)
    {
        return Transport::VELO;
    }
    else
    {
        return Transport::UNKNOWN;
    }
} //----- Fin de Str2Transport

//---------------------------------------------------------------------- PRIVE

//--------------------------------------------------------- Méthodes protégées
