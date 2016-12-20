#include<iostream>
#include<Eigen\Core>
#include<Eigen\SVD>
#include<Eigen\Dense>

using namespace std;
using namespace Eigen;
using Eigen::MatrixXd;

template<typename _Matrix_Type_>
_Matrix_Type_ pseudoInverse(const _Matrix_Type_ &a, double epsilon = numeric_limits<double>::epsilon())
{
	JacobiSVD< _Matrix_Type_ > svd(a, ComputeThinU | ComputeThinV);
	double tolerance = epsilon * max(a.cols(), a.rows()) * svd.singularValues().array().abs()(0);
	return svd.matrixV() * (svd.singularValues().array().abs() > tolerance).select(svd.singularValues().array().inverse(), 0).matrix().asDiagonal() * svd.matrixU().adjoint();
}

int main()
{
	//�����������
	MatrixXd A(2, 3);
	A << 1, 2, 3, 4, 5, 6;
	cout << "���������ľ���A:" << endl;
	cout << A << endl << endl;
	cout << "A �Ĺ��������:" << endl;
	cout << pseudoInverse(A) << endl << endl;

	//ʹ�ù��������������Է����� Ax = B
	//[1] Ƿ������
	MatrixXd A1(3, 4), B1(3, 1), x1(3, 1);
	A1 << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12;
	B1 << 1, 2, 3;
	x1 = pseudoInverse(A1)*B1;

	cout << "Ƿ�����Է����� Ax = B �Ľ� x2 Ϊ:" << endl;
	cout << x1 << endl;
	cout << "��� error1 = Ax-B Ϊ��" << endl;
	cout << A1*x1 - B1 << endl << endl;
	//[2] ��������
	MatrixXd A2(4, 3), B2(4, 1), x2(4, 1);
	A2 << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12;
	B2 << 1, 2, 3, 4;
	x2 = pseudoInverse(A2)*B2;

	cout << "�������Է����� Ax = B �Ľ� x2 Ϊ:" << endl;
	cout << x2 << endl;
	cout << "��� error1 = Ax-B Ϊ��" << endl;
	cout << A2*x2 - B2 << endl << endl;

	return(0);
}