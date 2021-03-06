/*
 * TriangularMatrix.h
 *
 *  Created on: 2014年11月4日
 *      Author: nemo
 */

#ifndef TRIANGULARMATRIX_H_
#define TRIANGULARMATRIX_H_

#include <vector>
#include "TriangularMatrixEnum.h"

using namespace std;

class TriangularMatrix {
public:
	TriangularMatrix();
	virtual ~TriangularMatrix();

	///		Initial triangular matrix
	int initial();

	///		Set matrix size.
	void setSizeOfMatrix(unsigned int sizeOfMatrix) {_sizeOfMatrix = sizeOfMatrix;}

	///		Set element of triangular matrix.
	virtual int setElement(unsigned int index_I, unsigned int index_J, int elementValue)=0;

	///		Get element of triangular matrix.
	int getElement(unsigned int index_I, unsigned int index_J);

	///		Show element in matrix.
	void showMatrix(unsigned int size = 0, bool showALL = false, unsigned int width = 3);

	///		Show element in matrix symmetrically.
	void showSymmetricalMatrix(unsigned int size = 0, bool showALL = false, unsigned int width = 3);

	///		Show element in 1-dimension container.
	void showOneDimensionData(unsigned int width = 3);

	///		Get triangularMatrixType.
	TriangularMatrixType triangularMatrixType() {return _triangularMatrixType;}

	///		Show version information.
	static void showVersion();

protected:
	vector <int> _triangularMatrix;				///< Store element of triangular matrix
	unsigned int _sizeOfMatrix;					///< Size of triangular matrix

	bool _isInitialed;							///< For checking initial status.

	TriangularMatrixType _triangularMatrixType;	///< The matrix is row major or column major.


	///		Convert 2-dimension index to 1-dimension TriangularMatrix index.
	virtual int matrixIndexConvert(unsigned int index_I, unsigned int index_J)=0;

};

#endif /* TRIANGULARMATRIX_H_ */
