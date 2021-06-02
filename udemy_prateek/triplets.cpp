#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;

vvi tripletSum(vi arr, int Sum){
sort(arr.begin(),arr.end());
vvi res;
int n = arr.size();
for(int i = 0;i<=n-3;i++){
    int j = i + 1;
    int k = n - 1;

    while(j<k){
        int curSum = arr[i];
        curSum+= arr[j];
        curSum+=arr[k];
        if(curSum == Sum){
            res.push_back({arr[i],arr[j],arr[k]});
            j++;
            k--;
        }else if(curSum < Sum){
            j++;
        }else if(curSum > Sum){
            k--;
        }
    }
}
return res;
}
int main(){
vi arr{1,2,3,4,5,6,7,8,9,15};
int tgtSum = 18;
vvi res = tripletSum(arr,tgtSum);
for (auto x : res){
    vi tmp = x;
cout << "[" << tmp[0] << "," << tmp[1] << "," << tmp[2] << "]" << endl;
}
}