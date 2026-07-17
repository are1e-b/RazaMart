# include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,4,100,19};
    int n =sizeof(arr)/4;
    int mx=arr[0];
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
        }
    int smx=arr[0];
    for(int i=0;i<n;i++){
       if(arr[i]!=mx) smx=max(smx,arr[i]);
    }
    cout<<"The second maximum element in the array is: "<<smx<<endl;
    return 0;
}