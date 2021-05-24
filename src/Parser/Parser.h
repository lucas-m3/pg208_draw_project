#ifndef __PARSER_H_
#define __PARSER_H_

#include <fstream>
#include <string>
#include "../Formes/Pool.h"

using namespace std;

class Parser {
    private:
        int _width; //deduced from maximal x coordinate
        int _height; // y
    public:
        Parser();

        bool parse_file(string path, Pool* pool);
        int get_width();
        int get_height();
};


#endif // __PARSER_H_
