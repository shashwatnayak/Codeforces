#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

void print(vi v){

  for(auto i : v){
    cout << i << " ";
  }
  cout<<"\n";
}

//bubble o n^2
//pass by referance to change the array dynamically in vector
void bubble(vi& a){
  int n = a.size();
  for(int i = 0;i<n;i++){
    for(int j = i + 1;j<n;j++){
      if(a[i] < a[j]){
        swap(a[i],a[j]);
      }
    }
  }
}
//insertion o n^2
void insertion(vi& a){

}
//selection o n^2
void selection(vi& a){}

//mergesort o nlgn
//seg fault error in mergesort maybe due to vector, can try for array

void merge(vi& left,vi& right,vi& orig){
int i = 0, j = 0, k = 0;
int n1 = left.size();
int n2 = right.size();

while(i < n1 && j < n2 ){
  if(left[i] <= right[j]){
    orig[k] = left[i];
    i++;
  }else{
    orig[k] = right[j];
    j++;
  }
  k++;
}
while(i < n1){
  orig[k] = left[i];
  i++;
  k++;
}
while(j  <n2){
  orig[k] = right[j];
  j++;
  k++;
}
}
void mergesort(vi& a){
//split array into 2 parts
//recursively follow up in first half
//recursively follow up in second half;
//merge both and return array
vi left;
vi right;
int mid = (a.size()/2);
for(int i = 0;i<mid;i++){
  left.push_back(a[i]);
}
for(int j = 0;j<(a.size()) - mid;j++){
  right.push_back(a[j+mid]);
}

mergesort(left);
mergesort(right);
merge(left,right,a);
}
//quicksort o lgn
void quicksort(){

}

int main(){
vi a;
a.push_back(2);
a.push_back(1);
a.push_back(6);
a.push_back(4);
a.push_back(5);
print(a);
//sort(a.begin(),a.end());  // for algorithm header
//qsort(a.begin(),a.end()) // for quicksort shortcut in algorithm header
// bubble(a);
// print(a);

mergesort(a);
print(a);
}
