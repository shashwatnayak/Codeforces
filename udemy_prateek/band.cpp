#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
typedef vector<int> vi;

int longestchain(vi arr){
unordered_set<int>s;
for(int x : arr){
    s.insert(x);
}
int longest_chain = INT_MIN;
for(int x : arr){
    int parent = x - 1;

    if(s.find(parent) == s.end()){
        // if parent found then start finding other element;
        int cnt = 1;
        int next_child = parent+1;
        while(s.find(next_child)!=s.end()){
            cnt++;
            next_child++;
        }

        if(cnt > longest_chain){
            longest_chain = cnt;
        }
    }
}
return longest_chain;
}
int main(){
vi arr{1,9,3,0,18,5,2,4,10,7,12,6};
cout << longestchain(arr);
}