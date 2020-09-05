#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;

void print(vi v){
  for(auto x:v){
    cout<<x<< " ";
  }
  cout<<"\n";
}

//General subset using bit manipulation
void subsets(int n){

  for(int i = 0;i<(1<<n);i++){
    vi subset;
    for(int j = 0;j<n;j++){
      if(i&(1<<j)){
        subset.push_back(j);
      }
    }
    print(subset);
    subset.clear();
  }
}
// printing subsets of given vector(can used for both strings and integer)
void printSubofarr(vi v){
  int n = v.size();
  for(int i = 0;i<(1<<n);i++){
    for(int j = 0;j<n;j++){
      if(i&(1<<j)){
        cout<<v[j]<< " ";
      }
    }
    cout<<"\n";
  }

//using recursion
void SubsetsRec(string str,int k = 0,string cur = ""){

int n = str.size();
if(k==n){
  cout<<cur<<endl;
  return;
}else{
  SubsetsRec(str,k+1,cur + str[k]);
  SubsetsRec(str,k+1,cur);
}

}

int main(){
// int n;
// n = 3;
// subsets(n);
vi b = {0,1,3};
printSubofarr(b);
}
