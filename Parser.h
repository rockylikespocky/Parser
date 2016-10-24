//
//  Parser.h
//  Parser Class header file.
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

struct Symbol {
	string text;
	bool isTerminal() {
		return ((text[0] == '$') || (text[0] >= 'a' && text[0] <= 'z'));
	}
	int getSymbolId() {
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
	string getAbbreviation() {
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
};

class Parser {
public:
	string theMatrix[15][19] = {
		//                 0                              1                               2           3                  4        5           6           7                  8        9              10            11            12            13             14            15     16     17      18
		//                 prog                           print                           input       id                 int      float       string      (                  )        ,              -             +             *             /              ^             ;      {      }       $
		/* 0  Pgm     */{ "kwdprog brace1 Slist brace2",  "",                             "",         "",                "",      "",         "",         "",                "",      "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 1  Slist   */{ "",                             "Stmt semi Slist",              "",         "Stmt semi Slist", "",      "",         "",         "",                "",      "",            "",           "",           "",           "",            "",           "",    "",    "eps",  "" },
		/* 2  Stmt    */{ "",                             "S_Out",                        "",         "id equal Y1",     "",      "",         "",         "",                "",      "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 3  S_Out   */{ "",                             "kwdprint paren1 Elist paren2", "",         "",                "",      "",         "",         "",                "",      "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 4  Y1      */{ "",                             "",                             "kwdinput", "E",               "E",     "E",        "E",        "E",               "",      "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 5  Elist   */{ "",                             "",                             "",         "E Elist2",   "E Elist2", "E Elist2",   "E Elist2", "E Elist2",        "eps",   "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 6  Elist2  */{ "",                             "",                             "",         "",                "",      "",         "",         "",                "",      "comma Elist", "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 7  E       */{ "",                             "",                             "",         "T X1",            "T X1",  "T X1",     "T X1",     "T X1",            "",      "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 8  X1      */{ "",                             "",                             "",         "",                "",      "",         "",         "",                "eps",   "eps",         "Opadd T X1", "Opadd T X1", "",           "",            "",           "eps", "",    "",     "" },
		/* 9  T       */{ "",                             "",                             "",         "F X2",            "F X2",  "F X2",     "F X2",     "F X2",            "",      "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 10 X2      */{ "",                             "",                             "",         "",                "",      "",         "",         "",                "eps",   "eps",         "eps",        "eps",        "Opmul F X2", "Opmul F X2",  "Opmul F X2", "eps", "",    "",     "" },
		/* 11 F       */{ "",                             "",                             "",         "Fatom",           "Fatom", "Fatom",    "Fatom",    "paren1 E paren2", "",      "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 12 Fatom   */{ "",                             "",                             "",         "id",              "int",   "float",    "string",   "",                "",      "",            "",           "",           "",           "",            "",           "",    "",    "",     "" },
		/* 13 Opadd   */{ "",                             "",                             "",         "",                "",      "",         "",         "",                "",      "",            "minus",      "plus",       "",           "",            "",           "",    "",    "",     "" },
		/* 14 Opmul   */{ "",                             "",                             "",         "",                "",      "",         "",         "",                "",      "",            "",           "",           "aster",      "slash",       "caret",      "",    "",    "",     "" },
	};

	Parser(deque<Token> myQ);

	void parse();
	vector<Symbol> expand(Symbol symbol, Token token);

	// Returns the row index based on the symbol
	int getRow(Symbol);

	// Returns the column index based on the token
	int getColumn(Token);

	void printChanges();

	// Returns column header string
	string getColumnHeader(Token token);

	// Prints error message
	void printError();
private:
	deque<Token> Queue;
	vector<Symbol> Stack;
};

#endif /* Parser_h */