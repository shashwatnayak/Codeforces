#include<iostream>
using namespace std;

/***********************************
 * Fenwick Tree Theory
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * *********************************/

// Not build as well 
//Explaination ?? s
int sum(int tree[],int n,int k){
int s = 0;
while(k>=1){
    s+=tree[k];
    k-=k&(-k);
}
return s;
}
void add(int tree[],int n,int k,int x){
k++;
while(k<=n){
    tree[k]+=x;
    k+=k&(-k);
}
}
void constructFenwickTree(int arr[],int n){

    int *ftree = new int[n+1];
    for(int i = 1;i<=n;i++){
        ftree[i] = 0;
    }

    for(int i = 0;i<n;i++){
        add(ftree,n,i,arr[i]);
    }
}
int main(){
    int arr[] = {1,3,4,8,6,1,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    constructFenwickTree(arr,n);
}