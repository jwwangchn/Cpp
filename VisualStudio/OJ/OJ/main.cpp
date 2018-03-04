#include <iostream>
using namespace std;
int isrunnian(int year)
{
    if (year % 4 != 0)
        return 0;
    if (year % 100 != 0)
        return 1;
    if (year % 400 != 0)
        return 0;
    else
        return 1;
}
int main()
{
    int year, month, day, dayth;
    int tmonth;
    cin >> year >> month >> day;
    month = -month;
    tmonth = month;
    day = -day;
    int runnian[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nrunnian[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year >= 0 && year < 10000 && month >= 0 && month <= 12)
    {
        if (isrunnian(year))
        {
            if (day > runnian[- month - 1])
            {
                cout << "invalid input";
                return 0;
            }
            else
            {
                dayth = day;
                tmonth = tmonth - 2;
                while (tmonth >= 0)
                {
                    dayth += runnian[tmonth];
                    tmonth--;
                }
            }
        }
        else
        {
            if (day > nrunnian[- month - 1])
            {
                cout << "invalid input";
                return 0;
            }
            else
            {
                dayth = day;
                tmonth = tmonth - 2;
                while (tmonth >= 0)
                {
                    dayth += nrunnian[tmonth];
                    tmonth--;
                }
            }
        }
        cout << year << "-" << month << "-" << day << " is the No." << dayth << " day of " << year << "." << endl;
        return 0;
    }
    cout << "invalid input";
    return 0;
}
