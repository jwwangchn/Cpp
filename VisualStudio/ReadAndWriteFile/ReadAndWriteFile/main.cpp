#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream outfile;
	outfile.open("resultfile.txt");

	int data = 23;
	outfile << data;
	data = 23;
	outfile << data;
	outfile.close();

	//// �Զ�ģʽ���ļ�
	//ifstream infile;
	//infile.open("afile.txt");

	//cout << "Reading from the file" << endl;
	//infile >> data;

	//// ����Ļ��д������
	//cout << data << endl;

	//// �ٴδ��ļ���ȡ���ݣ�����ʾ��
	//infile >> data;
	//cout << data << endl;

	//// �رմ򿪵��ļ�
	//infile.close();

	return 0;
}