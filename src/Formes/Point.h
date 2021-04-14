#ifndef __POINT_H_
#define __POINT_H_

#include "Forme.h"

class Point : public Forme {
    private:
    public:
        Point();
        // ~Point();
        Point(int x, int y, Couleur c);
        void dessiner(CImage *img);
};

#endif // __POINT_H_
