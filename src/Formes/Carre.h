#ifndef __CARRE_H_
#define __CARRE_H_

#include "Rectangle.h"

class Carre : public Rectangle {
    private:
    public:
        Carre();
        Carre(int x, int y, int cote, Couleur fond, Couleur contour);
        Carre(int x, int y, int cote, Couleur fond, Couleur contour, int z_index);
};


#endif // __CARRE_H_
