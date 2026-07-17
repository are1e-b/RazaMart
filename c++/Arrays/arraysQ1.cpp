# include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,4,100,19};
    int n =sizeof(arr)/4;
    for(int i=0;i<n;i++){
        if(i%2==0){
           cout<<arr[i]*2<<" ";
        }
        else{
            cout<<arr[i]+10<<" ";
        }
    
    }
}
    