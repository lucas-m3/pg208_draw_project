#include "Ligne.h"


Ligne::Ligne() {
    set_tag("ligne NI"); //Non Initialisé
}

Ligne::Ligne(int x1, int y1, int x2, int y2, Couleur fond) {
    set_tag("ligne");
}

void Ligne::dessiner(CImage *img) {

}

void Ligne::set_coord(int x1, int y1, int x2, int y2) {

}
