//Single Source Shortest Path (Equal Weights)

#include<iostream>
#include<map>
#include<queue>
#include<list>

using namespace std;

template<typename T>
class Graph{
  map<T,list<T> > adjlist;

public:
  Graph(){}

  void add_edge(T src,T dest){
    adjlist[src].push_back(dest);
    adjlist[dest].push_back(src);
  }

  void print_graph(){

    for(T i : adjlist){
      cout<< i.first << " ";
      for(T x : i.second){
        cout<< x ;
      }
      cout<<endl;
    }
    void SSSP(T src){
      queue<T>q;
      map<T,int> dist;
      map<T,T> parent;

      for(T i : adjlist){
        dist[i.first] = 1e9;
      }
      q.push(src);
      dist[src] = 0;
      parent[src] = src;

      while(!q.empty()){
        T node = q.front();
        q.pop();
        cout << node << " ";

        for(T ngbr : adjlist[node]){
          if(dist[ngbr] == 1e9){
            q.push(ngbr);
            dist[ngbr] = dist[node] + 1;
            parent[ngbr] = node;
          }
        }
      }

      for(T x : adjlist){
        T node = i.first;
        cout<< "Dist of " << node "from " << src << dist[node]<<endl;
      }
    }
};

int main(){
  Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	g.SSSP(0);
}
