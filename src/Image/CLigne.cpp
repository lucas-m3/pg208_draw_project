/*
 *  CLigne.cpp
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include "CLigne.h"

CLigne::CLigne(int _taille){
    //cout << "Instanciation des colonnes... " << taille << endl;
    taille = _taille;
    ligne = (CPixel**)new CPixel**[taille];
    for(int i=0; i<taille; i++)
        ligne[i] = new CPixel();
}

CLigne::CLigne(){
}

CLigne::~CLigne(){
    for(int i=0; i<taille; i++)
        delete ligne[i];
    delete[] ligne;
}

int CLigne::size(){
    return taille;
}

CPixel* CLigne::getPixel(int position){
    if( (position >= taille) || position < 0 ){
        cerr << "CLigne::getPixel => trying to access " << position << " but the line has only " << taille << " data" << endl;
    }
    return (position < taille && position >= 0)?ligne[position]:NULL;
}
