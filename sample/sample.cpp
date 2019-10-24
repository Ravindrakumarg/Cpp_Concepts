

#include <iostream>

using namespace std;

int main ()

{
     int workDays;
     float workHours, payRate, weeklyPay;

      workDays = 5;
      payRate = 38.55; 

      cout<< "Enter the number of hours worked: ";
      cin >> workHours;
      cin.ignore ();

      weeklyPay = workDays * workHours * payRate;

      cout << "Weekly Pay = ";
      cout << weeklyPay;
      cout << '\n';

       return 0;
 }