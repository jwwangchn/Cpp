#include <iostream>
#include <string>

using namespace std;

int main()
{
	string card;
	int sum = 0;
	while (cin >> card)
	{
		int num = (card[0] - 48) * 10000 + (card[1] - 48) * 1000 + (card[2] - 48) * 100 + (card[3] - 48) * 10 + (card[4] - 48);
		sum = sum + num;
	}
	int min = 10;
	while (sum > 0)
	{
		int temp = sum % 10;
		min = temp < min ? temp : min;
		sum /= 10;
	}
	cout << min << endl;
	return 0;
}