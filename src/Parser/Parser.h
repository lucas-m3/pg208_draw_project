#ifndef __PARSER_H_
#define __PARSER_H_

#include <fstream>
#include <string>

using namespace std;

class Parser {
    private:
        string _in_path;
        bool parse_file();
    public:
        Parser();
        Parser(string in_path);
};


#endif // __PARSER_H_
