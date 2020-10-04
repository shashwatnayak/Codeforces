#include<iostream>
using namespace std;

#define N 10000
int n, t[1<<N];
/***************************************
Segment Tree is used in cases where there are multiple range queries on array and modifications of elements of the same array. 
For example, finding the sum of all the elements in an array from indices  to , or finding the minimum
(famously known as Range Minumum Query problem) of all the elements in an array from indices  to. 
These problems can be easily solved with one of the most versatile data structures, Segment Tree.

What is Segment Tree ?
Segment Tree is a basically a binary tree used for storing the intervals or segments. 
Each node in the Segment Tree represents an interval. Consider an array  of size  and a corresponding Segment Tree :

The root of  will represent the whole array .
Each leaf in the Segment Tree  will represent a single element  such that .
The internal nodes in the Segment Tree  represents the union of elementary intervals  where .
The root of the Segment Tree represents the whole array . Then it is broken down into two half intervals
or segments and the two children of the root in turn represent the  and . So in each step, the segment 
is divided into half and the two children represent those two halves. So the height of the segment tree will be . 
There are leaves representing the elements of the array. The number of internal nodes is. So, a total number of nodes are .

Once the Segment Tree is built, its structure cannot be changed. 
We can update the values of nodes but we cannot change its structure. 


Segment tree provides two operations:
Update: To update the element of the array  and reflect the corresponding change in the Segment tree.
Query: In this operation we can query on an interval or segment and return the answer to the problem 
(say minimum/maximum/summation in the particular segment).

Implementation:
Since a Segment Tree is a binary tree, a simple linear array can be used to represent the Segment Tree. 
Before building the Segment Tree, one must figure what needs to be stored in the Segment Tree's node?.
For example, if the question is to find the sum of all the elements in an array from indices  to , 
then at each node (except leaf nodes) the sum of its children nodes is stored.

A Segment Tree can be built using recursion (bottom-up approach ). Start with the leaves and go 
up to the root and update the corresponding changes in the nodes that are in the path from leaves to root. 
Leaves represent a single element. In each step, the data of two children nodes are used to form an internal parent node.
Each internal node will represent a union of its children’s intervals. Merging may be different for different questions. 
So, recursion will end up at the root node which will represent the whole array.

For , search the leaf that contains the element to update. This can be done by going to either on the 
left child or the right child depending on the interval which contains the element. Once the leaf is found, 
it is updated and again use the bottom-up approach to update the corresponding change in the path from that leaf to the root.

To make a  on the Segment Tree, select a range from  to  (which is usually given in the question). 
Recurse on the tree starting from the root and check if the interval represented by the node is completely in the range from to .
If the interval represented by a node is completely in the range from  to , return that node’s value.

 ***************************************/
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