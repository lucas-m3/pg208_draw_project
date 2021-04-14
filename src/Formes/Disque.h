#ifndef __DISQUE_H_
#define __DISQUE_H_


#include "Forme.h"

class Disque : public Forme {
    private:
        int _r; //radius
    public:
        Disque();
        Disque(int x, int y, int radius, Couleur fond, Couleur contour);
        void dessiner(CImage *img);
        void set_radius(int r);
};

#endif // __DISQUE_H_
