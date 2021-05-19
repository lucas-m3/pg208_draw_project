#include "Carre.h"

Carre::Carre() {
    set_tag("carre NI");
}

Carre::Carre(int x, int y, int cote, Couleur fond, Couleur contour) :
    Rectangle(x, y, cote, cote, fond, contour)
{
    set_tag("carre");
}

Carre::Carre(int x, int y, int cote, Couleur fond, Couleur contour, int z_index) :
    Carre(x, y, cote, fond, contour) {
    set_z_index(z_index);
}
