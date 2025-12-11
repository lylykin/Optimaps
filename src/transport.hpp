#if !defined(TRANSPORT_H)
#define TRANSPORT_H


// Rôle de l'énum Transport :
// Liste tout les moyens de transport possible

// Pourquoi une énum ? Car les moyens de transports sont fixés
// Et il n'y a pas d'intérêt de les afficher en string 
// Car la comparaison serait plus lente 

enum Transport 
{
    AUTO,
    TRAIN,
    METRO,
    BATEAU,
    VELO,
    UNKNOWN
};

const char* Transport2Str(Transport val);
// Mode d'emploi : 
//      Transport2Str(Transport::TRAIN) => "Train"
// Contrat : 
//      Val doit être un Transport valide <!> 
//      La chaine retournée n'est pas une copie  

Transport Str2Transport(const char * & val);
// Mode d'emploi : 
//      Str2Transport("Train") => TRAIN
// Contrat : 
//      Val doit être un Transport valide <!> 
//      La chaine retournée n'est pas une copie  
#endif 