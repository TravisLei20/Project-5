#include <iostream>
#include <fstream>
#include <sstream>

#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream in;
    in.open(argv[1]);
    stringstream ss;
    ss << in.rdbuf();
    string input = ss.str();
    in.close();

    //cout << input << endl;

    //Project-1
    Lexer* lexer = new Lexer();
    lexer -> Run(input);
    //lexer -> toString();

    //Project-2
    Parser parser;
    parser.setTokens(lexer -> getToken());
    parser.parse();

    //Project-3
    Interpreter interpreter(parser.getDatalogProgram());


    delete lexer;

    return 0;
}