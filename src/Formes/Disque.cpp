#include "Disque.h"
#include <math.h>

Disque::Disque() {
    set_tag("disque");
    cerr << "creation disque" << endl;
    set_x(0);
    set_y(0);
    set_radius(0);
    set_fond(Couleur());
    set_contour(Couleur());
}

Disque::Disque(int x, int y, int radius, Couleur fond, Couleur contour) {
    Disque();
    set_x(x);
    set_y(y);
    set_radius(radius);
    set_fond(fond);
    set_contour(contour);
}

void Disque::dessiner(CImage *img) {
    int x0 = get_x();
    int y0 = get_y();
    Couleur c = get_contour();
    Couleur f = get_fond();


    for(int x = x0 - _r; x <= x0 + _r; x++) {
        for(int y = y0 - _r; y <= y0 + _r; y++) {
            CPixel *p = img->getPixel(x, y);
            int eq = (int)pow((float)(x - x0), 2.0) + pow((float)(y - y0), 2.0);
            int r_squared = (int)pow((float)_r, 2.0);

            // fond
            if(eq < r_squared) {
                if(p != NULL && f._alpha != 0) {
                    p->RGB(f._R, f._G, f._B);
                }
            }
            //contour
            else if(eq >= r_squared && eq <= r_squared + 2*_r) {
                if(p != NULL && c._alpha != 0) {
                    p->RGB(c._R, c._G, c._B);
                }
            }
        }
    }

}

void Disque::set_radius(int r) {
    _r = r;
}
