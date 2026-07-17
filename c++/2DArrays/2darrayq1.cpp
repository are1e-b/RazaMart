//write a program to store 10 at every index of 2d array matrix of 5 rows and 5 columns and print the matrix
#include <iostream>
using namespace std;
int main()
{
    int arr[5][5];
    // Initialize all elements to 10
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr[i][j] = 10;
        }
    }
    cout<<"The matrix with all elements as 10 is: "<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}