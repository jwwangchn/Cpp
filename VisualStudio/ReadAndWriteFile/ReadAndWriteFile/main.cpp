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

	//// 以读模式打开文件
	//ifstream infile;
	//infile.open("afile.txt");

	//cout << "Reading from the file" << endl;
	//infile >> data;

	//// 在屏幕上写入数据
	//cout << data << endl;

	//// 再次从文件读取数据，并显示它
	//infile >> data;
	//cout << data << endl;

	//// 关闭打开的文件
	//infile.close();

	return 0;
}