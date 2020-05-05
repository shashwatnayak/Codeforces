#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



// void foo(vector<string>in,vector<string>&out){
// string a,b;

// for(int i = 0;i<in.size();i++){
//   a = in[i];
//   if(a.size()>10){
//     b += a[0];
//     b += to_string(a.size()-2);
//     b += a[a.size()-1];
//     out[i] = b;
//     b.clear();
//   }else{
//     out[i] = a;
//   }
//   a.clear();
// }
// }
int main(){
  // int n;
  // cin>>n;
  // vector<string> in(n);
  // vector<string> out(n);
  // for(int i = 0;i<n;i++){
  //     string s;
  //     cin>>s;
  //     //cout<<"hre";
  //     in[i] = s;
  //     s.clear();
  // }
  // // for(auto s : in){
  // //   cout<<s;
  // // }
  // foo(in,out);

  // for(auto a : out){
  //  cout<<a<<endl;
  // }

  // string a,b,c;
  // cin>>a;
  // //cin>>b;
  // b = a.size() + '0';
  // cout<<b<<endl;
  // cout<<a[0];
  // cout<<a[a.size()-1];
  // c+=a[0];
  // c+=b;
  // c+=a[a.size()-1];
  // cout<<c;

  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i = 0;i<n;i++){
    int p;
    cin>>p;
    arr[i] = p;
  }
  if(arr[0]==0){
    cout<<arr[0];
    exit(1);
  }
  for(int i = 0;i<n;i++){
    arr[i] = arr[i] - arr[k-1];
  }
  int c = 0;
  for(int i = 0;i<n;i++){
    if(arr[i]>0){
      c++;
    }
  }
  cout<<c;
}