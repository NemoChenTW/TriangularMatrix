/*
 * TriangularMatrixEnum.h
 *
 *  Created on: 2014年11月5日
 *      Author: nemo
 */

#ifndef TRIANGULARMATRIXENUM_H_
#define TRIANGULARMATRIXENUM_H_

enum TriangularMatrixType
{
	TriangularMatrixType_RowMajor,
	TriangularMatrixType_ColumnMajor,

	TriangularMatrixType_MAX
};

///		Check the input triangularMatrixType is legal or not.
bool legalTriangularMatrixType(TriangularMatrixType triangularMatrixType);


#endif /* TRIANGULARMATRIXENUM_H_ */
