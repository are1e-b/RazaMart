# include <iostream>
using namespace std;
int main(){
    int arr[]={130,240,450,100,1000};
    int n =sizeof(arr)/4;
    int x;
    cout<<"inter the number for which we have to count the nuber of elements greater than x in the array"<<endl;
    cin>>x;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            count++;
        }
    }
    cout<<"The number of elements greater than "<<x<<" in the array is: "<<count<<endl;

}