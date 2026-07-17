# include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,4,1,10};
    int n =sizeof(arr)/4;
    int oddcount=0;
    int evencount=0;

    
    for(int i=0;i<n;i++){
        if(i%2==0){

            evencount+=arr[i];
        }
        else{
            oddcount+=arr[i];
            }}
       cout<<"the difference between even and odd numbers in the array  is: "<<evencount-oddcount<<endl;
    
        }

