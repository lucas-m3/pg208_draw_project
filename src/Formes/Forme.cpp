#include "Forme.h"

Forme::Forme() {
    set_x(0);
    set_y(0);
    set_fond(Couleur());
    set_contour(Couleur());
    set_z_index(10);
}

Forme::Forme(int x, int y, Couleur fond, Couleur contour) {
    set_x(x);
    set_y(y);
    set_fond(fond);
    set_contour(contour);
    set_z_index(10);
}

Forme::Forme(int x, int y, Couleur fond, Couleur contour, int z_index) :
    Forme(x, y, fond, contour)
{
    set_z_index(z_index);
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

int Forme::get_z_index() {
    return _z_index;
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

void Forme::set_z_index(int z_index) {
    if( z_index >= 0 ) {
        _z_index = z_index;
    }
    else {
        cerr << "z index out of range" << endl;
        _z_index = 0;
    }
}
