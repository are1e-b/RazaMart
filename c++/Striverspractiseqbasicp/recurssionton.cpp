#include <iostream>

using namespace std;
int cnt=0;
int sum = 0;
void print(int i, int n){
    if(i>n) return;
    cout<<"name"<<endl;
    print(i + 1, n);
    cnt++;

}
void print1(int i, int n){
    if(i>n) return;
    cout<<i<<endl;
    print1(i + 1, n);
    cnt++;

}
void print2(int n){
    if(n<0) return;
    print2( n-1);
    cout<<n<<endl;
    
    cnt++;

}
int suM( int n){
    if(n==0) return 0;
    
    return n + suM(n-1);
   
}
void reversearray(int arr[], int n, int i){
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    reversearray(arr, n, i+1);
}
int main(){
    int arr[5];
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }
    int n = 5;
    reversearray(arr, n, 0);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}