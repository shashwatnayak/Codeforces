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

void kadane_algo(vi a){
int n = a.size();
int max_sum = a[0];
int cur_max = a[0];

for(int i = 1;i<n;i++){
cur_max = cur_max + a[i];
if(cur_max<0){
    cur_max = 0;
}else if(cur_max > max_sum){
    max_sum = cur_max;
}
}
cout << max_sum << endl;
}

void duplicate_nplusone(vi a,int n){
int n_t = a.size();
int ss = ((n)*(n+1))/2;
int ts = 0;
for(auto x : a){
    ts+=x;
}

cout << ts - ss << "\n";
}

void move_all_negative_atoneend(vi a){
    int j = 0;
    for(int i = 0;i<a.size();i++){
        if(a[i]<0){
            if(i!=j){
            swap(a[i],a[j]);
            }
            j++;
        }
    }
    print(a);
}
void test_cases(){
    vi a;
    reverse(a);
    min_max(a);
    sort_012(a);
    kadane_algo(a);
    move_all_negative_atoneend(a);
    duplicate_nplusone(a,a.size()-1);
}
int main(){
test_cases();
}