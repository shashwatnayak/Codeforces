#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<int,int> pii;

bool duplicatenumber(vi a);
mii m;
for(int i = 0;i<a.size();i++){
  m[a[i]]++;
}
map<int,int> iterator :: itr = m.begin();
while(itr! = m.end()){
  if(itr->second>1){
    return true;
  }
  itr++;
}
return false;
}

pii findint(vi a,int v){
  pii ans;
  mii m;

  for(int i = 0;i<a.size();i++){
    m.insert(pii(a[i],v-a[i]));
  }
  mii iterator it = m.begin();
  for(int i = )
  
}
int main(){


}
