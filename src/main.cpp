#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Formes/Point.h"
#include "./Formes/Rectangle.h"
#include "./Formes/Carre.h"
#include "./Formes/Disque.h"
#include "./Formes/Ligne.h"
#include "./Formes/Pool.h"


int main(int argc, char * argv[]) {
    // cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    // cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) Creating CBitmap object" << endl;
    CBitmap *image = new CBitmap();
    string filename2 = "Sortie.bmp";

    cout << "(II) Extracting CImage pointer" << endl;
    CImage   *img = new CImage(2000, 2000);
    // for(int i=0; i<200; i++){
    //     CPixel *p = img->getPixel(i, i);
    //     p->RGB(255,255,255);
    // }

    cout << "(II) Creating new pool..." << endl;

    Pool* pool = new Pool();
    Forme* p = new Point(0, 0 , Couleur(255, 0, 0, 100));
    Forme* p2 = new Point(50, 50 , Couleur(0, 255, 0, 100));
    Forme* r1 = new Rectangle(80, 80, 20, 100, Couleur(0,0,255,100), Couleur(255,255,255,100));
    Forme* c1 = new Disque(100, 100, 20, Couleur(255, 255, 0, 100), Couleur(255,0,255, 100));
    Forme* c2 = new Disque(100, 110, 40, Couleur(255, 255, 0, 0), Couleur(255,100,0, 100));
    Forme* c3 = new Disque(100, 110, 100, Couleur(255, 255, 0, 0), Couleur(100,100,0, 100));
    Forme* c4 = new Disque(100, 1000, 400, Couleur(255, 255, 0, 0), Couleur(100,100,0, 100));
    // Forme* c5 = new Disque(1000, 1000, 2000, Couleur(255, 255, 0, 100), Couleur(100,100,0, 100));
    Forme *s1 = new Carre(1000, 1000, 300, Couleur(14, 244, 65, 100), Couleur(255, 62, 146, 100));
    Forme *l1 = new Ligne(0,0, 1999, 1999, Couleur(255, 0, 0, 100));
    Forme *l2 = new Ligne(500, 250, 0, 0, Couleur(0, 255, 0, 100));

    // pool->add(c5);
    pool->add(p);
    pool->add(p2);
    pool->add(r1);
    pool->add(c1);
    pool->add(c2);
    pool->add(c3);
    pool->add(c4);
    pool->add(s1);
    pool->add(l1);
    pool->add(l2);

    pool->print_pool();

    cout << "(II) Drawing image..." << endl;

    pool->dessiner( img );

    image->setImage( img );
    cout << "(II) Saving CBitmap image" << endl;
    image->SaveBMP(filename2);
    return 1;
}

