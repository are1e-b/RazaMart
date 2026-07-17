#include <iostream>
using namespace std;
int main()
{
    int a[2][4]={{1,2,3,4},{5,6,7,8}};
    int b[2][4]={{9,10,11,12},{13,14,15,16}};
    
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cout<<a[i][j]<<" ";
        }
    
    cout<<endl;}
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cout<<b[i][j]<<" ";
        }
    
    cout<<endl;}
    cout<<"The sum of the two matrices is:" <<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cout<<a[i][j]+b[i][j]<<" ";
        }
        cout<<endl;
    }
        
    
    
    return 0;
}