#include <iostream>  
#include <iomanip>  
#include <fstream>  

using namespace std;

int main(){
	char buffer[256];
	ifstream myfile("c://a.txt");
	ofstream outfile("c://b.txt");

	if (!myfile){
		cout << "Unable to open myfile";
		exit(1); // terminate with error  

	}
	if (!outfile){
		cout << "Unable to open otfile";
		exit(1); // terminate with error  

	}
	int a, b;
	int i = 0, j = 0;
	int data[6][2];
	while (!myfile.eof())
	{
		myfile.getline(buffer, 10);
		sscanf(buffer, "%d %d", &a, &b);
		cout << a << " " << b << endl;
		data[i][0] = a;
		data[i][1] = b;
		i++;
	}
	myfile.close();
	for (int k = 0; k<i; k++){
		outfile << data[k][0] << " " << data[k][1] << endl;
		cout << data[k][0] << " " << data[k][1] << endl;
	}

	outfile.close();
	return 0;
}
