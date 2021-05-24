#ifndef __FORME_H_
#define __FORME_H_

#include <string>
#include "../Image/CImage.h"
#include "Couleur.h"

class Forme {
    private:
        string _tag;
        Couleur _fond;
        Couleur _contour;
        int _x;
        int _y;
        int _z_index;

    public:
        Forme();
        Forme(int x, int y, Couleur fond, Couleur contour);
        Forme(int x, int y, Couleur fond, Couleur contour, int z_index);
        virtual ~Forme();

        virtual void dessiner(CImage *img) = 0;

        string get_tag();
        void set_tag(string str);

        int get_x();
        int get_y();
        Couleur get_fond();
        Couleur get_contour();
        int get_z_index();

        void set_x(int x);
        void set_y(int y);
        void set_fond(Couleur fond);
        void set_contour(Couleur contour);
        void set_z_index(int z_index);
};

#endif // __FORME_H_
