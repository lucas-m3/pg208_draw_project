#include "Forme.h"

Forme::Forme() {
    _fond = Couleur(255, 255, 255, 100);
}

string Forme::get_tag() {
    return _tag;
}
void Forme::set_tag(string str) {
    _tag = str;
}

int Forme::get_x() {
    return _x;
}

int Forme::get_y() {
    return _y;
}

Couleur Forme::get_fond() {
    return _fond;
}

Couleur Forme::get_contour() {
    return _contour;
}

// TODO sanitize user input
void Forme::set_x(int x) {
    _x = x;
}

void Forme::set_y(int y) {
    _y = y;
}

void Forme::set_fond(Couleur fond) {
    _fond = fond;
}

void Forme::set_contour(Couleur contour) {
    _contour = contour;
}
