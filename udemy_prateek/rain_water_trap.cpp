#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;

int watertrapped(vi heights){
int n = heights.size();
vi left(n), right(n);
left[0] = heights[0];
right[n-1] = heights[n-1];
// fill max from left
for(int i = 1;i<n;i++){
left[i] = max(heights[i-1],heights[i]);
}
// fill max from right
for(int i = n-1;i>=0;i--){
right[i] = max(heights[i],heights[i-1]);
}
// for(auto x : left){
//     cout << x << " ";
// }
// cout << "\n";
// for(auto x : right){
//     cout << x << " ";
// }
//cout << "\n";
int watertrapped = 0;
for(int i = 0;i<n;i++){
    watertrapped+= min(left[i],right[i]) - heights[i];
}

return watertrapped;
}
int main(){
vi height {0,1,0,2,1,0,1,3,2,1,2,1};

cout << watertrapped(height);
return 0;
}