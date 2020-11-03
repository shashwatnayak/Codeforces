#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

// Graph Exercise 2.4.1.1-5
template <typename T>
class GraphAdjL{

private:
map<T,list<T> > g;
public:

void add_edge(int src,int dest,bool bd = true){
g[src].push_back(dest);
if(bd){g[dest].push_back(src);}
}

void print_graph(){

for(auto x:g){
    auto t = x.first;
    cout<<t<< "->";
    for(auto p:x.second){
        cout<< p << " ";
    }
    cout<<endl;
}
}
};

class GraphAdjM{
private:
vvi g;
//int vtx;
public:
GraphAdjM(int vtx){
    g.resize(vtx);
}
void add_edge(int src,int dest){
g[src].push_back(dest);
g[dest].push_back(src);
}

void print_graph(){

for(auto i : g){
    //cout << i << " ";
    for(auto j : i){
        cout<< j << " ";
    }
    cout<<endl;
}
}
};
int main(){
GraphAdjL<int> gAl;
gAl.add_edge(1,2);
gAl.add_edge(1,4);
gAl.add_edge(2,3);
gAl.add_edge(2,4);
gAl.add_edge(4,5);
gAl.add_edge(3,4);

gAl.print_graph();

//ZERO necessary, otherwise segfault

GraphAdjM gAm(6);
gAm.add_edge(0,1);
gAm.add_edge(1,2);
gAm.add_edge(1,4);
gAm.add_edge(2,3);
gAm.add_edge(2,4);
gAm.add_edge(4,5);
gAm.add_edge(3,4);
gAm.print_graph();
}