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
    public:
        Forme();
        virtual void dessiner(CImage *img) = 0;

        string get_tag();
        void set_tag(string str);

        int get_x();
        int get_y();
        Couleur get_fond();
        Couleur get_contour();

        void set_x(int x);
        void set_y(int y);
        void set_fond(Couleur fond);
        void set_contour(Couleur contour);
};

#endif // __FORME_H_
