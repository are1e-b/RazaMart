#include<iostream>
using namespace std;
int fibo(int a)

{
    if(a==1 or a==0) return 1;
    return fibo(a-1) + fibo(a-2);
}
int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;
    cout << "The Fibonacci is: " << fibo(a) << endl;
    return 0;
}