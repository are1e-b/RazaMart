#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    int k;
    cout<<"Enter the number of rows: ";
    cin>>k;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=i;j++){
            cout<<j ;
        }
        cout<<endl;
    }

    int u;
    cout<<"Enter the number of rows: ";
    cin>>u;
    for(int i=1;i<=u;i++){
        for(int j=1;j<=i;j++){
            cout<<i ;
        }
        cout<<endl;
      
    }
}