/*
 * TriangularMatrixEnv.h
 *
 *  Created on: 2014年11月6日
 *      Author: nemo
 */

#ifndef TRIANGULARMATRIXENV_H_
#define TRIANGULARMATRIXENV_H_

#include <stdio.h>

namespace TriangularMatrixEnv
{
    const char* const _VERSION = "1.0.0";

	void showVersion()
	{
		printf("[TriangularMatrix]\n");
		printf("Version: %s\n", _VERSION);
		printf("Last Update: %s %s\n\n", __DATE__, __TIME__);
	}
}



#endif /* TRIANGULARMATRIXENV_H_ */
