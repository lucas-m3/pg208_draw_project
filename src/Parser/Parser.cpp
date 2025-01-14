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
// attentions aux yeux
bool Parser::parse_file(string path, Pool* pool) {
    ifstream infile;
    string line;

    string id; //command identifier: RECTANGLE, ...
    vector<int> line_args; // command arguments

    int x_max = 0;
    int y_max = 0;

    Forme* forme_tmp;

    infile.open(path);

    if(infile) {

        while(getline(infile, line)) {
            if(line.length()) {
                if(line.front() != '#') {    // ignore comments
                    int pos = line.find(":");

                    // get ID
                    id = line.substr(0, pos);
                    line.erase(0, pos+1);

                    // get parameters
                    while(line.find(",") != string::npos) {
                        pos = line.find(",");
                        line_args.push_back(stoi(line.substr(0, pos)));
                        line.erase(0, pos+1);
                    }

                    //special case for last parameter
                    line_args.push_back(stoi(line.substr(0, line.find(";"))));

                    //add form to pool
                    if( id.compare("RECTANGLE") == 0 || id.compare("RECTANGLES") == 0 ) {
                        forme_tmp = new Rectangle(line_args[0], //x
                                                  line_args[1], //y
                                                  line_args[2], //l
                                                  line_args[3], //h
                                                  Couleur(),
                                                  Couleur(line_args[4], //R couleur contour
                                                          line_args[5], //G
                                                          line_args[6], //B
                                                          line_args[7]) //alpha
                        );
                        if( id.compare("RECTANGLES") == 0) {
                            forme_tmp->set_fond(Couleur(line_args[4],
                                                        line_args[5],
                                                        line_args[6],
                                                        line_args[7]));
                        }
                        if( line_args.size() == 9 ) forme_tmp->set_z_index(line_args[8]);
                        x_max = max(x_max, line_args[0] + line_args[2]);
                        y_max = max(y_max, line_args[1] + line_args[3]);
                    }
                    else if( id.compare("CARRE") == 0 || id.compare("CARRES") == 0 ) {
                        forme_tmp = new Carre(line_args[0],
                                              line_args[1], //y
                                              line_args[2], //c
                                              Couleur(),
                                              Couleur(line_args[3], //R
                                                      line_args[4], //G
                                                      line_args[5], //B
                                                      line_args[6]) //alpha
                        );

                        if( id.compare("CARRES") == 0 ) {
                            forme_tmp->set_fond(Couleur(line_args[3],
                                                        line_args[4],
                                                        line_args[5],
                                                        line_args[6]));
                        }
                        if( line_args.size() == 8 ) forme_tmp->set_z_index(line_args[7]);
                        x_max = max(x_max, line_args[0] + line_args[2]);
                        y_max = max(y_max, line_args[1] + line_args[2]);
                    }
                    else if( id.compare("CERCLE") == 0 || id.compare("CERCLES") == 0 ) {
                        forme_tmp = new Disque(line_args[0],
                                               line_args[1], //y
                                               line_args[2], //c
                                               Couleur(),
                                               Couleur(line_args[3], //R
                                                       line_args[4], //G
                                                       line_args[5], //B
                                                       line_args[6]) //alpha
                        );

                        if( id.compare("CERCLES") == 0 ) {
                            forme_tmp->set_fond(Couleur(line_args[3],
                                                        line_args[4],
                                                        line_args[5],
                                                        line_args[6]));
                        }
                        if( line_args.size() == 8 ) forme_tmp->set_z_index(line_args[7]);
                        x_max = max(x_max, line_args[0] + line_args[2])+1;
                        y_max = max(y_max, line_args[1] + line_args[2])+1;
                    }
                    else if( id.compare("POINT") == 0 ) {
                        forme_tmp = new Point(line_args[0],
                                              line_args[1], //y
                                              Couleur(line_args[2], //R
                                                      line_args[3], //G
                                                      line_args[4], //B
                                                      line_args[5]) //alpha
                        );

                        if( line_args.size() == 7 ) forme_tmp->set_z_index(line_args[6]);
                        x_max = max(x_max, line_args[0]);
                        y_max = max(y_max, line_args[1]);
                    }
                    else if( id.compare("LIGNE") == 0 ) {
                        forme_tmp = new Ligne(line_args[0], //x1
                                              line_args[1], //y1
                                              line_args[2], //x2
                                              line_args[3], //y2
                                              Couleur(line_args[4], //R
                                                      line_args[5], //G
                                                      line_args[6], //B
                                                      line_args[7]) //alpha
                        );
                        if( line_args.size() == 7 ) forme_tmp->set_z_index(line_args[6]);
                        x_max = max(x_max, max(line_args[0], line_args[2]));
                        y_max = max(y_max, max(line_args[1], line_args[3]));
                    }

                    pool->add(forme_tmp);
                    line_args.clear();
                }
            }
        }

        _width = x_max;
        _height = y_max;

        infile.close();
        return true;
    }
    else {
        cerr << "ERROR: Could not open file " << path << endl;
        return false;
    }
}

int Parser::get_width() {
    return _width;
}

int Parser::get_height() {
    return _height;
}

                    // if( id.compare("RECTANGLE") == 0 ) {
                    //     if(line_args.size() == 8) {
                    //         pool->add(new Rectangle(line_args[0], //x
                    //                                 line_args[1], //y
                    //                                 line_args[2], //l
                    //                                 line_args[3], //h
                    //                                 Couleur(line_args[4], //R countour
                    //                                         line_args[5], //G
                    //                                         line_args[6], //B
                    //                                         line_args[7]), //alpha
                    //                                 Couleur(line_args[4], //R remplissage
                    //                                         line_args[5], //G
                    //                                         line_args[6], //B
                    //                                         line_args[7]) //alpha
                    //                                ));
                    //         x_max = max(x_max, line_args[0] + line_args[2]);
                    //         y_max = max(y_max, line_args[1] + line_args[3]);
                    //     }
                    //     else if(line_args.size() == 9) { // with z index
                    //         pool->add(new Rectangle(line_args[0], //x
                    //                                 line_args[1], //y
                    //                                 line_args[2], //l
                    //                                 line_args[3], //h
                    //                                 Couleur(line_args[4], //R
                    //                                         line_args[5], //G
                    //                                         line_args[6], //B
                    //                                         line_args[7]), //alpha
                    //                                 Couleur(line_args[4], //R remplissage
                    //                                         line_args[5], //G
                    //                                         line_args[6], //B
                    //                                         line_args[7]), //alpha
                    //                                 line_args[8] //z index
                    //                                ));
                    //         x_max = max(x_max, line_args[0] + line_args[2]);
                    //         y_max = max(y_max, line_args[1] + line_args[3]);
                    //     }
                    // }
                    // else if( id.compare("CARRE") == 0 ) {
                    //     if(line_args.size() == 7) {
                    //         pool->add(new Carre(line_args[0], //x
                    //                             line_args[1], //y
                    //                             line_args[2], //c
                    //                             Couleur(line_args[3], //R
                    //                                     line_args[4], //G
                    //                                     line_args[5], //B
                    //                                     line_args[6]),//alpha
                    //                             Couleur(line_args[3], //R
                    //                                     line_args[4], //G
                    //                                     line_args[5], //B
                    //                                     line_args[6]) //alpha
                    //                 ));
                    //         x_max = max(x_max, line_args[0] + line_args[2]);
                    //         y_max = max(y_max, line_args[1] + line_args[2]);
                    //     }
                    //     else if(line_args.size() == 8) {
                    //         pool->add(new Carre(line_args[0], //x
                    //                             line_args[1], //y
                    //                             line_args[2], //c
                    //                             Couleur(line_args[3], //R
                    //                                     line_args[4], //G
                    //                                     line_args[5], //B
                    //                                     line_args[6]),//alpha
                    //                             Couleur(line_args[3], //R
                    //                                     line_args[4], //G
                    //                                     line_args[5], //B
                    //                                     line_args[6]), //alpha
                    //                             line_args[7] //z index
                    //                 ));
                    //         x_max = max(x_max, line_args[0] + line_args[2]);
                    //         y_max = max(y_max, line_args[1] + line_args[2]);
                    //     }
                    // }
                    // else if( id.compare("CERCLE") == 0 ) {
                    //     if(line_args.size() == 7) {
                    //         pool->add(new Disque(line_args[0], //x
                    //                              line_args[1], //y
                    //                              line_args[2], //radius
                    //                              Couleur(line_args[3], //R
                    //                                      line_args[4], //G
                    //                                      line_args[5], //B
                    //                                      line_args[6]), //alpha
                    //                              Couleur(0,0,0,0) //empty
                    //                   ));
                    //         x_max = max(x_max, line_args[0] + line_args[2])+1;
                    //         y_max = max(y_max, line_args[1] + line_args[2])+1;
                    //     }
                    //     else if(line_args.size() == 8) {
                    //         pool->add(new Disque(line_args[0], //x
                    //                              line_args[1], //y
                    //                              line_args[2], //radius
                    //                              Couleur(line_args[3], //R
                    //                                      line_args[4], //G
                    //                                      line_args[5], //B
                    //                                      line_args[6]), //alpha
                    //                              Couleur(0,0,0,0), //empty
                    //                              line_args[7] //z index
                    //                   ));
                    //         x_max = max(x_max, line_args[0] + line_args[2])+1;
                    //         y_max = max(y_max, line_args[1] + line_args[2])+1;
                    //     }
                    // }
                    // else if( id.compare("POINT") == 0 ) {
                    //     if(line_args.size() == 6) {
                    //         pool->add(new Point(line_args[0], //X
                    //                             line_args[1], //y
                    //                             Couleur(line_args[2], //R
                    //                                     line_args[3], //G
                    //                                     line_args[4], //B
                    //                                     line_args[5]) //alpha
                    //                   ));
                    //         x_max = max(x_max, line_args[0]);
                    //         y_max = max(y_max, line_args[1]);
                    //     }
                    // }
                    // else if( id.compare("LIGNE") == 0 ) {
                    //     if(line_args.size() == 8) {
                    //         pool->add(new Ligne(line_args[0], //X1
                    //                             line_args[1], //y1
                    //                             line_args[2], //x2
                    //                             line_args[3], //y2
                    //                             Couleur(line_args[4], //R
                    //                                     line_args[5], //G
                    //                                     line_args[6], //B
                    //                                     line_args[7]) //alpha
                    //                   ));
                    //         x_max = max(x_max, max(line_args[0], line_args[2]));
                    //         y_max = max(y_max, max(line_args[1], line_args[3]));
                    //     }
                    // }
