#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<queue>

using namespace std;

//Adjacency list
//dfs and bfs traversal
template<typename T>
class Graph{
    map<T,list<T> > adjlist;
    public:
    Graph(){}

    void add_edge(T src, T dest){
        adjlist[src].push_back(dest);
        adjlist[dest].push_back(src);
    }

    void print_graph(){

        for(auto i : adjlist){
            cout << i.first<<"->";
                for(T p : i.second){
                    cout<<p<<" ";
                }
                cout<<endl;
        }
    }

    void dfs_util(T src, map<T,bool> &visited){
        visited[src] = true;
        cout<< src << " ";
        
        for(T x : adjlist[src]){
            if(!visited[x]){
                dfs_util(x,visited);
            }
        }
    }
    void dfs(T src){
        map<T,bool> visited;
        dfs_util(src,visited);
    }

    void bfs(T src){
        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            cout<<node << " ";
            q.pop();

            for(T neighbour : adjlist[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

//Adjacency Matrix
//dfs and bfs traversal
class _Graph{
vector<vector<int> > adjmatrix;
public:
_Graph(int s){
    adjmatrix.resize(s);
}
void add_edge(int src, int dest){
    adjmatrix[src].push_back(dest);
    adjmatrix[dest].push_back(src);
}
void print_graph(){
    for(int i = 0;i<adjmatrix.size();i++){
        cout<<i << "->";
            for(int j = 0;j<adjmatrix[i].size();j++){
                cout << adjmatrix[i][j]<< " ";
            }
            cout<<endl;
    }
}

void dfs_util(int src,vector<bool> &vb){
    vb[src] = true;
    cout<<src << " ";

    for(int x : adjmatrix[src]){
        if(!vb[x]){
            dfs_util(x,vb);
        }
    }
}
void dfs(int src){
    vector<bool> vb(adjmatrix.size());
    dfs_util(src,vb);
}

void bfs(int src){
    queue<int> q;
    vector<bool> vs(adjmatrix.size());

    q.push(src);
    vs[src] = true;

    while(!q.empty()){
    int i = q.front();
    q.pop();
    cout<< i << " ";
        //cout<< "here";
        for(auto x : adjmatrix[i]){
            if(!vs[x]){
            q.push(x);
            vs[x] = true;
            }
        }
    }
}

};
void test1(){
Graph <int> g1;
g1.add_edge(0,1);
g1.add_edge(0,2);
g1.add_edge(2,3);
g1.add_edge(1,2);
g1.add_edge(1,4);
g1.add_edge(3,4);

g1.print_graph();
cout<<"\n";
g1.dfs(0);
cout<<"\n";
g1.bfs(0);

}
void test2(){
_Graph g1(5);
g1.add_edge(0,1);
g1.add_edge(0,2);
g1.add_edge(2,3);
g1.add_edge(1,2);
g1.add_edge(1,4);
g1.add_edge(3,4);


g1.print_graph();
cout<<"\n";
g1.dfs(0);
cout<<"\n";
g1.bfs(0);
}
int main(){
    test1();
    cout<<endl;
    test2();
}