#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<list>
using namespace std;

template <typename T>
class Graph{
private:
map<T,list<T> > adjlist;
public:
Graph(){

}

void add_edge(T src, T dest, bool bd = true){
adjlist[src].push_back(dest);
if(bd)adjlist[dest].push_back(src);
}
void printgraph(){
for(auto i : adjlist){
    cout << i.first << "->";
    for(auto p : i.second){
        cout<< p << " ";
    }
    cout<<"\n";
}
}
void dfs_help(T src,map<T,bool> &vis){
cout<< src << " ";
vis[src] = true;

for(auto x : adjlist[src]){
    if(!vis[x]){
        dfs_help(x,vis);
    }
}
}
void dfs(T src){
map<T,bool> vis;
dfs_help(src,vis);
}

void bfs(T src){
queue<T> q;
map<T,bool> vis;
q.push(src);
vis[src] = true;

while(!q.empty()){
    T p = q.front();
    cout<< p << " ";
    q.pop();

    for(auto x : adjlist[p]){
        if(!vis[x]){
            q.push(x);
            vis[x] = true;
        }
    }
}
}
};

int main(){
  Graph<int> g;
  g.add_edge(0,1);
  g.add_edge(1,2);
  g.add_edge(2,4);
  g.add_edge(3,4);
  g.add_edge(0,3);
  g.add_edge(0,4);

  g.printgraph();

  g.bfs(0);
  cout<<endl;
  g.dfs(0);;
}