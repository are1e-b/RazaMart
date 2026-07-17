# include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,4,100,19};
    int n =sizeof(arr)/4;
    int i=0;
    int j=n-1;
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";}
}