/*
 * test.cpp
 *
 *  Created on: 2014年11月4日
 *      Author: nemo
 */

#include <iostream>

#include "UpperTriangularMatrix.h"
#include "LowerTriangularMatrix.h"

using namespace std;

int main()
{
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

