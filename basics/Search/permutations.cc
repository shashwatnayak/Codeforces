#include<iostream>
#include<vector>
using namespace std;

//Permutation using backtracking
void permute(string a,int l,int r){
  if(l==r){
    cout<< a <<endl;
  }else{

    for(int i = l; i<=r;i++){
      swap(a[l],a[i]);
      permute(a,l+1,r);
      swap(a[l],a[i]);
    }
  }
}
void search(){
  if(perm.size()==n){
    
  }else{

    for(int i = 0;i<n;i++){
      if(chosen[i]) continue;
      perm.push_back(i);
      search();
      chosen[i] = false;
      perm.pop_back();
    }
  }
}
int main(){


  return 0;
}
