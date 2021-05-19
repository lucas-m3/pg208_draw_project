#include "Disque.h"
#include <math.h>

Disque::Disque() : Forme()
{
    set_tag("disque NI");
    set_radius(0);
}

Disque::Disque(int x, int y, int radius, Couleur fond, Couleur contour) :
    Forme(x, y, fond, contour)
{
    set_tag("disque");
    set_radius(radius);
}

Disque::Disque(int x, int y, int radius, Couleur fond, Couleur contour, int z_index) :
    Forme(x, y, fond, contour, z_index)
{
    set_tag("disque");
    set_radius(radius);
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
                    p->RGB(f._R, f._G, f._B, f._alpha);
                }
            }
            //contour
            else if(eq >= r_squared && eq <= r_squared + 2*_r) {
                if(p != NULL && c._alpha != 0) {
                    p->RGB(c._R, c._G, c._B, c._alpha);
                }
            }
        }
    }

}

void Disque::set_radius(int r) {
    _r = r;
}
