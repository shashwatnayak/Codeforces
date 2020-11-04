#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;

class UnionFind{
private:
vi p,rank;
public:
UnionFind(int n){
    rank.assign(n,0);
    p.assign(n,0);
    for(int i = 0;i<n;i++){
        p[i] = i;
    }
}
int findSet(int i){
return (p[i]==i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i,int j){
return (findSet(i)==findSet(j));
}
void UnionSet(int i,int j){
if(!isSameSet(i,j)){
int x = findSet(i);
int y = findSet(j);
if(rank[x]>rank[y]){
    p[y] = x;
}else{
    p[x] = y;
    if(rank[x]==rank[y])rank[y]++;
}
}}};

int main(){
    UnionFind uf(4);
    uf.UnionSet(0,1);
    uf.UnionSet(2,3);
    uf.UnionSet(4,3);
    cout << uf.isSameSet(0,4);
    uf.UnionSet(0,3);
    cout<<uf.isSameSet(0,4);
}
/*
To do this efficiently, we store the index of the parent item and (the upper bound of)
the height of the tree of each set (vi p and vi rank in our implementation). Remember
that vi is our shortcut for a vector of integers. p[i] stores the immediate parent of item i.
If item i is the representative item of a certain disjoint set, then p[i] = i, i.e. a self-loop.
rank[i] yields (the upper bound of) the height of the tree rooted at item i.
In this section, we will use 5 disjoint sets {0, 1, 2, 3, 4} to illustrate the usage of this
data structure. We initialize the data structure such that each item is a disjoint set by itself
with rank 0 and the parent of each item is initially set to itself.
To unite two disjoint sets, we set the representative item (root) of one disjoint set to be
the new parent of the representative item of the other disjoint set. This effectively merges
the two trees in the Union-Find Disjoint Set representation. As such, unionSet(i, j) will
cause both items ‘i’ and ‘j’ to have the same representative item—directly or indirectly. For
efficiency, we can use the information contained in vi rank to set the representative item
of the disjoint set with higher rank to be the new parent of the disjoint set with lower rank,
thereby minimizing the rank of the resulting tree. If both ranks are the same, we arbitrarily
choose one of them as the new parent and increase the resultant root’s rank. This is the
‘union by rank’ heuristic. In Figure 2.6, top, unionSet(0, 1) sets p[0] to 1 and rank[1]
to 1. In Figure 2.6, middle, unionSet(2, 3) sets p[2] to 3 and rank[3] to 1.
For now, let’s assume that function findSet(i) simply calls findSet(p[i]) recursively
to find the representative item of a set, returning findSet(p[i]) whenever p[i] != i and i
otherwise. In Figure 2.6, bottom, when we call unionSet(4, 3), we have rank[findSet(4)]
= rank[4] = 0 which is smaller than rank[findSet(3)] = rank[3] = 1, so we set p[4]
= 3 without changing the height of the resulting tree—this is the ‘union by rank’ heuristic 
at work. With the heuristic, the path taken from any node to the representative item by
following the chain of ‘parent’ links is effectively minimized.

In Figure 2.6, bottom, isSameSet(0, 4) demonstrates another operation for this data
structure. This function isSameSet(i, j) simply calls findSet(i) and findSet(j) and
checks if both refer to the same representative item. If they do, then ‘i’ and ‘j’ both belong
to the same set. Here, we see that findSet(0) = findSet(p[0]) = findSet(1) = 1 is
not the same as findSet(4)= findSet(p[4]) = findSet(3) = 3. Therefore item 0 and
item 4 belongs to different disjoint sets.


There is a technique that can vastly speed up the findSet(i) function: Path compression.
Whenever we find the representative (root) item of a disjoint set by following the chain of
‘parent’ links from a given item, we can set the parent of all items traversed to point directly
to the root. Any subsequent calls to findSet(i) on the affected items will then result in
only one link being traversed. This changes the structure of the tree (to make findSet(i)
more efficient) but yet preserves the actual constitution of the disjoint set. Since this will
occur any time findSet(i) is called, the combined effect is to render the runtime of the
findSet(i) operation to run in an extremely efficient amortized O(M × α(n)) time.
In Figure 2.7, we demonstrate this ‘path compression’. First, we call unionSet(0, 3).
This time, we set p[1] = 3 and update rank[3] = 2. Now notice that p[0] is unchanged,
i.e. p[0] = 1. This is an indirect reference to the (true) representative item of the set, i.e.
p[0] = 1 → p[1] = 3. Function findSet(i) will actually require more than one step to
traverse the chain of ‘parent’ links to the root. However, once it finds the representative
item, (e.g. ‘x’) for that set, it will compress the path by setting p[i] = x, i.e. findSet(0)
sets p[0] = 3. Therefore, subsequent calls of findSet(i) will be just O(1). This simple
strategy is aptly named the ‘path compression’ heuristic. Note that rank[3] = 2 now no
longer reflects the true height of the tree. This is why rank only reflects the upper bound of
the actual height of the tree.
*/