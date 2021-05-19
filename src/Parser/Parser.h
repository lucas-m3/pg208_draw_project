#ifndef __PARSER_H_
#define __PARSER_H_

#include <fstream>
#include <string>
#include "../Formes/Pool.h"

using namespace std;

class Parser {
    public:
        Parser();

        bool parse_file(string path, Pool* pool);
};


#endif // __PARSER_H_
