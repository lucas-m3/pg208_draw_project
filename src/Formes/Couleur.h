#ifndef __COULEUR_H_
#define __COULEUR_H_

class Couleur {
    public:
        int _R;
        int _G;
        int _B;
        int _alpha; // 0->invisible, 100->opaque

        Couleur();
        Couleur(int R, int G, int B, int alpha);
};

#endif // __COULEUR_H_
