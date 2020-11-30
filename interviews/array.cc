#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;

void print(vi a){
    for(auto x : a){
        cout<<x << " ";
    }
    cout<<endl;
}
void reverse(vi a){
int l = 0;
int r = a.size()-1;

while(l!=r){
    swap(a[l],a[r]);
    l++;
    r--;
}
print(a);
}

void min_max(vi a){
int mn = 1e9;
int mx = -1e9;

for(auto i : a){
mn = min(mn,i);
}

for(auto i : a){
mx = max(mx,i);
}
}

void test_cases(){
    vi a;
    reverse(a);
    min_max(a);
}
int main(){
test_cases();
}