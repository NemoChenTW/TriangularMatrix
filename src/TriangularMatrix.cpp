/*
 * TriangularMatrix.cpp
 *
 *  Created on: 2014年11月4日
 *      Author: nemo
 */

#include "header/TriangularMatrix.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>

namespace TriangularMatrixEnv
{
    const char* const _VERSION = "1.0.3";
}

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
void TriangularMatrix::showMatrix(unsigned int size, bool showALL, unsigned int width)
{
	if(size > _sizeOfMatrix || size == 0)
		size = _sizeOfMatrix;

	for(unsigned int j = 0; j < size; j++)
	{
		for(unsigned int k = 0; k < size; k++)
		{
			int elementValue = getElement(j,k);
			if(showALL)
			{
				cout << setw(width) << setfill('0') << elementValue << " ";
			}
			else
			{
				if(elementValue == 0)
				{
					cout << " ";
					for(auto i = 0; i < width; i++)
						cout << " ";
				}
				else
					cout << setw(width) << setfill('0') << elementValue << " ";
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
void TriangularMatrix::showSymmetricalMatrix(unsigned int size, bool showALL, unsigned int width)
{
	if(size > _sizeOfMatrix || size == 0)
		size = _sizeOfMatrix;

	for(unsigned int j = 0; j < size; j++)
	{
		for(unsigned int k = 0; k < size; k++)
		{
			int elementValue = getElement(k,j);
			if(showALL)
			{
				cout << setw(width) << setfill('0') << elementValue << " ";
			}
			else
			{
				if(elementValue == 0)
				{
					cout << " ";
					for(auto i = 0; i < width; i++)
						cout << " ";
				}
				else
					cout << setw(width) << setfill('0') << elementValue << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * @brief	Show element in 1-dimension container.
 */
void TriangularMatrix::showOneDimensionData(unsigned int width)
{
	vector <int>::iterator triangularMatrix_Iter;

	unsigned int indexCounter = 0;
	for (triangularMatrix_Iter = _triangularMatrix.begin();
			triangularMatrix_Iter != _triangularMatrix.end();
			triangularMatrix_Iter++)
	{
		if (triangularMatrix_Iter == _triangularMatrix.begin())
		{
			cout << "(" << indexCounter++ << ")=" << setw(width) << setfill('0')
					<< *triangularMatrix_Iter;
		}
		else
		{
			cout << ", " << "(" << indexCounter++ << ")=" << setw(width)
					<< setfill('0') << *triangularMatrix_Iter;
		}

	}

	cout << endl;
}

///		Show version information.
void TriangularMatrix::showVersion()
{
	printf("[TriangularMatrix]\n");
	printf("Version: %s\n", TriangularMatrixEnv::_VERSION);
	printf("Last Update: %s %s\n\n", __DATE__, __TIME__);
}
