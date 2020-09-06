//Find Maximum possible sum with subset of integers present in array
// MEET IN THE MIDDLE Technique
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;
ll xray[200005],yray[200005];

void calcsubarraysum(ll arr[],ll x[],int n,int c){

  for(int i = 0;i<(1<<n);i++){
    ll s = 0;
      for(int j = 0;j<n;j++){
        if(i&(1<<j)){
          s+=arr[j+c];
        }
      }
      x[i] = s;
  }
}


ll solvesubsetsum(ll a[],int n,int sum){
  calcsubarraysum(a,xray,n/2,0);
  calcsubarraysum(a,yray,n-n/2,n/2);

  int xsize = 1<<(n/2);
  int ysize = 1<<(n-n/2);
  sort(yray,yray+ysize);
  ll maxsum = 0;
  for(int i = 0;i<xsize;i++){
    if(xray[i]<=sum){
      int p = lower_bound(yray,yray+ysize,sum - xray[i]) - yray;
      if(p==ysize || yray[p]!=sum-xray[i]){
        p--;
      }
      if(yray[p] + xray[i] > maxsum){
        maxsum = yray[p] + xray[i];
      }
    }
  }
  return maxsum;
}

int main(){
  ll a[] = {3,34,4,12,5,2};
  int n = sizeof(a)/sizeof(a[0]);
  ll s = 10;
  printf("%lld\n",solvesubsetsum(a,n,s));
}
