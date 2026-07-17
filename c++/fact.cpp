#include<iostream>
using namespace std;
int fact(int a)

{
    if(a==1 or a==0) return 1;
    return a *fact(a-1);
}
int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;
    cout << "The factorial is: " << fact(a) << endl;
    return 0;
}_getws