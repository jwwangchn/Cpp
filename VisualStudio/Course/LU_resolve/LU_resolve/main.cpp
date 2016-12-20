/*
�ļ�����LU.cpp
���ã����о���� LU �ֽ�
ʹ�÷������޸ľ��� matrixA0

���ߣ������� ��Ϣ��ͨ�Ź��� 
ѧ�ţ�2016202120110

ʱ�䣺2016��11��20��
*/
#include <iostream>
#include <vector>

using namespace std;

//���ֽ�ľ���
vector<vector<double>> matrixA0 = { { 2, -1, 3 }, { 1, 2, 1 }, { 2, 4, 2 } };		//��Ҫ�ֽ�ľ���
int n = matrixA0.size();	//����Ĵ�С
vector<vector<vector<double>>> Lr(n, vector<vector<double>>(n, vector<double>(n)));
vector<vector<vector<double>>> Lr_1(n, vector<vector<double>>(n, vector<double>(n)));

//ʵ�־���˷��ĺ���, �˺��������ܼ��㷽���ľ���˻�
vector<vector<double>> matrixMultiplication(vector<vector<double>> Matrix1, vector<vector<double>> Matrix2)
{
	//��ʼ��result���д�С
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
//ʵ�־�������ĺ���
vector<vector<double>> matrixSubtraction(vector<vector<double>> Matrix1, vector<vector<double>> Matrix2)
{
	//��ʼ��result���д�С
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
// ���ɵ�λ����ĺ���
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
//ʵ�ֶ�ά��������ά����ĸ�ֵ����,highΪ����ά��ά��
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
//ʵ����ά�������ά����ĸ�ֵ����,highΪ����ά��ά��
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

//���L����
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
	//����������ά�������ڴ洢����ֽ�����е��м����
	vector<vector<vector<double>>> A(n, vector<vector<double>>(n, vector<double>(n)));
	vector<vector<vector<double>>> L(n, vector<vector<double>>(n, vector<double>(n)));
	vector<vector<vector<double>>> L_1(n, vector<vector<double>>(n, vector<double>(n)));
	//������ά����������ڴ洢���ս��
	vector<vector<double>> L_result = eyeMatrix(n);
	vector<vector<double>> U_result(n, vector<double>(n));
	vector<vector<double>> A_result(n, vector<double>(n));
	vector<vector<double>> Subtration_result(n, vector<double>(n));

	//��ʼ��A����
	A = matrixAssignment_2to3(matrixA0, A, 0);	//A(:,:,1)=A0
	//ѭ�����Ar��Lr��������
	for (int i = 0; i < n - 1; i++)
	{
		solveL(matrixAssignment_3to2(A, i), i, i);
		A = matrixAssignment_2to3(matrixMultiplication(matrixAssignment_3to2(Lr_1, i), matrixAssignment_3to2(A, i)), A, i + 1);
	}

	//���
	for (int i = 0; i < n - 1; i++)
	{
		L_result = matrixMultiplication(L_result, matrixAssignment_3to2(Lr, i));
	}
	U_result = matrixAssignment_3to2(A, n - 1);
	A_result = matrixMultiplication(L_result, U_result);

	//��ӡ���
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
					//��������L����
					if (flag == true)
					{
						cout << "���ֽ�ľ��� A ��" << endl;
						flag = false;
					}
					cout << matrixA0[row][col] << " ";
				}
				if (i == 1)
				{
					//��������L����
					if (flag == true)
					{
						cout << "A ����� L ����Ϊ��" << endl;
						flag = false;
					}
					cout << L_result[row][col] << " ";
				}
				if (i == 2)
				{
					//��������U����
					if (flag == true)
					{
						cout << "A ����� U ����Ϊ��" << endl;
						flag = false;
					}

					cout << U_result[row][col] << " ";
				}
				if (i == 3)
				{
					//���L*U
					if (flag == true)
					{
						cout << "L*U Ϊ��" << endl;
						flag = false;
					}
					cout << A_result[row][col] << " ";
				}
				if (i == 4)
				{
					//��� A-L*U
					if (flag == true)
					{
						cout << "A-L*U Ϊ��" << endl;
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