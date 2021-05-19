#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Forme.h"

class Rectangle : public Forme {
    private:
        int _h;
        int _l;
    public:
        Rectangle();
        Rectangle(int x, int y, int longueur, int hauteur, Couleur fond, Couleur contour);
        Rectangle(int x, int y, int longueur, int hauteur, Couleur fond, Couleur contour,
                  int z_index);
        void dessiner(CImage *img);
        void set_hauteur(int h);
        void set_longueur(int l);
};

#endif // __RECTANGLE_H_
