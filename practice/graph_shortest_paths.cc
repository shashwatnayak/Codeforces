#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<utility>

using namespace std;
//Weighted Graph

template<typename T>
class Graph{
    map<T,list<pair<T,T> > > w_adjlist;
    public:
    Graph(){}

    void add_edge(T src, T dest, T weight){
        w_adjlist[src].push_back(make_pair(dest,weight));
        w_adjlist[dest].push_back(make_pair(src,weight));
    }

    void print_graph_with_weights(){
        for(auto i : w_adjlist){
            cout << i.first<<"->";
            
               for(auto p : i.second){
                  cout<<p.first<<"-"<<p.second<<" " ;
                }
                // auto couldnt be identified
                // pair<T,T > :: iterator p;
                // for(p = ;p<i.second;p++){
                //     cout<< *(p.first) << "-" << *(p.second) << " ";
                // }
                cout<<endl;
        }
    
    int djikstra(T src, T dest){
        const int inf = 1e9;
        map<T,int> dist;
        priority_queue<,,greater>
        for(auto i : w_adjlist){
            dist[i.first] = inf;
        }

    }
    }

  
};

// To do
// BELLMAN FORD
// DJIKSTRA ALGORITHM
// FLOYD WARSHALL 
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
            distance[i.first] = 1e9;
        }

        q.push(src);
        distance[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node << " ";

            for(int ngbr : adjlist[node]){
                if(distance[ngbr] == 1e9){
                    q.push(ngbr);
                    distance[ngbr] = distance[node] + 1;
                    parent[ngbr] = node;
                }
            }
        }
        
        for(auto i : adjlist){
            T node = i.first;
            cout << "Dist of node " << node << " from source " << src <<" is "<< distance[node]<<endl;
        }
    }
};


void test1(){
       Graph <int> g1;
       g1.add_edge(0,1,2);
       g1.add_edge(0,2,4);
        g1.add_edge(2,3,3);
        g1.add_edge(1,2,5);
        g1.add_edge(1,4,1);
        g1.add_edge(3,4,9);

        g1.print_graph_with_weights();
    }

void test2(){
    _Graph <int> g1;
    g1.add_edge(0,1);
    g1.add_edge(0,2);
    g1.add_edge(2,3);
    g1.add_edge(1,2);
    g1.add_edge(1,4);
    g1.add_edge(3,4);

    g1.print_graph();

    cout<<"\n";
    g1.distance_between_nodes(0);

}
int main(){
    test1();
    cout<<"\n";
    test2();
}