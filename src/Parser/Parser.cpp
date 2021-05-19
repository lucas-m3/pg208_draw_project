#include "Parser.h"

#include <iostream>

Parser::Parser() {}

Parser::Parser(string in_path) {
    _in_path = in_path;
    parse_file();
}


/*
** returns false if parsing fails
*/
// TODO ignore comments #
// TODO create push function to fill pool
bool Parser::parse_file() {
    ifstream infile;
    string line;

    infile.open(_in_path);

    if(infile) {

        while(getline(infile, line)) {
            cout << line << endl;
        }

        infile.close();
        return true;
    }
    else {
        cerr << "ERROR: Could not open file " << _in_path << endl;
        return false;
    }
}
