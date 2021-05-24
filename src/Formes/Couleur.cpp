#include "Couleur.h"
#include <iostream>

Couleur::Couleur() {
    _R = 0;
    _G = 0;
    _B = 0;
    _alpha = 0;
}

Couleur::Couleur(int R, int G, int B, int alpha) {
    _R = R;
    _G = G;
    _B = B;
    if(alpha <= 100 && alpha >= 0) {
        _alpha = alpha;
    }
    else {
        std::cerr << "alpha out of range" << std::endl;
        _alpha = 100;
    }
}
