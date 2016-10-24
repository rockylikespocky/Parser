//
//  main.cpp
//  Main file test the Lexer Class using input from text files or stdin.
//  Main file will also test the Parser Class based on output produced by the Lexer Class.
//
//  Created by Nhat Nguyen on 10/10/16.
//  Created by Adam Adame on 10/10/16.
//  Copyright © 2016 Nhat Nguyen & Adam Adame. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Lexer.h"
#include "Parser.h"

using namespace std;

void useFile1(string fileName) {
    Lexer l(fileName);
    Parser p(l.getQueue());
}

void useFile2(string fileName) {
    Lexer l(fileName);
	Parser p(l.getQueue());
}

void useFile3(string fileName) {
    Lexer l(fileName);
	Parser p(l.getQueue());
}

void useCustomFile() {
    string inputFileName;
    cout << "Type in your filename: ";
    cin >> inputFileName;
    Lexer l(inputFileName);
	Parser p(l.getQueue());
}

void Stdin() {
    Lexer l;
	Parser p(l.getQueue());
}

int main() {
    string inFileName1 = "Test-A.txt";
    string inFileName2 = "Test-B.txt";
    string inFileName3 = "Test-C.txt";
    
    cout << "What do you want to test?" << endl;
    cout << "1. Test-A  2. Test-B  3. Test-C 4. Custom File 5. Stdin: ";
    int choice;
    string blank;
    cin >> choice;
    getline(cin, blank);
    
    switch (choice) {
        case 1: useFile1(inFileName1); break;
        case 2: useFile2(inFileName2); break;
        case 3: useFile3(inFileName3); break;
        case 4: useCustomFile(); break;
        case 5: Stdin(); break;
    }
    
    string line;
    cout << "Press ENTER to exit program..." << endl;
    getline(cin, line);
    
    return 0;
}
