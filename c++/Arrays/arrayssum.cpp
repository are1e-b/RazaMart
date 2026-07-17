# include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,0,10};
    int n =sizeof(arr)/4;
    int sum=0;
    for(int i=0;i<=n;i++){
        sum+=arr[i];
    }
    cout<<"The sum of the array is: "<<sum<<endl;
    return 0;
}