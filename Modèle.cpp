#include "Modèle.h"

void Modèle::appelfiltres1()
{
    Filtres a;
    a.canny();
    
}

void Modèle::appelfiltres2()

{
    Filtres a;    a.median();
}

void Modèle::appelfiltres3()
{
    Filtres a; a.gaussien();
}

void Modèle::appelfiltres4()
{
    Filtres a; a.dilatation();
}

void Modèle::appelfiltres5()
{
    Filtres a; a.erosion();
}

void Modèle::appelfiltres6()
{
    Filtres a; a.grad();
}

void Modèle::appelfiltres7()
{
    Filtres a; a.seuillages();
}

void Modèle::appelfiltres8()
{
    Filtres a; a.croissance_region();
}
