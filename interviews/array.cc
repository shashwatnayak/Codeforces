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
void sort_012(vi a){
int zero = 0;
int one = 0;
int two = 0;

for(auto x: a){
    if(x == 0){
        zero++;
    }else if(x==1){
        one++;
    }else if(x = 2){
        two++;
    }
}
int i;
i = 0;
int n = a.size();
while(i<n){
 a[i] = 0;
 i++;
 zero--;   
}

while(i<n){
 a[i] = 1;
 i++;
 one--;   
}

while(i<n){
 a[i] = 0;
 i++;
 two--;   
}
}
void test_cases(){
    vi a;
    reverse(a);
    min_max(a);
    sort_012(a);
}
int main(){
test_cases();
}