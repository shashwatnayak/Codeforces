#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<queue>
using namespace std;


//Adjacency list
template<typename T>
class Graph{
map<T,list<T> >adjList;
public:
  Graph(){}

  void add_edge(T src,T dest, bool bd = true){
    adjList[src].push_back(dest);
    if(bd){adjList[dest].push_back(src);
    }
  }

  void graph_print(){
    for(auto i:adjList){
      cout<<i.first<<"->";
      for(T entry : i.second){
          cout<<entry << " ";
      }
      cout<<endl;
    }
  }

  void bfs(T src){
    queue<T> q;
    map<T,bool> visited;

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
      T node = q.front();
      q.pop();
      cout<< node << " ";

      for(T ngbr : adjList[node]){
        if(!visited[ngbr]){
          q.push(ngbr);
          visited[ngbr] = true;
        }
      }
    }
  }

  void dfshelper(T src, map<T,bool> &vis){
    vis[src] = true;
    cout<<src<< " ";

    for(T ngbr: adjList[src]){
      if(!vis[ngbr]){
        dfshelper(ngbr,vis);
      }
    }
  }
  void dfs(T src){
    map<T,bool> vis;
    dfshelper(src,vis);
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

  g.graph_print();

  g.bfs(0);
  cout<<endl;
  g.dfs(0);
}
