#include<iostream>
#include<string>
using namespace std;

// reverse a string
void reverse(string a){
    int l = 0;
    int r = a.size()-1;
    while(l!=r){
        swap(a[l],a[r]);
        l++;
        r--;
    }
}
// check if string palindrome or not
bool ifPalindrome(string a){
    if(a.size() == 0 || a.size()==1){
        return true;
    }
    int l = 0;
    int r = a.size()-1;
    while(l!=r){
        if(a[l]!=a[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
/* Strings are immutable (cannot be change) in java because of security purposes
*/

int main(){
    
}