#include<iostream>
#include<string>
using namespace std;

string strExchange(string str, string subStr, string strOfExchange)
{
	int lenOfStr = str.length();
	int lenOfSubstr = subStr.length();
	bool flagOfEqual = false;
	int startOfSame[100] = { 0 };
	int numOfSame = 0;

	for (int i = 0; i < lenOfStr; i++)
	{
		if (str[i] == 'm' || str[i] == 'M')
		{
			int index = i;
			for (int j = 0; j < lenOfSubstr; j++)
			{
				if ((str[index] == subStr[j]) || (str[index] == subStr[j] - 32))
				{
					index++;
					flagOfEqual = true;
				}
				else
				{
					flagOfEqual = false;
					break;
				}
			}
			if (flagOfEqual)
			{
				startOfSame[numOfSame] = i;
				numOfSame++;
			}
		}
	}
	if (numOfSame != 0)
	{
		for (int k = 0; k < numOfSame; k++)
		{
			str = str.replace(startOfSame[k], lenOfSubstr, strOfExchange);
		}
	}
	return str;
}

int main()
{
	//string str[200] = { " " }, strNew[200] = { " " };
	string str, strNew, strInput;
	string subOfStr = "marshtomp";
	string strOfExchange = "fjxmlhx";
	int numOfInput = 0;
	while (1)
	{

		getline(cin, strInput);
		cin.ignore();
		if (strInput == "")
		{
			strNew = strExchange(str, subOfStr, strOfExchange);
			break;
		}
		str = str + strInput + "\n";

		numOfInput++;

	}
	cout << strNew << endl;
	return 0;
}