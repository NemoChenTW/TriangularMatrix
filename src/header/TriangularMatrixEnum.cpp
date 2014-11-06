/*
 * TriangularMatrixEnum.cpp
 *
 *  Created on: 2014年11月5日
 *      Author: nemo
 */

#include "TriangularMatrixEnum.h"

/**
 * @brief	Check the input triangularMatrixType is legal or not.
 *
 * @param triangularMatrixType	Input triangularMatrixType.
 *
 * @return	The input triangularMatrixType is legal or not.
 */
bool legalTriangularMatrixType(TriangularMatrixType triangularMatrixType)
{
	switch(triangularMatrixType)
	{
		case TriangularMatrixType_RowMajor:
		case TriangularMatrixType_ColumnMajor:
			return true; break;
		default:
			return false;
	}
}

