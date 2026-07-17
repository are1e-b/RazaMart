# include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of arrays till which you want to find the suare of the numbers"<<endl;
    cin>>n;
    int arr[n];
   
    for(int i=1;i<=n;i++){
        arr[i]=i*i;
        
        cout<<arr[i]<<" ";
    }
}