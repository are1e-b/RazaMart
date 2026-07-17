#include <iostream>
using namespace std;
int main()
{
    int arr[2][4];
    cout<<"Enter the roll number and marks of students: "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"The entered values are: "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}