# include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,4,1,10};
    int n =sizeof(arr)/4;
    int product=1;
    for(int i=0;i<=n-1;i++){
        product*=arr[i];
    }
    cout<<"The product of the array is: "<<product<<endl;
    return 0;
}