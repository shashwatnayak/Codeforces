#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;
// Only Recurisve Way
// Range Minimum Query
class SegmentTree{
private:
vi st,A;
int n;
void build(int p,int l,int r){
if(l==r){
    st[p] = l;
}else{
// from top-down tree build
int m = (l+r)/2;
build(p<<1,l,m);  
build((p<<1) + 1,m+1,r);
int p1 = st[(p<<1)];
int p2 = st[(p<<1)+1];
st[p] = (A[p1] <= A[p2]) ? p1 : p2;
}
}

int rmq(int p,int l ,int r,int i,int j){
if(i>r || j<l)return -1; // outside query range
if(l>=i && r<=j)return st[p]; // inside query range check
int m = (l+r)/2;
int leftrmq = rmq(p<<1,l,m,i,j) ;  // get left min idx
int rightrmq = rmq((p<<1)+1,m+1,r,i,j) ; // get right min idx
if(leftrmq==-1)return rightrmq; // accidental outside check left query
if(rightrmq==-1)return leftrmq; // accidental outside check right query
return (A[leftrmq] <= A[rightrmq]) ? leftrmq : rightrmq; // return least of left and right query
}
public:
SegmentTree(const vi &_A){
A = _A;
n = (int)A.size();
st.assign(4*n,0);
build(1,0,n-1);
}
int rmq(int i,int j){
    return rmq(1,0,n-1,i,j);
}
};

//Range Sum Query
class SegmentTreeRSQ{
private:
vi st,A;
int n;
void build(int p,int l,int r){
if(l==r){
    st[p] = A[l];
}else{
// from top-down tree build
int m = (l+r)/2;
build(2*p,l,m);  
build((2*p) + 1,m+1,r);
st[p] = st[2*p] + st[(2*p)+1];
}
}

int rsq(int p,int l ,int r,int i,int j){
if(i>r || j<l)return 0; // outside query range
if(l>=i && r<=j)return st[p]; // inside query range check
int m = (l+r)/2;
int left = rsq(2*p,l,m,i,j) ;  //
int right = rsq((2*p) + 1,m+1,r,i,j) ; // 
return (left + right); // 
}

void update(int p,int l,int r,int pos,int val){
if(l == r){
    st[p] = val;
}else{
    int m = (l+r)/2;
    if(pos<=m){
        update(2*p,l,m,pos,val);
    }else{
        update(2*p + 1,m+1,r,pos,val);    
    }
    st[p] = st[2*p] + st[2*p +1];
}
}
public:
SegmentTreeRSQ(const vi &_A){
A = _A;
n = (int)A.size();
st.assign(4*n,0);
build(1,0,n-1);
}
void print(){
    for(auto x : st){
        cout<<x << " ";
    }
    cout<<endl;
}
int rsq(int i,int j){
    return rsq(1,0,n-1,i,j);
}
void rsq(int pos,int val){
update(1,0,n-1,pos,val);
}
};
int main(){
    //int arr[] = {18,17,13,19,15,11,20};
    //vi A(arr,arr+7);
    // SegmentTree st(A);
    // //cout << (1<<4) <<" "<< (5<<1) << "\n";
    // printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // answer = index 1 
    // printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // answer = index 6    
    // printf("RMQ(1, 7) = %d\n", st.rmq(1, 7)); // answer = index 6
    // printf("RMQ(3, 8) = %d\n", st.rmq(3, 8)); // answer = index 6

    int arr[] = {10,2,47,3,7,9,1,98,21};
    vi A(arr,arr+9);
    SegmentTreeRSQ st(A);
    st.print();
     printf("RMS(1, 3) = %d\n", st.rsq(1, 3)); // answer =  52
     printf("RMS(4, 6) = %d\n", st.rsq(4, 6)); // answer =  17
     printf("RMS(1, 7) = %d\n", st.rsq(1, 7)); // answer =  167
     printf("RMS(3, 8) = %d\n", st.rsq(3, 8)); // answer =  139
}

/*
1. A = {10,2,47,3,7,9,1,98,21} rmq (1,7) and rmq(3,8) - Done
2. range sum queries - Done 
3.  rsq(1,7) & rsq (3,8) - Done
4. point update function - array update update(idx,val) - Done
5. point update function - delete and insert. what will happen ? - Not Recommended
6. Range update operation. Given subarray and (i,j). Update the Segment tree - Call Update sizeof(subarr) times;
//      int subar = {};
        int sub_i = i;
        int sub_j = j;
        for(int i = 0;i<n;i++){
            int val = subar[i];
            int pos = sub_i;
            st.update(pos,val);
            pos++;
        }

7. Lazy Propagation
8. Iterative Segment Tree (using bits)
*/