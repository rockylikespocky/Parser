//Main file

#include <iostream>
#include <string>

using namespace std;

//Optional: change the cell struct name to "myRule" to represent rules in the matrix. (Makes sense a little more for the matrix)

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
	
	//This cell 0 will be used to throw the error for the blank spaces in the matrix.
	cell mycell0;
	myCell1.setCell(0, "0", "0");


	cell myCell1;
	myCell1.setCell(1, "Pgm", "kwdprog brace1 Slist brace2");

	cell myCell2;
	myCell2.setCell(2, "Slist", "Stmt semi Slist");

	cell myCell3;
	myCell3.setCell(3, "Slist", "eps");

	cell myCell4;
	myCell4.setCell(4, "Stmt", "S_Out");

	cell myCell5;
	myCell1.setCell(5, "Stmt", "id equal Y1");

	cell myCell6;
	myCell2.setCell(6, "S_Out", "kwdprint paren1 Elist paren2");

	cell myCell7;
	myCell7.setCell(7, "Y1", "E");
	
	cell mycell8;
	myCell8.setCell(8, "Y1", "kwdinput");
	
	cell myCell9;
	myCell2.setCell(9, "Elist", "E Elist2");

	cell myCell10;
	myCell7.setCell(10, "Elist", "eps");
	
	cell mycell1;
	myCell8.setCell(11, "Elist2", "comma Elist");
	
	cell myCell12;
	myCell1.setCell(12, "E", "T X1");

	cell myCell13;
	myCell2.setCell(13, "X1", "Opadd T X1");

	cell myCell14;
	myCell7.setCell(14, "X1", "eps");
	
	cell mycell15;
	myCell8.setCell(15, "T", "F X2");
	
	cell myCell16;
	myCell2.setCell(16, "X2", "Opmul F X2");

	cell myCell117;
	myCell7.setCell(17, "X2", "eps");
	
	cell mycell18;
	myCell8.setCell(18, "F", "Fatom");
	
	cell myCell19;
	myCell2.setCell(19, "F", "paren1 E paren2");

	cell myCell20;
	myCell7.setCell(20, "Fatom", "id");
	
	cell mycell21;
	myCell8.setCell(21, "Fatom", "int");
	
	cell myCell22;
	myCell7.setCell(22, "Fatom", "float");
	
	cell mycell23;
	myCell8.setCell(23, "Fatom", "string");
	
	cell myCell24;
	myCell7.setCell(24, "Opadd", "plus");
	
	cell mycell25;
	myCell8.setCell(25, "Opadd", "minus");
	
	cell myCell26;
	myCell7.setCell(26, "Opmul", "aster");
	
	cell mycell27;
	myCell8.setCell(27, "Opmul", "slash");
	
	cell mycell28;
	myCell8.setCell(28, "Opmul", "caret");
	
	cell theMatrix[15][19] =
	{
		//                     0      1      2      3      4      5      6      7      8      9      10     11     12     13     14     15     16     17     18
			//                     prog   print  input  id     int    float  string (      )      ,      -      +      *      /      ^      ;      {      }      $
			/* 0   Pgm     */{ myCell1,    "",    "",    "",    "",   "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 1   Slist   */{ "",     myCell2,    "", myCell2, "",   "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "", myCell3,    "" },
			/* 2   Stmt    */{ "",    myCell4,    "",  myCell5,    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 3   S_Out   */{ "",    "",      myCell6,    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 4   Y1      */{ "",    "",      myCell8, myCell7, myCell7, myCell7, myCell7, myCell7,    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 5   Elist   */{ "",    "",    "",        myCell9, myCell9, myCell9, myCell9, myCell9, myCell10,    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 6   Elist2  */{ "",    "",    "",    "",    "",    "",    "",    "",    "",    myCell11",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 7   E       */{ "",    "",    "",       myCell12, myCell12, myCell12, myCell12, myCell12,    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 8   X1      */{ "",    "",    "",    "",    "",    "",    "",    "",    myCell14, myCell14, myCell13, myCell13, "", "",  "", myCell14,    "",    "",    "" },
			/* 9   T       */{ "",    "",    "",    myCell15, myCell15, myCell15, myCell15, myCell15,    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 10  X2      */{ "",    "",    "",    "",    "",    "",    "",    "",    myCell17, myCell17, myCell17, myCell17, myCell16, myCell16, myCell16, myCell17,    "",    "",    "" },
			/* 11  F       */{ "",    "",    "",    myCell18, myCell18, myCell18, myCell18, myCell19,    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 12  Fatom   */{ "",    "",    "",    myCell20, myCell21, myCell22, myCell23,    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "" },
			/* 13  Opadd   */{ "",    "",    "",    "",    "",    "",    "",    "",    "",    "",   myCell25, myCell25,    "",    "",    "",    "",    "",    "",    "" },
			/* 14  Opmul   */{ "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",    "",   myCell26, myCell27, myCell28,    "",    "",    "",    "" },

	};
	
	return 0;
}
