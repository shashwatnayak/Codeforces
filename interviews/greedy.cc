#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> vi;
//Activity Selection Problem
struct Activity{
int start, finish;
};
bool ActivityCompare(Activity s1,Activity s2){
    return (s1.start < s2.finish);
}

void activity_selection(Activity arr[],int n){
//Sort Activity from finish
sort(arr,arr+n,ActivityCompare);
// print 1st activity
int i = 0;
cout << arr[i].start << " " << arr[i].finish << "\n";
for(int j = 1;j<n;j++){
    // if start greater than previous finish then print it
    if(arr[j].start >= arr[i].finish){
        cout << arr[j].start << " " << arr[j].finish << "\n";
        i = j;
    }
}
}
struct Job{
    char id;
    int deadline;
    int profit;
};
bool Compare(Job a, Job b){
return (a.profit > b.profit);
}
void job_sequencing(Job arr[],int n){
sort(arr,arr+n,Compare);
bool slot[n];
int result[n];
for(int i = 0;i<n;i++){
    slot[i] = false;
}

for(int i = 0;i<n;i++){
    for(int j = min(n,arr[i].deadline)-1;j>=0;j--){
        if(slot[j] == false){
            slot[j] = true;
            result[j] = i;
            break;
        }
    }
}

for(int i = 0;i<n;i++){
    if(slot[i]){
        cout << arr[result[i]].id << " ";
    }
}
}

//Similar to Activity Selection Problem
void maximum_train(){

}

void minimum_platform(vi arr, vi dep){
sort(arr.begin(),arr.end());
sort(dep.begin(),dep.end());
int plat_max = 1;
int res = 1;
int i,j;
i = j = 0;
int n = arr.size();
while(i < n && j < n){

    if(arr[i] < dep[j]){
        plat_max++;
        i++;
    } else if(arr[i] > dep [j]){
        plat_max--;
        j++;
    }
    if(plat_max > res){
        res = plat_max;
    }
}
cout << res << " ";
}

void maximise_ar_i(vi a){
int sum = 0;
sort(a.begin(),a.end());
for(int i = 0;i<a.size();i++){
    sum += i*a[i];
}
cout << sum << endl;
}

void max_subset_product(vi a){
    
}
void test_cases(){
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    activity_selection(arr,n);

    Job ar[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}}; 
    int nx = sizeof(arr)/sizeof(arr[0]); 
    job_sequencing(ar,nx);
}
int main(){
    test_cases();
}