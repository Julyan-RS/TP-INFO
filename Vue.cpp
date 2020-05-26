#include "Vue.h"

void Vue::display()

{
    bool y;
    while (y = 1)
    {       //Voici ce qui servira de menu
            int x;
            std::cout << "Veuillez choisir quel filtre effectuer sur La statue de la liberte!" << std::endl;
            std::cout << " 1.Filtres Canny" << std::endl;
            std::cout << " 2.Filtres Median" << std::endl;
            std::cout << " 3.Filtres Gaussien" << std::endl;
            std::cout << " 4.Filtres Dilatation" << std::endl;
            std::cout << " 5.Filtres Erosion" << std::endl;
            std::cout << " 6.Filtres Gradient" << std::endl;
            std::cout << " 7.Filtres Seuillages" << std::endl;
            std::cout << " 8.Filtres Croissance par region" << std::endl;

            std::cin >> x;
            // Ici j'appel les fonctions des filtres.
            if (x == 1) { Modèle a; a.appelfiltres1(); };
            if (x == 2) { Modèle a; a.appelfiltres2(); };
            if (x == 3) { Modèle a; a.appelfiltres3(); };
            if (x == 4) { Modèle a; a.appelfiltres4(); };
            if (x == 5) { Modèle a; a.appelfiltres5(); };
            if (x == 6) { Modèle a; a.appelfiltres6(); };
            if (x == 7) { Modèle a; a.appelfiltres7(); };
            if (x == 8) { Modèle a; a.appelfiltres8(); };

            //Cette commande va permettre de nettoyer le terminal
            system("CLS");
        }

}
