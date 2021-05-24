#include "Ligne.h"

Ligne::Ligne() :
    Forme()
{
    set_tag("ligne NI"); //Non Initialisé
    set_coord(0, 0, 0, 0);
}

Ligne::Ligne(int x1, int y1, int x2, int y2, Couleur fond)
{
    set_tag("ligne");
    set_coord(x1, y1, x2, y2);
    set_fond(fond);
}

Ligne::Ligne(int x1, int y1, int x2, int y2, Couleur fond, int z_index) :
    Ligne(x1, y1, x2, y2, fond)
{
    set_z_index(z_index);
}

void Ligne::dessiner(CImage *img) {
    Couleur f = get_fond();
    float x1 = (float)_x1;
    float y1 = (float)_y1;
    float x2 = (float)_x2;
    float y2 = (float)_y2;

    int y;

    for(int x = _x1; x <= _x2 ; x++) {
        y = (int)( (y2 - y1)/(x2 - x1)*(x - x1) + y1 );
//        cout << "Ligne y: " << y << endl;
        CPixel *p = img->getPixel(x, y);
        if(p != NULL) p->RGB(f._R, f._G, f._B, f._alpha);
    }

}

void Ligne::set_coord(int x1, int y1, int x2, int y2) {
    // x1 and y1 must be inferior than x2 and y2
    if(x2 < x1) {
        _x1 = x2;
        _x2 = x1;
    }
    else {
        _x1 = x1;
        _x2 = x2;
    }

    if(y2 < y1) {
        _y1 = y2;
        _y2 = y1;
    }
    else {
        _y1 = y1;
        _y2 = y2;
    }
}
