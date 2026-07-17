#include<iostream>
using namespace std;
int sum(int a)

{
    if(a==1 or a==0) return 1;
    return a +sum(a-1);
}
int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;
    cout << "The sum is: " << sum(a) << endl;
    return 0;
}