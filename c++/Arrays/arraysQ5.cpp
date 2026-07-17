# include <iostream>
using namespace std;
int main(){
    int a[5]={1,2,4,1,10};
    int b[5];
    for(int i=0;i<5;i++){
        int j=4-i;
        b[i]=a[j];}
    for(int i=0;i<5;i++){
        cout<<b[i]<<" ";}

    


    
    
    return 0;
    }