#include<iostream>
#include<vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;


//Adjacency Matrix
class Graph{
  vvi g;
public:
  Graph(int s){
    g.resize(s);
  }
  void add_edge(int src, int dest){
    g[src].push_back(dest);
    g[dest].push_back(src);
  }
  void graph_print(){
    for(int i = 0;i<g.size();i++){
      cout << i << "\t";
        for(int j = 0;j<g[i].size();j++){
            cout<<g[i][j] << " ";
        }
        cout<<endl;
    }
  }
  void dfshelper(int src,vector<bool> &vis){
    cout<< src << " ";
    vis[src] = true;
    vector<int> &ngbrlist = g[src];

    for(int i = 0;i<ngbrlist.size();i++){
      int curngbr = ngbrlist[i];
      if(!vis[curngbr]){
        dfshelper(curngbr,vis);
      }
    }
  }
  void dfs(int src){
    vector<bool> visited (g.size(),false);
    dfshelper(src,visited);
  }
};

int main(){
  Graph g(4);
  //g.add_edge(0,1);
  //g.add_edge(1,2);
  //g.add_edge(2,4);
  //g.add_edge(3,4);
  //g.add_edge(2,4);
  //g.add_edge(3,4);

  g.graph_print();
}
