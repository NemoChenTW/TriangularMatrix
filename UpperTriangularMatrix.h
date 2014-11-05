/*
 * UpperTriangularMatrix.h
 *
 *  Created on: 2014年11月4日
 *      Author: nemo
 */

#ifndef UPPERTRIANGULARMATRIX_H_
#define UPPERTRIANGULARMATRIX_H_

#include "TriangularMatrix.h"

class UpperTriangularMatrix: public TriangularMatrix {
public:
	UpperTriangularMatrix(TriangularMatrixType triangularMatrixType=TriangularMatrixType_RowMajor);
	virtual ~UpperTriangularMatrix();

	///		Set element of upper triangular matrix.
	int setElement(unsigned int index_I, unsigned int index_J, int elementValue);

private:

	///		Convert 2-dimension index to 1-dimension TriangularMatrix index.
	int matrixIndexConvert(unsigned int index_I, unsigned int index_J);
};

#endif /* UPPERTRIANGULARMATRIX_H_ */
