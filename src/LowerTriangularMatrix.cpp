/*
 * LowerTriangularMatrix.cpp
 *
 *  Created on: 2014年11月5日
 *      Author: nemo
 */

#include "header/LowerTriangularMatrix.h"

LowerTriangularMatrix::LowerTriangularMatrix(TriangularMatrixType triangularMatrixType)
{
	if(legalTriangularMatrixType(triangularMatrixType))
	{
		_triangularMatrixType = triangularMatrixType;
	}
	else
	{
		triangularMatrixType = TriangularMatrixType_RowMajor;
	}
}

LowerTriangularMatrix::~LowerTriangularMatrix()
{

}

/**
 * @brief	Set element of lower triangular matrix.
 *
 * @param index_I			Element index i.
 * @param index_J			Element index j.
 * @param elementValue		The value of element (i.j).
 *
 * @retval	 0	Set value success.
 * @retval	-1	Set value fail, index out of range.
 * @retval	-2	Set value fail, element value error.
 * @retval	-5	Set value fail, triangular matrix not initialed.
 */
int LowerTriangularMatrix::setElement(unsigned int index_I, unsigned int index_J, int elementValue)
{
	if( !_isInitialed )
		return -5;

	if(index_I >= _sizeOfMatrix || index_J >= _sizeOfMatrix)
		return -1;

	//	Check whether the element value accord with rule of upper triangular matrix.
	if(index_I < index_J)
	{
		if (elementValue != 0)
		{
			return -2;
		}
		else
			return 0;
	}
	else
	{
		_triangularMatrix[matrixIndexConvert(index_I, index_J)] = elementValue;
		return 0;
	}
}

/**
 * @brief	Convert 2-dimension index to 1-dimension lower triangular matrix index.
 *
 * @param index_I	2-dimension matrix index i.
 * @param index_J	2-dimension matrix index j.
 *
 * @return	1-dimension lower triangular matrix index.
 */
int LowerTriangularMatrix::matrixIndexConvert(unsigned int index_I, unsigned int index_J)
{

	if(index_I < index_J)
		return -1;

	unsigned int LTMIndex;
	if(triangularMatrixType() == TriangularMatrixType_RowMajor)
	{
		LTMIndex = (index_I+1) * ((index_I+1)-1) / 2 + (index_J+1) -1;
	}
	else if(triangularMatrixType() == TriangularMatrixType_ColumnMajor)
	{

	}

	return LTMIndex;
}

