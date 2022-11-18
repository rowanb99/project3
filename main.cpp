#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Lexer.h"
#include "Parser.h"

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();
/*
 *
 * OPEN TRELLO AND SEE WHAT YOU NEED TO DO NEXT!!!!!
 * USING TRELLO COULD INCREASE PROJECT PICKUP TIME
 */
    // My stuff starts
    ifstream fileInput;
    string fileInputString;
    //Takes a file and puts it in a string so it can go to the lexer
    fileInput.open(argv[1]);
    if(!fileInput.is_open()){
        cout << "Failed To Open" << endl;
    }
    while (fileInput.peek() != EOF) {
        fileInputString.push_back(char(fileInput.get()));
    }
    //cout << fileInputString << endl;                      // Confirms that file stringified
    fileInput.close();

    lexer->Run(fileInputString);
    //cout << lexer->lexerToString(); //Use this and use in14.txt as arg if concerned that lexer is broke
    Parser* parser = new Parser(lexer->lexerResults());
    //My stuff ends


    delete lexer;
    delete parser;
    return 0;
}