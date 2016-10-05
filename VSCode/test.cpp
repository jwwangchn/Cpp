#include<iostream>
#include<vector>
using namespace std;

int grade = 0;
void highOfMoun(vector<int> moun, int left, int right)
{
	int numOfMin = 0;
	for (int i = left + 1; i < right; i++)
	{
		if (moun[i] <= moun[left] && moun[i] <= moun[right])
		{
			numOfMin++;
			if (numOfMin == right - left - 1)
			{
				grade++;
				numOfMin = 0;
			}
		}
	}
}

int main()
{
	vector<int> num;
	int numOfInput = 0;
	int temp;
	cin >> numOfInput;
	for (int i = 0; i < numOfInput; i++)
	{
		cin >> temp;
		num.push_back(temp);
	}
	for (int i = 0; i < numOfInput; i++)
	{
		num.push_back(num[i]);
	}

	for (int i = 0; i < numOfInput; i++)
	{
		for (int j = i + 2; j <= i + numOfInput - 2; j++)
		{
			highOfMoun(num, i, j);
		}
	}
	cout << grade + numOfInput << endl;
	return 0;
}