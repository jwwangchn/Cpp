#include <iostream>
#include "add.h"
using namespace std;
int main()
{
	if (!addInitialize())
	{
		cout << "initilize failed!!!" << endl;
		return -1;
	}

	mwArray a(1, 1, mxDOUBLE_CLASS);
	mwArray b(1, 1, mxDOUBLE_CLASS);

	a(1, 1) = 20;
	b(1, 1) = 30;

	mwArray x(1, 1, mxDOUBLE_CLASS);
	mwArray y(1, 1, mxDOUBLE_CLASS);

	//�����������,�������,���������
	add(2, x, y, a, b);

	double *i = new double;
	double *j = new double;

	x.GetData(i, 1);
	y.GetData(j, 1);

	cout << "x=" << *i << "  y=" << *j << endl;
	getchar();
	return 0;
}