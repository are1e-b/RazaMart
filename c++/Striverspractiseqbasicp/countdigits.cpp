#include <iostream>
#include <cmath>
using namespace std;
int revDigits(int n){
    
    int rev=0;
    while(n>0){
        int rem=n%10;
        rev =rev*10+rem;
        n=n/10;
        
    }
    return rev;

}
bool ispalindrome(int n){
    if(n==revDigits(n)){
        return true;
        
    }
    else{
        return false;
    }

}
int isamstrong(int n){
    int temp=n;

    int sum=0;
    while(n>0){
    int ld=n%10;
    sum+=ld*ld*ld;
    n=n/10;}
    if(temp==sum){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
        
    }
}
int printdivisors(int n){
    for(int i=n/2;i>=1;i--){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}
void primenumber(int n){
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            cout<<"is not prime number"<<endl;}
        return;
        }
        
         cout<<"is  prime number"<<endl;
    return;

   
    }
void HCF(int a,int b){
    int hcf=1;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            hcf=i;
        }
    }
    cout<<hcf<<endl;
}

int main(){
    int n;
    cin>>n;
    int h;
    cin>>h;
    HCF(n, h);
    return 0;
}