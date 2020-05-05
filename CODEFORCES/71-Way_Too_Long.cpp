#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 
 
 
void foo(vector<string>in,vector<string>&out){
string a,b;
 
for(int i = 0;i<in.size();i++){
  a = in[i];
  if(a.size()>10){
    b += a[0];
    b += to_string(a.size()-2);
    b += a[a.size()-1];
    out[i] = b;
    b.clear();
  }else{
    out[i] = a;
  }
  a.clear();
}
}
int main(){
  int n;
  cin>>n;
  vector<string> in(n);
  vector<string> out(n);
  for(int i = 0;i<n;i++){
      string s;
      cin>>s;
      //cout<<"hre";
      in[i] = s;
      s.clear();
  }
  // for(auto s : in){
  //   cout<<s;
  // }
  foo(in,out);
 
  for(auto a : out){
   cout<<a<<endl;
  }
}