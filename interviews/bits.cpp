#include<iostream>
using namespace std;

void count_setbits(int n){
int count = 0;

while(n!=0){
    if(n&1)count++;
    n= n>>1;
}

cout<<" "<<count<<"\n";
}

void power_set(int n){

for(int i = 1;i<(1<<n);i++){
    for(int j = 0;j<n;j++){
        if(i&(1<<j)){
            cout<<i<< " ";
        }
    }
    cout<<endl;
}
}

void power_two_or_not(int n){
bool a = false;
if((n)&(n-1)){
a = true;
}else{
a = false;
}

cout << a << endl;
}
void test_cases(){
    int x;
    cout<< " Enter a number \n";
    cin>>x;

    count_setbits(x);
    power_set(x);
    power_two_or_not(x);
}
int main(){
    test_cases();    
return 0;    
}