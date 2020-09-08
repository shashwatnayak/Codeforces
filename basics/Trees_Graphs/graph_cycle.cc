#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<typename T>
class Graph{
  map<T,list<T> > g;
public:
  Graph(){}

  void add_edge(T src,T dest){
    g[src].push_back(dest);
    g[dest].push_back(src);
  }

  void dfshelp(T src,map<T,bool> &vb){
    vb[src] = true;
    cout<<src<< " ";

    for(auto curngbr : g[src]){
      if(!vb[curngbr]){
        dfshelp(curngbr,vb);
      }
    }
  }
  void dfs(T src){
    map<T,bool> vb;
    dfshelp(src,vb);
  }

  bool detect_cycle_help(T node, map<T,bool> &vs, T parent){

    vs[node] = true;

    for(T ngbr : g[node]){
      if(!vs[ngbr]){
      bool cycle = detect_cycle_help(ngbr,vs,node);
      if(cycle){
        return true;
      }
    }
    else if(ngbr !=parent){
      return true;
    }
  }
return false;
  }
  bool detect_cycle(T src){
    map<T,bool> vb;

    for(i : g){
      T node = i.first;
      if(!vs[node]){
        bool ans = detect_cycle_help(node,vb,node);
        if(ans==1){
          return true;
        }
      }
    }
    return false;
  };

  void print_graph(){
    for(T i : g){
      cout << i.first <<"->";
        for(T p : g.second){
          cout << p << " ";
        }
        cout<<endl;
    }
  }
};

int main(){
  Graph <int>g;
  g.add_edge(0,1);
  g.add_edge(1,2);
  g.add_edge(2,3);
  g.add_edge(3,4);
  g.add_edge(4,0);
  cout << detect_cycle(0);
}
