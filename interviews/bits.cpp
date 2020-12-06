#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
void count_setbits(int n){
int count = 0;

while(n!=0){
    if(n&1)count++;
    n= n>>1;
}

cout<<" "<<count<<"\n";
}

void power_set(int n){

for(int i = 0;i<(1<<n);i++){
    for(int j = 0;j<n;j++){
        if(i&(1<<j)){
            // all element here like a[j]
            cout<<j<< " ";
        }
    }
    cout<<endl;
}
}

bool power_two_or_not(int n){
bool a = false;
if(n && (!(n)&(n-1))){
a = true;
}else{
a = false;
}

cout << a << endl;
return a;
}
// Similar to odd and even occurences question
void two_non_repeating(vi a){
int xor_all = 0;
int set_xor_bit = 0;
int x_el,y_el;
x_el = y_el = 0;

// Calculate xor of all elements
for(int i = 0;i<a.size();i++){
    xor_all = xor_all^a[i];
}
// Calculate righmost set bit of xor elements;
set_xor_bit = xor_all & ~(xor_all-1);

// Divide array into two sets, the rightmost setbit of two numbers will make every make
// every other element zero. so we'll get 2 different numbers

for(int i = 0;i<a.size();i++){
    if(a[i] & set_xor_bit){
        x_el = x_el^a[i];
    }else{
        y_el = y_el^a[i];
    }
}

cout<< x_el << " "<<y_el << "\n";
}


void convertA_B_setbits(int x,int y){
count_setbits(x^y);
}

// Get Log2n is another method;
void only_setbit(unsigned a){

if (power_two_or_not(a)){
int pos = 1;
while(a!=0){
if(a & 0 == true){
cout << pos << endl;
break;
}else{
pos ++;
a = a/2;
}

} 

}else {
    cout << "Invalid number";
}
}

void copy_setbit_inrange(unsigned x,unsigned y,int l,int r){
if(l<1 || r>32)return;

// copy 1 bit by bit
for(int i=l;i<=r;i++){
int mask = 1 << (i-1);
if(y&mask){
    x|=mask;
}
}
cout << x;
// do it all together
/*
int masklength = (1 << (r-l+1)) - 1;
int mask = ((masklength) << (l-1)) & y;
x|=mask;
*/
}

int counthelp(unsigned int x){
    if(x<=0)return 0;

    if(x%2==0){
        return counthelp(x/2);
    }else{
        return 1 + counthelp(x/2);
    }
}

// other way to count is by DP. Since there are overlapping substructures
void count_totalsetbits(int n){
int bcount = 0;
for(int i = 0;i<n;i++){
bcount+=counthelp(i);
}
cout << bcount;
}
void test_cases(){
    int x;
    cout<< " Enter a number \n";
    cin>>x;

    count_setbits(x);
    power_set(x);
   cout <<  power_two_or_not(x);
    vi a;
    two_non_repeating(a);
    int x,y;
    convertA_B_setbits(x,y);
    unsigned b = 128;
    only_setbit(b);
    copy_setbit_inrange(7,11,2,3);
    count_totalsetbits(5);
}
int main(){
    test_cases();    
return 0;    
}