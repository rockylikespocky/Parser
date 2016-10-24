//
//  Parser.h
//  Parser
//
//  Created by Nhat Nguyen on 10/10/16.
//  Created by Adam Adame on 10/10/16.
//  Copyright © 2016 Nhat Nguyen & Adam Adame. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iterator>

#include "Lexer.h"

using namespace std;

struct cell {
	int theID;
	string theLeftSide;
	string theRightSide;
};

cell myCell0 = { 0, "", "" };

cell myCell1 = { 1, "Pgm", "kwdprog brace1 Slist brace2" };

cell myCell2 = { 2, "Slist", "Stmt semi Slist" };

cell myCell3 = { 3, "Slist", "eps" };

cell myCell4 = { 4, "Stmt", "S_Out" };

cell myCell5 = { 5, "Stmt", "id equal Y1" };

cell myCell6 = { 6, "S_Out", "kwdprint paren1 Elist paren2" };

cell myCell7 = { 7, "Y1", "E" };

cell myCell8 = { 8, "Y1", "kwdinput" };

cell myCell9 = { 9, "Elist", "E Elist2" };

cell myCell10 = { 10, "Elist", "eps" };

cell myCell11 = { 11, "Elist2", "comma Elist" };

cell myCell12 = { 12, "E", "T X1" };

cell myCell13 = { 13, "X1", "Opadd T X1" };

cell myCell14 = { 14, "X1", "eps" };

cell myCell15 = { 15, "T", "F X2" };

cell myCell16 = { 16, "X2", "Opmul F X2" };

cell myCell17 = { 17, "X2", "eps" };

cell myCell18 = { 18, "F", "Fatom" };

cell myCell19 = { 19, "F", "paren1 E paren2" };

cell myCell20 = { 20, "Fatom", "id" };

cell myCell21 = { 21, "Fatom", "int" };

cell myCell22 = { 22, "Fatom", "float" };

cell myCell23 = { 23, "Fatom", "string" };

cell myCell24 = { 24, "Opadd", "plus" };

cell myCell25 = { 25, "Opadd", "minus" };

cell myCell26 = { 26, "Opmul", "aster" };

cell myCell27 = { 27, "Opmul", "slash" };

cell myCell28 = { 28, "Opmul", "caret" };

cell theMatrix[15][19] =
{
	//              0        1        2        3         4         5         6          7        8         9         10         11        12        13        14        15        16      17        18
	//              prog     print    input    id        int       float     string     (        )         ,          -         +         *         /         ^         ;         {        }        $
	/* 0  Pgm   */{ myCell1, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 1  Slist */{ myCell0, myCell2, myCell0, myCell2, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell3, myCell0 },
	/* 2  Stmt  */{ myCell0, myCell4, myCell0, myCell5, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 3  S_Out */{ myCell0, myCell0, myCell6, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 4  Y1    */{ myCell0, myCell0, myCell8, myCell7, myCell7, myCell7, myCell7, myCell7, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 5  Elist */{ myCell0, myCell0, myCell0, myCell9, myCell9, myCell9, myCell9, myCell9, myCell10, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 6  Elist2*/{ myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell11, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 7  E     */{ myCell0, myCell0, myCell0, myCell12, myCell12, myCell12, myCell12, myCell12, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 8  X1    */{ myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell14, myCell14, myCell13, myCell13, myCell0, myCell0, myCell0, myCell14, myCell0, myCell0, myCell0 },
	/* 9  T     */{ myCell0, myCell0, myCell0, myCell15, myCell15, myCell15, myCell15, myCell15, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 10 X2    */{ myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell17, myCell17, myCell17, myCell17, myCell16, myCell16, myCell16, myCell17, myCell0, myCell0, myCell0 },
	/* 11 F     */{ myCell0, myCell0, myCell0, myCell18, myCell18, myCell18, myCell18, myCell19, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 12 Fatom */{ myCell0, myCell0, myCell0, myCell20, myCell21, myCell22, myCell23, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 13 Opadd */{ myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell25, myCell25, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0 },
	/* 14 Opmul */{ myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell0, myCell26, myCell27, myCell28, myCell0, myCell0, myCell0, myCell0 },
};

struct Symbol {
	string text;
	bool isTerminal();
	int getSymbolId();
	string getAbbreviation();
};

bool Symbol::isTerminal() {
	return ((text[0] == '$') || (text[0] >= 'a' && text[0] <= 'z'));
}

int Symbol::getSymbolId() {
	if (text == "kwdprog") { return 10; }
	else if (text == "brace1") { return 33; }
	else if (text == "brace2") { return 34; }
	else if (text == "semi") { return 7; }
	else if (text == "id") { return 2; }
	else if (text == "equal") { return 45; }
	else if (text == "kwdinput") { return 22; }
	else if (text == "kwdprint") { return 23; }
	else if (text == "paren1") { return 37; }
	else if (text == "paren2") { return 38; }
	else if (text == "comma") { return 6; }
	else if (text == "int") { return 3; }
	else if (text == "float") { return 4; }
	else if (text == "string") { return 5; }
	else if (text == "plus") { return 47; }
	else if (text == "minus") { return 46; }
	else if (text == "aster") { return 41; }
	else if (text == "slash") { return 48; }
	else if (text == "caret") { return 42; }
	else if (text == "$") { return 0; }
	else { return -1; }
}

string Symbol::getAbbreviation() {
	if (text == "E") { return "E."; }
	else if (text == "Elist") { return "EL."; }
	else if (text == "Elist2") { return "E2."; }
	else if (text == "F") { return "F."; }
	else if (text == "Fatom") { return "Fa."; }
	else if (text == "Opadd") { return "O+."; }
	else if (text == "Opmul") { return "O*."; }
	else if (text == "Pgm") { return "Pg."; }
	else if (text == "S_Asgn") { return "S=."; }
	else if (text == "S_In") { return "SI."; }
	else if (text == "S_Out") { return "SO."; }
	else if (text == "Slist") { return "SL."; }
	else if (text == "Stmt") { return "S."; }
	else if (text == "Stmts") { return "Ss."; }
	else if (text == "T") { return "T."; }
	else if (text == "X1") { return "X1."; }
	else if (text == "X2") { return "X2."; }
	else if (text == "Y1") { return "Y1."; }
	else if (text == "aster") { return "*."; }
	else if (text == "brace1") { return "{."; }
	else if (text == "brace2") { return "}."; }
	else if (text == "caret") { return "^."; }
	else if (text == "comma") { return ",."; }
	else if (text == "equal") { return "=."; }
	else if (text == "float") { return "fl."; }
	else if (text == "id") { return "id."; }
	else if (text == "int") { return "it."; }
	else if (text == "kwdinput") { return "ki."; }
	else if (text == "kwdprint") { return "ko."; }
	else if (text == "kwdprog") { return "kp."; }
	else if (text == "minus") { return "-."; }
	else if (text == "paren1") { return "(."; }
	else if (text == "paren2") { return ")."; }
	else if (text == "plus") { return "+."; }
	else if (text == "semi") { return ";."; }
	else if (text == "slash") { return "/."; }
	else if (text == "string") { return "st."; }
	else if (text == "$") { return "$"; }
	else if (text == "eps") { return ""; }
	else { return "-1"; }
}

class Parser {
public:

	Parser(deque<Token> myQ);

	void parse();
	vector<Symbol> expand(Symbol symbol, Token token);

	// Returns the row index based on the symbol
	int getRow(Symbol);

	// Returns the column index based on the token
	int getColumn(Token);

	void printChanges();
	
private:
	deque<Token> Queue;
	vector<Symbol> Stack;
};

#endif /* Parser_h */
