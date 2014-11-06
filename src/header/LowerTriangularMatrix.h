/*
 * LowerTriangularMatrix.h
 *
 *  Created on: 2014年11月5日
 *      Author: nemo
 */

#ifndef LOWERTRIANGULARMATRIX_H_
#define LOWERTRIANGULARMATRIX_H_

#include "TriangularMatrix.h"

class LowerTriangularMatrix: public TriangularMatrix {
public:
	LowerTriangularMatrix(TriangularMatrixType triangularMatrixType=TriangularMatrixType_RowMajor);
	virtual ~LowerTriangularMatrix();

	///		Set element of lower triangular matrix.
	int setElement(unsigned int index_I, unsigned int index_J, int elementValue);

private:

	///		Convert 2-dimension index to 1-dimension TriangularMatrix index.
	int matrixIndexConvert(unsigned int index_I, unsigned int index_J);
};

#endif /* LOWERTRIANGULARMATRIX_H_ */
