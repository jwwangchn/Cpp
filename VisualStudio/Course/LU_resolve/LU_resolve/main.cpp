/*
文件名：LU.cpp
作用：进行矩阵的 LU 分解
使用方法：修改矩阵 matrixA0

作者：王金旺 信息与通信工程 
学号：2016202120110

时间：2016年11月20日
*/
#include <iostream>
#include <vector>

using namespace std;

//待分解的矩阵
vector<vector<double>> matrixA0 = { { 2, -1, 3 }, { 1, 2, 1 }, { 2, 4, 2 } };		//需要分解的矩阵
int n = matrixA0.size();	//方阵的大小
vector<vector<vector<double>>> Lr(n, vector<vector<double>>(n, vector<double>(n)));
vector<vector<vector<double>>> Lr_1(n, vector<vector<double>>(n, vector<double>(n)));

//实现矩阵乘法的函数, 此函数仅仅能计算方阵间的矩阵乘积
vector<vector<double>> matrixMultiplication(vector<vector<double>> Matrix1, vector<vector<double>> Matrix2)
{
	//初始化result的行大小
	vector<vector<double>> result(n, vector<double>(n));
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			for (int inner = 0; inner < n; inner++)
			{
				result[row][col] += Matrix1[row][inner] * Matrix2[inner][col];
			}
		}
	}
	return result;
}
//实现矩阵减法的函数
vector<vector<double>> matrixSubtraction(vector<vector<double>> Matrix1, vector<vector<double>> Matrix2)
{
	//初始化result的行大小
	vector<vector<double>> result(Matrix1.size(), vector<double>(Matrix1[0].size()));

	for (int row = 0; row < Matrix1.size(); row++)
	{
		for (int col = 0; col < Matrix1[0].size(); col++)
		{
			result[row][col] = abs(Matrix1[row][col] - Matrix2[row][col]);
		}
	}
	return result;
}
// 生成单位矩阵的函数
vector<vector<double>> eyeMatrix(int num)
{
	vector<vector<double>> eye(num,vector<double>(num));
	for (int row = 0; row < num; row++)
	{
		for (int col = 0; col < num; col++)
		{
			if (row == col)
			{
				eye[row][col] = 1;
			}
			else
			{
				eye[row][col] = 0;
			}
		}
	}
	return eye;
}
//实现二维矩阵向三维矩阵的赋值操作,high为第三维的维数
vector<vector<vector<double>>> matrixAssignment_2to3(vector<vector<double>> inputMatrix, vector<vector<vector<double>>> resultMatrix, int high)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			resultMatrix[high][row][col] = inputMatrix[row][col];
		}
	}
	return resultMatrix;
}
//实现三维矩阵向二维矩阵的赋值操作,high为第三维的维数
vector<vector<double>> matrixAssignment_3to2(vector<vector<vector<double>>> inputMatrix, int high)
{
	vector<vector<double>> result(n, vector<double>(n));
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			result[row][col] = inputMatrix[high][row][col];
		}
	}
	return result;
}

//求解L矩阵
void solveL(vector<vector<double>> inputMatrix, int r, int high)
{
	vector<vector<double>> Lr_temp = eyeMatrix(inputMatrix.size());
	vector<vector<double>> Lr_1_temp = eyeMatrix(inputMatrix.size());
	int n = inputMatrix.size();
	for (int i = r; i < n - 1; i++)
	{
		Lr_temp[i + 1][r] = inputMatrix[i + 1][r] / inputMatrix[r][r];
		Lr_1_temp[i + 1][r] = -inputMatrix[i + 1][r] / inputMatrix[r][r];
	}
	Lr = matrixAssignment_2to3(Lr_temp, Lr, high);
	Lr_1 = matrixAssignment_2to3(Lr_1_temp, Lr_1, high);
}
int main()
{
	//构造三个三维矩阵，用于存储矩阵分解过程中的中间变量
	vector<vector<vector<double>>> A(n, vector<vector<double>>(n, vector<double>(n)));
	vector<vector<vector<double>>> L(n, vector<vector<double>>(n, vector<double>(n)));
	vector<vector<vector<double>>> L_1(n, vector<vector<double>>(n, vector<double>(n)));
	//三个二维结果矩阵，用于存储最终结果
	vector<vector<double>> L_result = eyeMatrix(n);
	vector<vector<double>> U_result(n, vector<double>(n));
	vector<vector<double>> A_result(n, vector<double>(n));
	vector<vector<double>> Subtration_result(n, vector<double>(n));

	//初始化A矩阵
	A = matrixAssignment_2to3(matrixA0, A, 0);	//A(:,:,1)=A0
	//循环求解Ar和Lr两个矩阵
	for (int i = 0; i < n - 1; i++)
	{
		solveL(matrixAssignment_3to2(A, i), i, i);
		A = matrixAssignment_2to3(matrixMultiplication(matrixAssignment_3to2(Lr_1, i), matrixAssignment_3to2(A, i)), A, i + 1);
	}

	//结果
	for (int i = 0; i < n - 1; i++)
	{
		L_result = matrixMultiplication(L_result, matrixAssignment_3to2(Lr, i));
	}
	U_result = matrixAssignment_3to2(A, n - 1);
	A_result = matrixMultiplication(L_result, U_result);

	//打印输出
	bool flag = true;
	for (int i = 0; i < 5; i++)
	{
		flag = true;
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (i == 0)
				{
					//输出矩阵的L分量
					if (flag == true)
					{
						cout << "待分解的矩阵 A ：" << endl;
						flag = false;
					}
					cout << matrixA0[row][col] << " ";
				}
				if (i == 1)
				{
					//输出矩阵的L分量
					if (flag == true)
					{
						cout << "A 矩阵的 L 分量为：" << endl;
						flag = false;
					}
					cout << L_result[row][col] << " ";
				}
				if (i == 2)
				{
					//输出矩阵的U分量
					if (flag == true)
					{
						cout << "A 矩阵的 U 分量为：" << endl;
						flag = false;
					}

					cout << U_result[row][col] << " ";
				}
				if (i == 3)
				{
					//输出L*U
					if (flag == true)
					{
						cout << "L*U 为：" << endl;
						flag = false;
					}
					cout << A_result[row][col] << " ";
				}
				if (i == 4)
				{
					//输出 A-L*U
					if (flag == true)
					{
						cout << "A-L*U 为：" << endl;
						flag = false;
					}
					cout << matrixSubtraction(A_result,matrixA0)[row][col] << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}