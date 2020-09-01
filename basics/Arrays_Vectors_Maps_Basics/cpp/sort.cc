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
    for(int j = 0;j<n;j++){
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
void mergesort(){

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
//sort(a.begin(),a.end());
bubble(a);
print(a);
}
