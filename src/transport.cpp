#include "transport.hpp"
#include <iostream>
#include <stddef.h>
#include <string.h>

const char *Transport2Str(Transport val)
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
}

Transport Str2Transport(const char *val)
// #QUESTION j'ai du enlever le const, mais est-ce que c'est une bonne idée/philo?
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
}
