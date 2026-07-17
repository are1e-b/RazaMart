#include<iostream>
using namespace std;
void print1(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=-i+n+1;j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        
        cout<<endl;}
    }
void print2(int n){
     for(int i=1;i<=n;i++){
        
        
        for(int j=1;j<=i;j++){ 
            cout<<"  ";
        }
        for(int j=1;j<=2*n-(2*i-1);j++){
            cout<<"* ";
        }
        
        cout<<endl;}

}
void print3(int n){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=-i+n+1;j++){
            cout<<"  ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"* ";
        }
        
        
        cout<<endl;}
    }
void print4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        for(int j=1;j<=n;j++){
            cout<<"  ";
        }
        
        cout<<endl;}
    }
void print5(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=-i+n;j++){
            cout<<"* ";
        }
        for(int j=1;j<=i;j++){
            cout<<"  ";
        }
        
        
        cout<<endl;}
    }
void print6(int n){
    for(int i=1;i<=n;i++){
        int space=2*(n-1);
        for(int j=1;j<=i;j++){
            cout<<j ;
        }
        for(int j=i;j>=space;j--){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<j ;
        }
        
        cout<<endl;
        space+= 2;}
}
int main(){
//how was that shit outt of box
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
   
    print6(n);

}