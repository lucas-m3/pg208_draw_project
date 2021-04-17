#include "Carre.h"

Carre::Carre() {
    set_tag("carre NI");
}

Carre::Carre(int x, int y, int cote, Couleur fond, Couleur contour) :
    Rectangle(x, y, cote, cote, fond, contour)
{
    set_tag("carre");
}
