//---------- Interface de la classe <Transport> (fichier Transport.h) ----------------
#if ! defined ( TRANSPORT_H )
#define TRANSPORT_H

//------------------------------------------------------- Interfaces utilisées

//----------------------------------------------------------------- Constantes

//---------------------------------------------------------------------- Types

enum Transport 
{
    AUTO,
    TRAIN,
    METRO,
    BATEAU,
    VELO,
    UNKNOWN
};

//----------------------------------------------------------------------------
// Rôle de l'énumération <Transport>
// Liste tous les moyens de transport possibles
//----------------------------------------------------------------------------

//-------------------------------------------------------- Fonctions publiques

const char * Transport2Str ( Transport val );
// Mode d'emploi :
// Convertit un Transport en chaîne de caractères
// Exemple : Transport2Str(Transport::TRAIN) => "train"
//
// Contrat :
// val doit être un Transport valide
// La chaîne retournée n'est pas une copie
//

Transport Str2Transport ( const char * val );
// Mode d'emploi :
// Convertit une chaîne de caractères en Transport
// Exemple : Str2Transport("Train") => TRAIN
//
// Contrat :
// val doit être un Transport valide
//

//------------------------------------ Autres définitions dépendantes de <Transport>

#endif // TRANSPORT_H 