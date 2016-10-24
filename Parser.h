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
#include <queue>
#include <string>

using namespace std;

struct cell {
        int theID;
        string theLeftSide;
        string theRightSide;
        void setCell(int idNumber, string lhs, string rhs);
    };

void cell::setCell(int idNumber, string lhs, string rhs) 
{
            theID = idNumber;
            theLeftSide = lhs;
            theRightSide = rhs;
}

class Parser {
    
    
    //This cell 0 will be used to throw the error for the blank spaces in the matrix.
    cell myCell0;
    myCell0.setCell(0, "", "");
    
    cell myCell1;
    myCell1.setCell(1, "Pgm", "kwdprog brace1 Slist brace2");
    
    cell myCell2;
    myCell2.setCell(2, "Slist", "Stmt semi Slist");
    
    cell myCell3;
    myCell3.setCell(3, "Slist", "eps");
    
    cell myCell4;
    myCell4.setCell(4, "Stmt", "S_Out");
    
    cell myCell5;
    myCell5.setCell(5, "Stmt", "id equal Y1");
    
    cell myCell6;
    myCell6.setCell(6, "S_Out", "kwdprint paren1 Elist paren2");
    
    cell myCell7;
    myCell7.setCell(7, "Y1", "E");
    
    cell myCell8;
    myCell8.setCell(8, "Y1", "kwdinput");
    
    cell myCell9;
    myCell9.setCell(9, "Elist", "E Elist2");
    
    cell myCell10;
    myCell10.setCell(10, "Elist", "eps");
    
    cell mycell1;
    myCel11.setCell(11, "Elist2", "comma Elist");
    
    cell myCell12;
    myCell12.setCell(12, "E", "T X1");
    
    cell myCell13;
    myCell13.setCell(13, "X1", "Opadd T X1");
    
    cell myCell14;
    myCel14.setCell(14, "X1", "eps");
    
    cell mycell15;
    myCel15.setCell(15, "T", "F X2");
    
    cell myCell16;
    myCel16.setCell(16, "X2", "Opmul F X2");
    
    cell myCell117;
    myCell17.setCell(17, "X2", "eps");
    
    cell mycell18;
    myCell18.setCell(18, "F", "Fatom");
    
    cell myCell19;
    myCell19.setCell(19, "F", "paren1 E paren2");
    
    cell myCell20;
    myCell20.setCell(20, "Fatom", "id");
    
    cell myCell21;
    myCell21.setCell(21, "Fatom", "int");
    
    cell myCell22;
    myCell22.setCell(22, "Fatom", "float");
    
    cell myCell23;
    myCell23.setCell(23, "Fatom", "string");
    
    cell myCell24;
    myCel24.setCell(24, "Opadd", "plus");
    
    cell myCell25;
    myCell25.setCell(25, "Opadd", "minus");
    
    cell myCell26;
    myCell26.setCell(26, "Opmul", "aster");
    
    cell myCell27;
    myCell27.setCell(27, "Opmul", "slash");
    
    cell myCell28;
    myCell28.setCell(28, "Opmul", "caret");
    
    cell theMatrix[15][19] =
    {
    //              0        1        2        3         4         5         6          7        8         9         10         11        12        13        14        15        16      17        18
    //              prog     print    input    id        int       float     string     (        )         ,          -         +         *         /         ^         ;         {        }        $
    /* 0  Pgm   */{ myCell1, myCell0, myCell0, myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 1  Slist */{ myCell0, myCell2, myCell0, myCell2,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell3, myCell0 },
    /* 2  Stmt  */{ myCell0, myCell4, myCell0, myCell5,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 3  S_Out */{ myCell0, myCell0, myCell6, myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 4  Y1    */{ myCell0, myCell0, myCell8, myCell7,  myCell7,  myCell7,  myCell7,  myCell7,  myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 5  Elist */{ myCell0, myCell0, myCell0, myCell9,  myCell9,  myCell9,  myCell9,  myCell9,  myCell10, myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 6  Elist2*/{ myCell0, myCell0, myCell0, myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell11, myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 7  E     */{ myCell0, myCell0, myCell0, myCell12, myCell12, myCell12, myCell12, myCell12, myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 8  X1    */{ myCell0, myCell0, myCell0, myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell14, myCell14, myCell13,  myCell13, myCell0,  myCell0,  myCell0, myCell14, myCell0, myCell0, myCell0 },
    /* 9  T     */{ myCell0, myCell0, myCell0, myCell15, myCell15, myCell15, myCell15, myCell15, myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 10 X2    */{ myCell0, myCell0, myCell0, myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell17, myCell17, myCell17,  myCell17, myCell16, myCell16, myCell16, myCell17, myCell0, myCell0, myCell0 },
    /* 11 F     */{ myCell0, myCell0, myCell0, myCell18, myCell18, myCell18, myCell18, myCell19, myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 12 Fatom */{ myCell0, myCell0, myCell0, myCell20, myCell21, myCell22, myCell23, myCell0,  myCell0,  myCell0,  myCell0,   myCell0,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 13 Opadd */{ myCell0, myCell0, myCell0, myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell25, myCell25,  myCell0,  myCell0,  myCell0, myCell0,  myCell0, myCell0, myCell0 },
    /* 14 Opmul */{ myCell0, myCell0, myCell0, myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,  myCell0,   myCell0,  myCell26, myCell27, myCell28, myCell0, myCell0, myCell0, myCell0 },
    };
};

#endif /* Parser_h */
