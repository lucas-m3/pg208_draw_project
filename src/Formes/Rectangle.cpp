#include "Rectangle.h"


Rectangle::Rectangle() {
    set_tag("rectangle NI");
    set_x(0);
    set_y(0);
    set_longueur(0);
    set_hauteur(0);
    set_fond(Couleur());
    set_contour(Couleur());
}

Rectangle::Rectangle(int x, int y, int longueur, int hauteur,
                     Couleur fond, Couleur contour) {
    set_tag("rectangle");
    set_x(x);
    set_y(y);
    set_longueur(longueur);
    set_hauteur(hauteur);
    set_fond(fond);
    set_contour(contour);
}

void Rectangle::dessiner(CImage *img) {
    int x, y;
    int x0 = get_x();
    int y0 = get_y();

    //draw horizontal lines
    y = y0;
    for(x = x0; x < x0 + _l; x++) {
        CPixel *p1 = img->getPixel(x, y);
        CPixel *p2 = img->getPixel(x, y + _h);
        Couleur c = get_contour();

        if(p1 != NULL) p1->RGB(c._R, c._G, c._B, c._alpha);
        if(p2 != NULL) p2->RGB(c._R, c._G, c._B, c._alpha);
    }

    //draw vertical lines
    x = y0;
    for(y = y0; y < y0 + _h + 1; y++) {
        CPixel *p1 = img->getPixel(x, y);
        CPixel *p2 = img->getPixel(x + _l, y);
        Couleur c = get_contour();

        if(p1 != NULL) p1->RGB(c._R, c._G, c._B, c._alpha);
        if(p2 != NULL) p2->RGB(c._R, c._G, c._B, c._alpha);
    }

    //fill rectangle
    for(x = x0 + 1; x < x0 + _l; x++) {
        for(y = y0 + 1; y < y0 + _h; y++) {
            CPixel *p = img->getPixel(x, y);
            Couleur c = get_fond();
            if(p != NULL) p->RGB(c._R, c._G, c._B, c._alpha);
        }
    }
}

void Rectangle::set_hauteur(int h) {
    _h = h;
}

void Rectangle::set_longueur(int l) {
    _l = l;
}
