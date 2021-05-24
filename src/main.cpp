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
#include "./Parser/Parser.h"

int main(int argc, char * argv[]) {
        if(argc < 3) {
                cout << "Not enough arguments" << endl;
                cout << "Use: main <input vec file> <outpu bitmap file>" << endl;
                exit(EXIT_FAILURE);
        }

        cout << "(II) Creating CBitmap object" << endl;
        CBitmap *image = new CBitmap();

        string vec_path(argv[1]);
        Parser parser;
        Pool* pool = new Pool();

        cout << "(II) Parsing file..." << endl;
        if(parser.parse_file(vec_path, pool) == 0) {
                cout << "Parsing failed" << endl;
                exit(EXIT_FAILURE);
        }

        cout << "(II) Bitmap dimensions: " << parser.get_width() << "x" << parser.get_height() << endl;
        CImage   *img = new CImage(parser.get_height(), parser.get_width());

        pool->dessiner( img );

        pool->print_pool();

        image->setImage( img );
        cout << "(II) Saving CBitmap image" << endl;
        image->SaveBMP(argv[2]);

        cout << "(II) Cleaning up" << endl;
        delete pool;
        delete img;
        delete image;
        return EXIT_SUCCESS;
}

