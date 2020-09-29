#include<iostream>
using namespace std;

#define N 10000
int n, t[1<<N];

void build(int a[],int v,int l,int r){
if(l == r){
t[v] = a[l];
}else{
    int m = (l+r)/2;
    build(a,2*v,l,m);
    build(a,2*v+1,m+1,r);
    t[v] = t[v*2] + t[2*v+1];
  }
}

int sum(int v,int tl,int tr,int l,int r){
if(l>r){
    return 0;
}
if(l == tl && r == tr){
    return t[v];
}
int tm = (tl+tr)/2;

return sum(2*v,tl,tm,l,min(r,tm)) + sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}

void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){
        t[v] = val;
    }else{
        int tm = (tl + tr)/2;
        if(pos<=tl){
            update(2*v,tl,tm,pos,val);
        }else{
            update(2*v+1,tm+1,tr,pos,val);
        }
        t[v] = t[v*2] + t[2*v+1]; 
    }
}
int main(){

//cin>>n;
int a[] = {8,1,2,3,4,5,6,7};
n = sizeof(a)/sizeof(a[0]);
build(a,1,0,n-1);
for(int i = 0;i<n;i++){
    cout<<t[i]<<" ";
}
}