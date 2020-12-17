#include<iostream>
#include<vector>
#include<utility>
#include<set>
#include<algorithm>
#define MAX 500
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
// nlogn method (Implemented)
// minheap and max heap method (To look at)
// quick select partioning method - average - O(n) and worse O(n^2) (To look at)
void kthmin_max(vi a,int k){
    sort(a.begin(),a.end());
    // for min 
    cout << a[k-1];
    // for max 
    cout << a[a.size()-k+1];
}

int multiply(int x,int res[],int res_size){
int carry = 0;
for(int i = 0;i<res_size;i++){
    int prod = res[i]*x + carry;
    res[i] = prod %10;
    carry = prod/10;
}

while(carry){
res[res_size] = carry%10;
carry = carry/10;
res_size++;
}

return res_size;
}
void factorial_large(int n){
    int res[MAX];
    int res_size = 1;
    res[0] = 1;
    for(int i = 2;i<=n;i++){
        res_size = multiply(i,res,res_size);
    }
    // Printing Factorial with individual digits
    for(int i = res_size - 1;i>=0;i--){
        cout << res[i];
    }
} 

bool ifsubarrayzero(vi a){
    unordered_set<int>s;
    int sum = 0;
    for(int i = 1;i<a.size();i++){
        sum+=a[i];
        if(sum==0 || s.find(sum)!=s.end()){
            return true;
        }
        s.insert(sum);
 
    }
    return false;
}

bool subsetarray(vi a,vi b){

    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    while(i<n && j<m){

        if(a[i]==b[j]){
            i++;
            j++;
        }else if(a[i] < b[j]){
            i++;
        }else if(a[i] > b[j]){
            return 0;
        }
    }
    return (j<m) ? false : true;
}

void rearrangelalternate(vi a){
    int i = -1;
    for(int j = 0;j<a.size();j++){
        if(a[j]<0){
            i++;
            swap(a[i],a[j]);
        }
    }
    int pos = i+1;
    int neg = 0;
    int n = a.size();
    while(neg < n && pos < n && a[neg < 0]){
        swap(a[neg],a[pos]);
        pos++;
        neg+=2;
    }
}

// Doesnt handle duplicate
// Sorted case
void Union(vi a, vi b){
int i = 0;
int j = 0;
int n = a.size();
int m = b.size();
while(i<n && j<m){
if(a[i] < b[j]){
cout << a[i] << " ";
i++;
}else if(a[i] > b[j]){
cout << b[j] << " ";
j++;
}else {
    cout <<a[i] << " ";
    i++;
    j++;
}
}
if(n > m){
    while(i!=n){
        cout << a[i] << " ";
    }
}else{

    while(j!=m){
        cout << b[j] << " ";
    }
}
}
void Intersection(vi a,vi b){
int i = 0;
int j = 0;
int n = a.size();
int m = b.size();

while(i<n && j < m){
    if(a[i]==b[j]){
        cout << a[i] << " ";
        i++;
        j++;
    }else if(a[i] < b[j]{
        i++;
    }else if(a[i]>b[j]){
        j++;
    }
}
}
void rotate_one(vi &a){
    int n = a.size();
    int x = a[n-1];
    for(int i = n-1;i>0;i--){
        a[i] = a[i-1];
    }
    a[0] = x;
}

void commoninthreesorted(vi a,vi b,vi c){
int n = a.size();
int m = b.size();
int p = c.size();

int i,j,k;
i = j = k = 0;

while(i< n && j <m && k <p){
if(a[i] == b[j] == c[k]){
cout << a[i] << " ";
i++;
j++;
k++;
}else if(a[i] < c[k] && b[j] < c[k]){
i++;
j++;
}else if(a[i] < b[j] && c[k] < b[j]){
i++;
k++;
}else if(b[j]<a[i] && c[k] < a[i]){
j++;
k++;
}else if(a[i] < b[j] && b[j] == c[k]){
i++;
}else if (b[j] < a[i] && a[i] == c[k]){
j++;
}else if (c[k] < b[j] && a[i] == b[j]){
k++;
}

}
}

void triplet(vi a,int sum){
int n = a.size();

for(int i = 0; i <n ;i++){
    int l = i+1;
    int r = n-1;
    while(l!=r){
        if(a[i] + a[l] + a[r] == sum){
                cout << "Printall" << endl;
                cout << a[i] << " "<<a[l] << " "<< a[r] << endl;
                break;
        }else if(a[i] + a[l] + a[r] < sum){
                l++;
        }else if (a[i] + a[l] + a[r] > sum){
                r--;
        }
    }
}
}

int maxWater(int arr[], int n) 
{
     
    int res = 0;
     
    for (int i = 1; i < n-1; i++) {
         
        int left = arr[i];
        for (int j=0; j<i; j++)
           left = max(left, arr[j]);
         
        int right = arr[i];
        for (int j=i+1; j<n; j++)
           right = max(right, arr[j]); 
        
       res = res + (min(left, right) - arr[i]);   
    }
 
    return res; 
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
