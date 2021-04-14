#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Formes/Point.h"
#include "./Formes/Rectangle.h"
#include "./Formes/Disque.h"
#include "./Formes/Pool.h"


int main(int argc, char * argv[]) {
    // cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    // cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    string filename2 = "Sortie.bmp";

    cout << "(II) CImage pointer extraction" << endl;
    CImage   *img = new CImage(200, 200);
    // for(int i=0; i<200; i++){
    //     CPixel *p = img->getPixel(i, i);
    //     p->RGB(255,255,255);
    // }

    cout << "(II) New point" << endl;

    Pool* pool = new Pool();
    Forme* p = new Point(0, 0 , Couleur(255, 0, 0, 100));
    Forme* p2 = new Point(50, 50 , Couleur(0, 255, 0, 100));
    Forme* r1 = new Rectangle(80, 80, 20, 100, Couleur(0,0,255,100), Couleur(255,255,255,100));
    Forme* c1 = new Disque(100, 100, 20, Couleur(255, 255, 0, 100), Couleur(255,0,255, 100));
    Forme* c2 = new Disque(100, 110, 40, Couleur(255, 255, 0, 0), Couleur(255,100,0, 100));

    pool->add(p);
    pool->add(p2);
    pool->add(r1);
    pool->add(c1);
    pool->add(c2);

    pool->dessiner( img );
    cout << "Tag:" << p->get_tag() << endl;

    image->setImage( img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);
    return 1;
}

