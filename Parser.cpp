//
//  Parser.cpp
//  Parser
//
//  Created by Nhat Nguyen on 10/10/16.
//  Created by Adam Adame on 10/10/16.
//  Copyright © 2016 Nhat Nguyen & Adam Adame. All rights reserved.
//

#include "Parser.h"

Parser::Parser(deque<Token> myQ) {
	Queue = myQ;
	parse();
}

void Parser::parse() {
	cout << "~~~~~Starting Parser~~~~~" << endl;

	// Push end symbol onto the stack.
	Symbol endSymbol;
	endSymbol.text = "$";
	Stack.push_back(endSymbol);

	// Push start symbol onto the stack.
	Symbol startSymbol;
	startSymbol.text = "Pgm";
	Stack.push_back(startSymbol);

	// Loop until stack is empty.
	while (!Stack.empty()) {
		Symbol currentSymbol = Stack.back();
		Token currentToken = Queue.front();

		// Check for a terminal Symbol.
		if (currentSymbol.isTerminal()) {
			if (currentSymbol.getSymbolId() == currentToken.tokenID) {
				Queue.pop_front();
				Stack.pop_back();
			}
			else {
				cout << "ERROR: Terminal Symbol was found but did not match." << endl;
				break;
			}
		}
		// Check for a non-terminal Symbol.
		else {
			vector<Symbol> expansion = expand(currentSymbol, currentToken);


		}
	}
}

vector<Symbol> Parser::expand(Symbol symbol, Token token) {
	vector<Symbol> expansion;
	cell myCell = theMatrix[getRow(symbol)][getColumn(token)];

	istringstream ss(myCell.theRightSide);
	istream_iterator<string> begin(ss), end;

	vector<string> symbol_text(begin, end);

	for (int i = 0; i < symbol_text.size(); i++) {
		Symbol mySymbol;
		mySymbol.text = symbol_text[i];
		expansion.push_back(mySymbol);
	}

	return expansion;
}

int Parser::getRow(Symbol symbol) {
	if (symbol.text == "Pgm") { return  0; }
	else if (symbol.text == "Slist") { return  1; }
	else if (symbol.text == "Stmt") { return  2; }
	else if (symbol.text == "S_Out") { return  3; }
	else if (symbol.text == "Y1") { return  4; }
	else if (symbol.text == "Elist") { return  5; }
	else if (symbol.text == "Elist2") { return  6; }
	else if (symbol.text == "E") { return  7; }
	else if (symbol.text == "X1") { return  8; }
	else if (symbol.text == "T") { return  9; }
	else if (symbol.text == "X2") { return  10; }
	else if (symbol.text == "F") { return  11; }
	else if (symbol.text == "Fatom") { return  12; }
	else if (symbol.text == "Opadd") { return  13; }
	else if (symbol.text == "Opmul") { return  14; }
	else { return -1; }
}

int Parser::getColumn(Token token) {
	if (token.tokenID == 10) { return 0; }
	else if (token.tokenID == 23) { return 1; }
	else if (token.tokenID == 22) { return 2; }
	else if (token.tokenID == 2) { return 3; }
	else if (token.tokenID == 3) { return 4; }
	else if (token.tokenID == 4) { return 5; }
	else if (token.tokenID == 5) { return 6; }
	else if (token.tokenID == 37) { return 7; }
	else if (token.tokenID == 38) { return 8; }
	else if (token.tokenID == 6) { return 9; }
	else if (token.tokenID == 46) { return 10; }
	else if (token.tokenID == 47) { return 11; }
	else if (token.tokenID == 41) { return 12; }
	else if (token.tokenID == 48) { return 13; }
	else if (token.tokenID == 42) { return 14; }
	else if (token.tokenID == 7) { return 15; }
	else if (token.tokenID == 33) { return 16; }
	else if (token.tokenID == 34) { return 17; }
	else if (token.tokenID == 0) { return 18; }
	else { return -1; }
}

void Parser::printChanges() {
	for (int i = 0; i < Stack.size(); i++) {
		cout << Stack[i].getAbbreviation();
	}
	if (!Queue.empty()) {
		cout << "\t\t\t\t\t";
		for (int i = 0; i < Queue.size(); i++) {
			Token currentToken = Queue.front();
			cout << currentToken.tokenItem;
		}
	}
}