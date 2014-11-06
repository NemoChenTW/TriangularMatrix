TriangularMatrix
================

Using one dimension STL vector to store triangular matrix.


# How to use #

## Prepare ##
1. Decide the type of triangular matrix you need (ex. UpperTriangularMatrix).
2. Include the header file `libTriangularMatrix.h`.
3. Set the size of matrix.
4. Initial triangular matrix.

## Use ##

### Set element ###
+ By using the function 
`int setElement(unsigned int index_I, unsigned int index_J, int elementValue)`

###Get element ###
+ By using the function 
`int getElement(unsigned int index_I, unsigned int index_J)`

###Show Matrix###
+ `void showMatrix(bool showALL = false);`
+ `void showSymmetricalMatrix(bool showALL = false);`
+ `void showOneDimensionData();`

###Show Version##
+ `TriangularMatrixEnv::showVersion();`


##Example##

###test.cpp###

```
/*
 * test.cpp
 *
 *  Created on: 2014年11月4日
 *      Author: nemo
 */

#include <iostream>

#include "src/libTriangularMatrix.h"

using namespace std;

int main()
{
    TriangularMatrixEnv::showVersion();

    cout << "Test UpperTriangularMatrix." << endl;
    UpperTriangularMatrix UTM;
    int sizeOfMatrix = 5;
    UTM.setSizeOfMatrix(sizeOfMatrix);
    UTM.initial();

    int count = 1;
    for(int j = 0; j < sizeOfMatrix; j++)
    {
        for(int k = j; k < sizeOfMatrix; k++)
        {
            UTM.setElement(j,k,count++);
        }
    }
    UTM.showOneDimensionData();

    UTM.showMatrix();
    UTM.showSymmetricalMatrix();
    cout << endl;


    cout << "Test LowerTriangularMatrix." << endl;
    LowerTriangularMatrix LTM;

    LTM.setSizeOfMatrix(sizeOfMatrix);
    LTM.initial();

    count = 1;
    for(int j = 0; j < sizeOfMatrix; j++)
    {
        for(int k = 0; k <= j; k++)
        {
            LTM.setElement(j,k,count++);
        }
    }
    UTM.showOneDimensionData();

    LTM.showMatrix();
    LTM.showSymmetricalMatrix();
    return 0;
}
```
