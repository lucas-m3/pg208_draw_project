#ifndef __LIGNE_H_
#define __LIGNE_H_

#include "../Formes/Forme.h"

class Ligne : public Forme {
    private:
        int _x1;
        int _y1;
        int _x2;
        int _y2;

    public:
        Ligne();
        Ligne(int x1, int y1, int x2, int y2, Couleur fond);
        void dessiner(CImage *img);
        void set_coord(int x1, int y1, int x2, int y2);
};


#endif // __LIGNE_H_
