#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

inline int readInt()
{
	static int n, ch;
	n = 0, ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		n = n * 10 + ch - '0', ch = getchar();
	return n;
}

int main()
{
	int taxiNum = readInt();
	vector<vector<int>> taxiAxis(2, vector<int>(taxiNum, 0));
	vector<int> companyAxis(2);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < taxiNum; j++)
		{
			taxiAxis[i][j] = readInt();
		}
	}
	companyAxis[0] = readInt();
	companyAxis[1] = readInt();

	int walkTime = readInt();
	int taxiTime = readInt();

	int minDistanceTaxi = abs(taxiAxis[0][0]) + abs(taxiAxis[1][0]);
	int minIndex = 0;
	for (int i = 0; i<taxiNum; i++)
	{
		if (minDistanceTaxi > abs(taxiAxis[0][i]) + abs(taxiAxis[1][i]))
		{
			minDistanceTaxi = abs(taxiAxis[0][i]) + abs(taxiAxis[1][i]);
			minIndex = i;
		}
	}
	int walkCost = walkTime * minDistanceTaxi;

	int taxiCost = taxiTime * (abs(companyAxis[0] - taxiAxis[0][minIndex]) + abs(companyAxis[1] - taxiAxis[1][minIndex]));

	cout << taxiCost + walkCost << endl;
	return 0;
}