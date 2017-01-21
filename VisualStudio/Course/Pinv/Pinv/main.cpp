#include<iostream>
#include<Eigen\Core>
#include<Eigen\SVD>
#include<Eigen\Dense>

using namespace std;
using namespace Eigen;
using Eigen::MatrixXd;

template<typename _Matrix_Type_>
_Matrix_Type_ pseudoInverse(const _Matrix_Type_ &inputMatrix)
{
	//计算 inputMatrix 的SVD分解
	JacobiSVD< _Matrix_Type_ > svd(inputMatrix, ComputeThinU | ComputeThinV);

	//C++的数字精度
	double error = numeric_limits<double>::epsilon();
	//设定容忍误差
	double tolerance;
	tolerance = error * max(inputMatrix.cols(), inputMatrix.rows()) * svd.singularValues().array().abs()(0);
	//返回广义逆矩阵
	return svd.matrixV() * (svd.singularValues().array().abs() > tolerance).select(svd.singularValues().array().inverse(), 0).matrix().asDiagonal() * svd.matrixU().adjoint();
}

int main()
{
	//求解广义逆矩阵
	MatrixXd A(2, 3);
	A << 1, 2, 3, 4, 5, 6;
	cout << "待求广义逆的矩阵A:" << endl;
	cout << A << endl << endl;
	cout << "A 的广义逆矩阵:" << endl;
	cout << pseudoInverse(A) << endl << endl;

	//使用广义逆矩阵求解线性方程组 Ax = B
	//[1] 
	MatrixXd A1(3, 4), B1(3, 1), x1(3, 1);
	A1 << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12;
	B1 << 1, 2, 3;
	x1 = pseudoInverse(A1)*B1;

	cout << "不相容方程组 Ax = B 的最小二乘解 x2 为:" << endl;
	cout << x1 << endl;
	cout << "误差 error1 = Ax-B 为：" << endl;
	cout << A1*x1 - B1 << endl << endl;
	//[2] 相容方程组
	MatrixXd A2(4, 3), B2(4, 1), x2(4, 1);
	A2 << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12;
	B2 << 1, 2, 3, 4;
	x2 = pseudoInverse(A2)*B2;

	cout << "相容方程组 Ax = B 的极小范数解 x2 为:" << endl;
	cout << x2 << endl;
	cout << "误差 error1 = Ax-B 为：" << endl;
	cout << A2*x2 - B2 << endl << endl;

	return(0);
}