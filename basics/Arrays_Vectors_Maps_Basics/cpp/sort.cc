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

void merge(vi& a,int l,int m,int r){
int i,j,k;

int n1 = m - l + 1 ;
int n2 = r - m ;
vi left(n1);
vi right(n2);
for(i = 0 ;i<n1;i++){
  left.push_back(a[l+i]);
}
for(j = 0;j<n2;j++){
  right.push_back(a[k+1+j]);
}
i = 0;
j = 0;
k = l;

while(i< n1 && j < n2 && l <= r){
  if(left[i] <= right[j]){
    a[k] = left[i];
    i++;
  }else{
    a[k] = right[j];
    j++;
  }
  k++;
}
while(i<n1){
  a[k] = left[i];
  i++;
  k++;
}
while(j<n2){
  a[k] = right[j];
  j++;
  k++;
}

}
void mergesort(vi& a,int l ,int r){
//split array into 2 parts
//recursively follow up in first half
//recursively follow up in second half;
//merge both and return array
if(l<r){
int k = (l+r)/2;
mergesort(a,l,k);
mergesort(a,k+1,r);
merge(a,l,k,r);
}
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

mergesort(a,0,a.size()-1);
}
