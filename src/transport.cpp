#include "transport.hpp"


const char* Transport2Str(Transport val)
{
    switch(val)
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
}
