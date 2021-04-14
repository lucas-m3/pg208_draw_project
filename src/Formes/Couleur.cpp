#include "Couleur.h"

Couleur::Couleur() {
    _R = 0;
    _G = 0;
    _B = 0;
    _alpha = 100;
}

Couleur::Couleur(int R, int G, int B, int alpha) {
    _R = R;
    _G = G;
    _B = B;
    _alpha = alpha;
}
