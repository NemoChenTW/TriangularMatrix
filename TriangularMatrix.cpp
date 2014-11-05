/*
 * TriangularMatrix.cpp
 *
 *  Created on: 2014年11月4日
 *      Author: nemo
 */

#include "TriangularMatrix.h"

#include <iostream>
#include <iomanip>

TriangularMatrix::TriangularMatrix()
:_sizeOfMatrix(0), _isInitialed(false)
{

}

TriangularMatrix::~TriangularMatrix()
{
	// TODO Auto-generated destructor stub
}

/**
 * @brief	Initial triangular matrix
 *
 * @retval	 0	Initial success.
 * @retval	-1	Initial fail, sizeOfMatrix not set.
 *
 * Calculate the number of element according to the size of matrix.
 * After initial all element as 0, set flag isInitialed as true.
 */
int TriangularMatrix::initial()
{
	if (_sizeOfMatrix == 0)
		return -1;

	unsigned int numberOfElement;
	numberOfElement = (_sizeOfMatrix * (_sizeOfMatrix + 1)) / 2;

	for(unsigned int i = 0; i < numberOfElement; i++)
		_triangularMatrix.push_back(0);

	_isInitialed = true;
	return 0;
}

/**
 * @brief	Get element triangular matrix.
 *
 * @param index_I		Element index i.
 * @param index_J		Element index j.
 *
 * @return	The value of element (i.j)
 *
 * If any error occurred, the return value will be 0.
 */
int TriangularMatrix::getElement(unsigned int index_I, unsigned int index_J)
{
	if( !_isInitialed )
		return 0;
	if(index_I >= _sizeOfMatrix || index_J >= _sizeOfMatrix)
		return 0;

	int matrixIndex = matrixIndexConvert(index_I, index_J);
	if(matrixIndex < 0)
		return 0;
	else
	{
		int elementValue = _triangularMatrix[matrixIndexConvert(index_I, index_J)];
		return elementValue;
	}
}

/**
 * @brief	Show element in matrix.
 *
 * @param showALL	Show all element include '0' or not.
 */
void TriangularMatrix::showMatrix(bool showALL)
{
	for(unsigned int j = 0; j < _sizeOfMatrix; j++)
	{
		for(unsigned int k = 0; k < _sizeOfMatrix; k++)
		{
			int elementValue = getElement(j,k);
			if(showALL)
			{
				cout << setw(2) << setfill('0') << elementValue << " ";
			}
			else
			{
				if(elementValue == 0)
				{
					cout << "   ";
				}
				else
					cout << setw(2) << setfill('0') << elementValue << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * @brief	Show element in matrix symmetrically.
 *
 * @param showALL	Show all element include '0' or not.
 */
void TriangularMatrix::showSymmetricalMatrix(bool showALL)
{
	for(unsigned int j = 0; j < _sizeOfMatrix; j++)
	{
		for(unsigned int k = 0; k < _sizeOfMatrix; k++)
		{
			int elementValue = getElement(k,j);
			if(showALL)
			{
				cout << setw(2) << setfill('0') << elementValue << " ";
			}
			else
			{
				if(elementValue == 0)
				{
					cout << "   ";
				}
				else
					cout << setw(2) << setfill('0') << elementValue << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * @brief	Show element in 1-dimension container.
 */
void TriangularMatrix::showOneDimensionData()
{
	vector <int>::iterator triangularMatrix_Iter;

	unsigned int indexCounter = 0;
	for (triangularMatrix_Iter = _triangularMatrix.begin();
			triangularMatrix_Iter != _triangularMatrix.end();
			triangularMatrix_Iter++)
	{
		if (triangularMatrix_Iter == _triangularMatrix.begin())
		{
			cout << "(" << indexCounter++ << ")=" << setw(2) << setfill('0')
					<< *triangularMatrix_Iter;
		}
		else
		{
			cout << ", " << "(" << indexCounter++ << ")=" << setw(2)
					<< setfill('0') << *triangularMatrix_Iter;
		}

	}

	cout << endl;
}
