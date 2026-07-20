# include <iostream>
using namespace std;
bool ispalindrome(char str[],int i,int n){
    if(i>=n/2) return true;
    if(str[i]!=str[n-i-1]) return false;
    
  
    
    return ispalindrome(str,i+1,n);

}
int main(){
   char str[] = "123212";

    if (ispalindrome(str, 0, 5)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }
}

