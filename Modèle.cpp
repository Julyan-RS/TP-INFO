#include "Mod�le.h"

void Mod�le::appelfiltres1()
{
    Filtres a;
    a.canny();
    
}

void Mod�le::appelfiltres2()

{
    Filtres a;    a.median();
}

void Mod�le::appelfiltres3()
{
    Filtres a; a.gaussien();
}

void Mod�le::appelfiltres4()
{
    Filtres a; a.dilatation();
}

void Mod�le::appelfiltres5()
{
    Filtres a; a.erosion();
}

void Mod�le::appelfiltres6()
{
    Filtres a; a.grad();
}

void Mod�le::appelfiltres7()
{
    Filtres a; a.seuillages();
}

void Mod�le::appelfiltres8()
{
    Filtres a; a.croissance_region();
}
