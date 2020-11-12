#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;
void arr_Dep (int *h_arr, int *m_arr, int *h_dep, int *m_dep)
{

cout << "Please Enter the Time Your Car Arrived in the Parking Deck" << endl;
cout << endl;
cout << "***Time should be entered based on a 24-hour clock***" << endl;
cout << "\n(Hours should be entered from - 0 to 23 - and minutes should be entered from - 0 to 59 -)"<< endl;
cout << "Hours> ";
cin>>*h_arr;
cout << "Minutes> ";
cin >> *m_arr;
cout << endl;

cout << "Please Enter Time Your Car left the Parking Deck" <<endl;
cout << endl;
cout << "***Time should be entered based on a 24-hour clock***" << endl;
cout << "\nHours should be entered from - 0 to 23 - and minutes should be entered from - 0 to 59 -"<< endl;
cout << "Hours> ";
cin >> *h_dep;
cout << "Minutes> ";
cin >> *m_dep;

}
int park_Cal (int h_arr, int m_arr, int h_dep, int m_dep)
{
int total_time, arr_h, arr_m;

arr_h = h_arr - h_dep;
arr_m = m_arr - m_dep;
total_time = ((arr_h * 60) + arr_m)*-1;
if(total_time<0)
{

total_time=total_time*-1;
total_time=total_time-120;
}
return total_time;
}
double bill_amt(int total_time, int h_arr, int m_arr, int h_dep, int m_dep )
{
double charge;
if (total_time > 720 && total_time <= 1440)
{

cout << "An Error Has Occurred, Please Go To Main Building To Resolve Issue";
exit(0);
}
if (h_arr == 55 && m_arr ==55)
{
cout << "Please Deposit $110.00";
exit(0);
}
if (h_arr == 99 && m_arr ==99)

{cout << "You have a Special Pass, Please Deposit $5.00";
exit(0);
}
if (total_time <=30)
cout << "Please Deposit $3.00";
if (total_time > 30 && total_time <= 60)
cout << "Please Deposit $5.00";
if (total_time > 60 && total_time <= 120)
cout << "Please Deposit $10.00";
if (total_time > 120 && total_time <= 180)
cout << "Please Deposit $15.00";
if (total_time > 180 && total_time <= 240)
cout << "Please Deposit $30.00";
if (total_time > 240 && total_time <= 720)
{
charge = 30;
int c = total_time - 240;
for(int i=0;i<c;i=i+30)
charge=charge+5;
cout << "Please Deposit "<<charge;
}

return charge;

}
void printrec (int h_arr, int m_arr, int h_dep, int m_dep, int total_time)
{

cout << "Your Arrival time was "<< h_arr << ":" << m_arr << endl;
cout << endl;
cout << "Your Departure time is "<< h_dep << ":" << m_dep << endl;
cout << endl;
}
int main()
{
int h_arr, m_arr, h_dep, m_dep, total_time;

arr_Dep(&h_arr, &m_arr, &h_dep, &m_dep); // call function to generate random numbers.
total_time=park_Cal(h_arr, m_arr, h_dep, m_dep);

cout << "****Printing your receipt****\n";

printrec(h_arr, m_arr, h_dep, m_dep, total_time);

bill_amt(total_time,h_arr, m_arr, h_dep, m_dep);

cout << endl;

return 0;

}
