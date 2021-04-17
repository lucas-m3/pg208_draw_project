#include "Point.h"


Point::Point() {
    set_tag("point NI");
}

// Point::~Point() {}

Point::Point(int x, int y, Couleur c) {
    set_tag("point");
    set_x(x);
    set_y(y);
    set_fond(c);
}

void Point::dessiner(CImage *img) {
    CPixel *p = img->getPixel(get_x(), get_y());
    if(p != NULL) {
        Couleur c = get_fond();
        p->RGB(c._R, c._G, c._B);
    }
}
