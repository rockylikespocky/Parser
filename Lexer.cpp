//
//  Lexer.cpp
//  Parser
//
//  Created by Nhat Nguyen on 10/10/16.
//  Created by Adam Adame on 10/10/16.
//  Copyright © 2016 Nhat Nguyen & Adam Adame. All rights reserved.
//

#include "Lexer.h"

Lexer::Lexer() {
    // code input using stdin getline
    
    cout << "Enter input: " << endl;
    ofstream outFile;
    outFile.open("output.txt");
    
    while (getline(cin, line)) {
        if (line == "QUIT" || line == "q" || line == "Q") {
            outFile.close();
            break;
        }
        
        outFile << line << "\n";
        
        if (cin.bad()) {
            // IO error
            break;
        }
        
    }
    
    Lexer m("output.txt");
}

Lexer::Lexer(string file_name) {
    inFile.open(file_name);
    
    if (inFile.is_open()) {
        cout << "Success: File is opened." << endl;
        cout << "~~~~~Starting Lexer~~~~~" << endl;
    }
    if (!inFile.is_open()) {
        cout << "Error: File won't open." << endl;
    }
    
    // loop through file to get input
    while(!atEndOfFile()) {
        if (inFile.eof()) break; // Ugly but stops the output repeat of last line
        getline(inFile, line);
        
        // Iterate through each char in string line
        for (std::string::size_type i = 0; i < line.size(); ++i) {
            char c = line[i];
            char c2 = line[i + 1];
            
            if (isSpace(c)) {
                continue;
            }
            
            // Testing for string token
            if (c == '"') {
                ++i;
                c = line[i];
                c2 = line[i + 1];
                while (!(c == '"')) {
                    c = line[i];
                    c2 = line[i + 1];
                    if (c == '"') continue;
                    tempstr += c;
                    ++i;
                }
                token = tempstr;
                type = "string";
                setTokenID();
                saveInfo();
                printOutput();
                resetFields();
            }
            
            // Testing for Unpaired delimiters
            if (isUnpairedDelimiters(c)) {
                token = c;
                setTokenID();
                saveInfo();
                printOutput();
                resetFields();
                continue;
            }
            // Testing for Multi-char operators
            if (isMultiOperator(c, c2)) {
                token = c;
                token += c2;
                type = "multioperator";
                setTokenID();
                saveInfo();
                printOutput();
                ++i;
                resetFields();
            }
            // Testing for Punctuations
            else if (isPunctuation(c)) {
                if (isComment(c, c2)) {
                    break;
                }
                else {
                    if (c2 == ' ') {
                        token = c;
                        type = "punctuation";
                        setTokenID();
                        saveInfo();
                        printOutput();
                    }
                    resetFields();
                }
            }
            // Testing for Delimeters
            else if (isDelimeter(c)) {
                token = c;
                type = "delimiter";
                setTokenID();
                saveInfo();
                printOutput();
                resetFields();
            }
            // Testing for Integer
            else if (isdigit(c)) {
                tempstr += c;
                type = "integer";
                while (isdigit(c2)) {
                    ++i;
                    c = line[i];
                    c2 = line[i + 1];
                    tempstr += c;
                }
                // Testing for Float
                if (c2 == '.') {
                    ++i;
                    c = line[i];
                    c2 = line[i + 1];
                    tempstr += c;
                    type = "float";
                    while (isdigit(c2)) {
                        ++i;
                        c = line[i];
                        c2 = line[i + 1];
                        tempstr += c;
                    }
                }
                token = tempstr;
                setTokenID();
                saveInfo();
                printOutput();
                resetFields();
            }
            // currently a keyword or identifier
            else if (isalpha(c)) {
                tempstr += c;
                while (isalpha(c2) || isdigit(c2)) {
                    i++;
                    c = line[i];
                    c2 = line[i + 1];
                    tempstr += c;
                }
                if (isKeyword(tempstr)) {
                    token = tempstr;
                    setTokenID();
                    saveInfo();
                    printOutput();
                    resetFields();
                }
                else {
                    type = "identifier";
                    token = tempstr;
                    setTokenID();
                    saveInfo();
                    printOutput();
                    resetFields();
                }
            }
        }
        lineCount += 1;
    }
    endingProcess();
}

void Lexer::printOutput() {
    cout << "(Tok: id= "
    << idNumber
    << " line= "
    << lineCount
    << " str= "
    << '"'
    << token
    << '"';
    
    if (type == "integer") {
        cout << " int= " << token;
    }
    if (type == "float") {
        cout << " float= " << token;
    }
    
    cout << ")"
    << endl;
}

void Lexer::saveInfo() {
    Token myToken;
    myToken.lineNumber = lineCount;
    myToken.tokenID = idNumber;
    myToken.tokenItem = token;
    Queue.push_back(myToken);
}

void Lexer::setTokenID() {
    // identifier ID
    if (type == "identifier") {
        idNumber = 2;
        return;
    }
    // integer ID
    if (type == "integer") {
        idNumber = 3;
    }
    // float ID
    if (type == "float") {
        idNumber = 4;
    }
    // string ID
    if (type == "string") {
        idNumber = 5;
    }
    // unpaired delimiter IDs
    if (token == ",") {
        idNumber = 6;
    }
    if (token == ";") {
        idNumber = 7;
    }
    // keyword IDs
    if (token == "prog") {
        idNumber = 10;
    }
    if (token == "main") {
        idNumber = 11;
    }
    if (token == "fnc") {
        idNumber = 12;
    }
    if (token == "class") {
        idNumber = 13;
    }
    if (token == "float") {
        idNumber = 15;
    }
    if (token == "int") {
        idNumber = 16;
    }
    if (token == "string") {
        idNumber = 17;
    }
    if (token == "if") {
        idNumber = 18;
    }
    if (token == "elseif") {
        idNumber = 19;
    }
    if (token == "else") {
        idNumber = 20;
    }
    if (token == "while") {
        idNumber = 21;
    }
    if (token == "input") {
        idNumber = 22;
    }
    if (token == "print") {
        idNumber = 23;
    }
    if (token == "new") {
        idNumber = 24;
    }
    if (token == "return") {
        idNumber = 25;
    }
    // delimiter IDs
    if (token == "<") {
        idNumber = 31;
    }
    if (token == ">") {
        idNumber = 32;
    }
    if (token == "{") {
        idNumber = 33;
    }
    if (token == "}") {
        idNumber = 34;
    }
    if (token == "[") {
        idNumber = 35;
    }
    if (token == "]") {
        idNumber = 36;
    }
    if (token == "(") {
        idNumber = 37;
    }
    if (token == ")") {
        idNumber = 38;
    }
    // punctuation IDs
    if (token == "*") {
        idNumber = 41;
    }
    if (token == "^") {
        idNumber = 42;
    }
    if (token == ":") {
        idNumber = 43;
    }
    if (token == ".") {
        idNumber = 44;
    }
    if (token == "=") {
        idNumber = 45;
    }
    if (token == "-") {
        idNumber = 46;
    }
    if (token == "+") {
        idNumber = 47;
    }
    if (token == "/") {
        idNumber = 48;
    }
    // multi-char operators
    if (token == "->") {
        idNumber = 51;
    }
    if (token == "==") {
        idNumber = 52;
    }
    if (token == "!=") {
        idNumber = 53;
    }
    if (token == "<=") {
        idNumber = 54;
    }
    if (token == ">=") {
        idNumber = 55;
    }
    if (token == "<<") {
        idNumber = 56;
    }
    if (token == ">>") {
        idNumber = 57;
    }
    // error token ID
    if (type == "error") {
        idNumber = 99;
    }
}

void Lexer::resetFields() {
    idNumber = 0;
    token = "";
    tempstr = "";
    type = "";
}

bool Lexer::isComment(char c1, char c2) {
    return ((c1 == '/') && (c2 == '/'));
}

bool Lexer::isSpace(char c) {
    return (c == ' ');
}

bool Lexer::isUnpairedDelimiters(char c) {
    return (c == ',' || c == ';');
}

bool Lexer::isPunctuation(char c) {
    return (
            c == '*'
            || c == '^'
            || c == ':'
            || c == '.'
            || c == '='
            || c == '-'
            || c == '+'
            || c == '/'
            );
}

bool Lexer::isDelimeter(char c) {
    return (
            c == '<'
            || c == '>'
            || c == '{'
            || c == '}'
            || c == '['
            || c == ']'
            || c == '('
            || c == ')'
            );
}

bool Lexer::isMultiOperator(char c1, char c2) {
    return (
            (c1 == '-' && c2 == '>')
            || (c1 == '=' && c2 == '=')
            || (c1 == '!' && c2 == '=')
            || (c1 == '<' && c2 == '=')
            || (c1 == '>' && c2 == '=')
            || (c1 == '<' && c2 == '<')
            || (c1 == '>' && c2 == '>')
            );
}

bool Lexer::isKeyword(string word) {
    return (
            word == "prog"
            || word == "main"
            || word == "fnc"
            || word == "class"
            || word == "float"
            || word == "int"
            || word == "string"
            || word == "if"
            || word == "elseif"
            || word == "else"
            || word == "while"
            || word == "input"
            || word == "print");
}

bool Lexer::atEndOfFile() {
    if (!inFile) {
        closeFile();
        return true;
    } else {
        return false;
    }
}

void Lexer::closeFile() {
    inFile.close();
}

void Lexer::endingProcess() {
    idNumber = 0;
    lineCount -= 2;
    printOutput();
    
    // Testing to make sure that Queue is properly pushing Tokens
    cout << "Testing Queue: " << endl;
    for (int i = 0; (Queue.size() != 0); i++) {
        Token currentToken = Queue.front();
        cout << currentToken.tokenID << currentToken.tokenItem << endl;
        Queue.pop_front();
    }
}

deque<Token> Lexer::getQueue() {
    return Queue;
}
