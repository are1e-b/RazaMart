# include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,4,100,19};
    int n =sizeof(arr)/4;
    int mx=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>mx){
            mx=arr[i];
            //or
            mx=max(mx,arr[i]);
        }
    }
    cout<<"The maximum element in the array is: "<<mx<<endl;
    return 0;
}