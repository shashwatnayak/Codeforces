#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;

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

int main(){
    int arr[] = {18,17,13,19,15,11,20};
    vi A(arr,arr+7);
    SegmentTree st(A);
    cout << (1<<4) <<" "<< (5<<1) << "\n";
    printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // answer = index 2
    printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // answer = index 5
}