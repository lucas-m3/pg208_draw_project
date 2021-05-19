#include "Parser.h"

#include <iostream>
#include <vector>

#include "../Formes/Point.h"
#include "../Formes/Rectangle.h"
#include "../Formes/Carre.h"
#include "../Formes/Disque.h"
#include "../Formes/Ligne.h"
#include "../Formes/Couleur.h"

Parser::Parser() {}

/*
** returns false if parsing fails
*/
// TODO to upper before any processing ?
// TODO remove spaces
bool Parser::parse_file(string path, Pool* pool) {
    ifstream infile;
    string line;

    string id; //command identifier: RECTANGLE, ...
    vector<int> line_args; // command arguments

    int x_max = 0;
    int y_max = 0;

    infile.open(path);

    if(infile) {

        while(getline(infile, line)) {
            if(line.length()) {
                if(line.front() != '#') {    // ignore comments
                    int pos = line.find(":");

                    // get ID
                    id = line.substr(0, pos);
                    line.erase(0, pos+1);
                    // cout << "id: " << id << endl;

                    // get parameters
                    while(line.find(",") != string::npos) {
                        pos = line.find(",");
                        line_args.push_back(stoi(line.substr(0, pos)));
                        line.erase(0, pos+1);
                    }

                    //special case for last parameter
                    line_args.push_back(stoi(line.substr(0, line.find(";"))));

                    cout << "id " << id << endl;
                    //add form to pool
                    if( id.compare("RECTANGLE") == 0 ) {
                        cerr << "Creating rectangle " << line_args.size() << endl;
                        if(line_args.size() == 8) {
                            pool->add(new Rectangle(line_args[0], //x
                                                    line_args[1], //y
                                                    line_args[2], //l
                                                    line_args[3], //h
                                                    Couleur(line_args[4], //R
                                                            line_args[5], //G
                                                            line_args[6], //B
                                                            line_args[7]), //alpha
                                                    Couleur(0,0,0,0) //empty
                                                   ));
                            x_max = max(x_max, line_args[0] + line_args[2]);
                            y_max = max(y_max, line_args[1] + line_args[3]);
                        }
                        else if(line_args.size() == 9) { // with z index
                            pool->add(new Rectangle(line_args[0], //x
                                                    line_args[1], //y
                                                    line_args[2], //l
                                                    line_args[3], //h
                                                    Couleur(line_args[4], //R
                                                            line_args[5], //G
                                                            line_args[6], //B
                                                            line_args[7]), //alpha
                                                    Couleur(0,0,0,0), //empty
                                                    line_args[8] //z index
                                                   ));
                            x_max = max(x_max, line_args[0] + line_args[2]);
                            y_max = max(y_max, line_args[1] + line_args[3]);
                        }
                    }
                    else if( id.compare("CARRE") == 0 ) {
                        if(line_args.size() == 7) {
                            cerr << "Creating square" << endl;
                            pool->add(new Carre(line_args[0], //x
                                                line_args[1], //y
                                                line_args[2], //c
                                                Couleur(line_args[3], //R
                                                        line_args[4], //G
                                                        line_args[5], //B
                                                        line_args[6]), //
                                                Couleur(0,0,0,0) //empty
                                    ));
                            x_max = max(x_max, line_args[0] + line_args[2]);
                            y_max = max(y_max, line_args[1] + line_args[2]);
                        }
                    }
                    else if( id.compare("CERCLE") == 0 ) {
                        if(line_args.size() == 7) {
                            pool->add(new Disque(line_args[0], //x
                                                 line_args[1], //y
                                                 line_args[2], //radius
                                                 Couleur(line_args[3], //R
                                                         line_args[4], //G
                                                         line_args[5], //B
                                                         line_args[6]), //alpha
                                                 Couleur(0,0,0,0) //empty
                                      ));
                            x_max = max(x_max, line_args[0] + line_args[2]);
                            y_max = max(y_max, line_args[1] + line_args[2]);
                        }
                    }
                    else if( id.compare("POINT") == 0 ) {
                        if(line_args.size() == 6) {
                            pool->add(new Point(line_args[0], //X
                                                line_args[1], //y
                                                Couleur(line_args[2], //R
                                                        line_args[3], //G
                                                        line_args[4], //B
                                                        line_args[5]) //alpha
                                      ));
                            x_max = max(x_max, line_args[0]);
                            y_max = max(y_max, line_args[1]);
                        }
                    }
                    else if( id.compare("LIGNE") == 0 ) {
                        if(line_args.size() == 8) {
                            pool->add(new Ligne(line_args[0], //X1
                                                line_args[1], //y1
                                                line_args[2], //x2
                                                line_args[3], //y2
                                                Couleur(line_args[4], //R
                                                        line_args[5], //G
                                                        line_args[6], //B
                                                        line_args[7]) //alpha
                                      ));
                            x_max = max(x_max, max(line_args[0], line_args[2]));
                            y_max = max(y_max, max(line_args[1], line_args[3]));
                        }
                    }

                    line_args.clear();
                }
                cout << "xmax " << x_max << " ymax " << y_max << endl;
            }
        }

        infile.close();
        return true;
    }
    else {
        cerr << "ERROR: Could not open file " << path << endl;
        return false;
    }
}
