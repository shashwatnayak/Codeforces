#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;

typedef vector<int> vi;
typedef map<int,int> mi;
typedef pair<int,int> pi;
typedef map<int,pi> mpi;

// a+b = c+d

void printpairs(vi a){
  int n = a.size();
  mpi mp;

  for(int i = 0;i<n;i++){
    for(int j = i + 1;j<n;j++){

      int sum = a[i] + a[j];
      if(mp.find(sum) == mp.end()){ // if no new sum add into map
        mp[sum] = make_pair(i,j);
      }else{                        // else sum exist, get other pairs that matches with it
        pi p = mp[sum];
        int first_pair = p.first;
        int second_pair = p.second;

        cout << "(" <<a[first_pair] <<","<< a[second_pair] <<")"<< " = " <<"("<< a[i] <<","<< a[j] << ")\n";
        // doesnt handle duplication
        // Prints all pairs
        // return true;
      }
    }
  }
  // return false;
}

// a+b = c

void printabc(vi a,int c){
int n = a.size();
// o n^2
// for(int i = 0;i<n;i++){
//   for(int j = i + 1 ;i<n;i++){
//     if(a[i] + a[j] == c){
//       cout <<a[i] << " " << a[j] <<endl;
//     }
//   }
// }

// o n
mi m;
for(int i = 0;i<n;i++){
  int diff = c - a[i];
  m[diff] = a[i];
}
for(int i = 0; i<n;i++){
  if(m.find(a[i]) == m.end()){
    cout << "No pair" <<endl;
  }else{
    cout << a[i] << "+" << m[a[i]] <<endl;
  }
}
}
int main(){
vi a;
a.push_back(3);
a.push_back(7);
//a.push_back(4);
//a.push_back(1);
a.push_back(2);
a.push_back(9);
//a.push_back(8);

//printpairs(a);

printabc(a,10);
}
