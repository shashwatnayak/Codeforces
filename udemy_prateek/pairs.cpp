#include<iostream>
#include<vector>
//#include<algorithm>
#include<unordered_set>
using namespace std;

typedef vector<int> vi;

vi pairSum(vi arr,int tgtsum){
vi res;
unordered_set<int> s;

for(int x : arr){
    int ele = x;
    if(s.find(tgtsum-ele)!=s.end()){
        res.push_back(tgtsum-ele);
        res.push_back(ele);
        break;
    }
    s.insert(ele);
}
return res;
}

int main(){
vi arr {10,5,2,3,-6,9,11};
int tgtsum = 4;
vi res = pairSum(arr,tgtsum);

cout<<"{"<<res[0]<<","<<res[1]<<"}"<<endl;
}
