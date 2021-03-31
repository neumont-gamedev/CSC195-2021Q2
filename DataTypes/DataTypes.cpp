// DataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    string name;
    char initial;
    unsigned short age;
    bool isAdult;
    unsigned int zipcode;
    float wage;
    unsigned short daysWorked;
    unsigned short hoursWorkedPerDay[7];

    const float TAX = 0.1f;

    cout << "enter first name: ";
    cin >> name;
    cout << "enter last initial: ";
    cin >> initial;

    cout << "enter age: ";
    cin >> age;
    isAdult = (age >= 18);

    cout << "enter zipcode: ";
    cin >> zipcode;

    cout << "enter wage: ";
    cin >> wage;

    cout << "enter days worked: ";
    cin >> daysWorked;

    for (int i = 0; i < daysWorked; i++)
    {
        cout << "enter hours worked for day " << i + 1 << ": ";
        cin >> hoursWorkedPerDay[i];
    }

    int totalHours = 0;
    for (int i = 0; i < daysWorked; i++) totalHours += hoursWorkedPerDay[i];

    float gross = totalHours * wage;
    float net = gross - (gross * TAX);

    cout << name << " worked " << totalHours << " hours at $" << wage << " an hour.\n";
    cout << "gross income: $" << gross << endl;
    cout << "net income: $" << net << endl;
}

