#ifndef __CARRE_H_
#define __CARRE_H_

#include "Rectangle.h"

class Carre : public Rectangle {
    private:
    public:
        Carre();
        Carre(int x, int y, int cote, Couleur fond, Couleur contour);
};


#endif // __CARRE_H_
