#include<iostream>
using namespace std;

/***********************************
 * Fenwick Tree Theory
 A binary indexed tree or a Fenwick tree2 can be seen as a dynamic variant
of a prefix sum array. It supports two O(logn) time operations on an array:
processing a range sum query and updating a value.
The advantage of a binary indexed tree is that it allows us to efficiently update
array values between sum queries. This would not be possible using a prefix sum
array, because after each update, it would be necessary to build the whole prefix
sum array again in O(n) time.
Structure
Even if the name of the structure is a binary indexed tree, it is usually represented
as an array. In this section we assume that all arrays are one-indexed, because it
makes the implementation easier.
Let p(k) denote the largest power of two that divides k. We store a binary
indexed tree as an array tree such that
tree[k] = sumq(k - p(k) + 1,k) 

i.e., each position k contains the sum of values in a range of the original array
whose length is p(k) and that ends at position k. For example, since p(6) Æ 2,
tree[6] contains the value of sumq(5,6).

To calculate the value of sumq(a,b) where a È 1, we can use the same trick
that we used with prefix sum arrays:
sumq(a,b) = sumq(1,b) - sumq(1,a-1).

The operations of a binary indexed tree can be efficiently implemented using bit
operations. The key fact needed is that we can calculate any value of p(k) using
the formula
p(k) =  k&-k.
 
* *********************************/
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