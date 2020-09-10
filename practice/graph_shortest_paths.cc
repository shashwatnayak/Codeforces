#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<utility>

using namespace std;
//Weighted Graph
/*
template<typename T>
class Graph{
    map<T,list<pair<T,T> > > w_adjlist;
    public:
    Graph(){}

    void add_edge(T src, T dest, T weight){
        w_adjlist[src].push_back(make_pair(dest,weight));
        w_adjlist[dest].push_back(make_pair(src,weight));
    }

    void print_graph(){
        for(auto i : w_adjlist){
            cout << i.first<<"->";
            pair<T,T > :: iterator p;
               // for(auto p : i.second){
                  //  cout<<p.first<<"-"<<p.second<<" " ;
                //}
                for(p = ;p<i.second;p++){
                    cout<< *(p.first) << "-" << *(p.second) << " ";
                }
                cout<<endl;
        }
    }

  
}; */

template<typename T>
class _Graph{

    map<T,list<T> > adjlist;
   
   public:
    _Graph(){}

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
    void distance_between_nodes(T src){
        queue<T> q;
        map<T,int> distance;
        map<T,T> parent;
        for(auto i : adjlist){
            distance[i] = INT_MAX;
        }

        q.push(src);
        distance[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node << " ";

            for(int ngbr : adjlist[node]){
                if(distance[ngbr] == INT_MAX){
                    q.push(ngbr);
                    distance[ngbr] = distance[src] + 1;
                    parent[ngbr] = src;
                }
            }
        }
        
        for(auto i : adjlist){
            T node = i.first;
            cout << "Dist"
        }
    }
};


//void test1(){
  //      Graph <int> g1;
    //    g1.add_edge(0,1,1);
      //  g1.add_edge(0,2,1);
        //g1.add_edge(2,3,1);
        //g1.add_edge(1,2,1);
        //g1.add_edge(1,4,1);
        //g1.add_edge(3,4,1);

        //g1.print_graph();
    //}

void test2(){
    _Graph <int> g1;
    g1.add_edge(0,1);
    g1.add_edge(0,2);
    g1.add_edge(2,3);
    g1.add_edge(1,2);
    g1.add_edge(1,4);
    g1.add_edge(3,4);

    g1.print_graph();
//cout<<"\n";
//g1.dfs(0);
//cout<<"\n";
//g1.bfs(0);
}
int main(){
    // test1();
    test2();
}