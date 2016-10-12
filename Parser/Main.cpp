//Main file

#include <iostream>
#include <string>

using namespace std;

struct cell {
	int theID;
	string theLeftSide;
	string theRightSide;
	void setCell(int id, string lhs, string rhs);
};

void cell::setCell(int id, string lhs, string rhs)
{
	id = theID;
	lhs = theLeftSide;
	rhs = theRightSide;
}



int main() {

	cell myCell1;
	myCell1.setCell(1, "Pgm", "kwdprog brace1 Slist brace2");

	cell myCell2;
	myCell2.setCell(2, "Slist", "Stmt semi Slist");

	cell myCell3;
	myCell3.setCell(3, "Slist", "eps");

	cell myCell4;
	myCell4.setCell(4, "Stmt", "S_Out");

	cell myCell1;
	myCell1.setCell(5, "Stmt", "id equal Y1");

	cell myCell2;
	myCell2.setCell(6, "S_Out", "kwdprint paren1 Elist paren2");

	cell myCell7;
	myCell7.setCell(7, "Y1", "E");



	
	
	cell theMatrix[15][19] =
	{

	};
	
	return 0;
}
