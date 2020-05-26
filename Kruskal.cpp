#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define edge pair<int,int>
 
class Graph {
private:
    vector<pair<int, edge>> G; // graph
    vector<pair<int, edge>> T; // mst
    int *parent;
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};

Graph::Graph(int V) {
    parent = new int[V];
    
    // 初始自己為 parent
    for (int i = 0; i < V; i++)
        parent[i] = i;
 
    G.clear();
    T.clear();
}

// u->v  weight
void Graph::AddWeightedEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
    G.push_back(make_pair(w, edge(v, u)));
}

// 找 i 是屬於哪個 set 的
int Graph::find_set(int i) {
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}

void Graph::kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end()); // increasing weight 依權重排序
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        // 如果 u v 不屬於同個set 加入(u,v)至 T
        if (uRep != vRep) {
            T.push_back(G[i]); // add to tree
            union_set(uRep, vRep);
        }
    }
}

void Graph::print() {
    cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        cout <<"("<< T[i].second.first << "," << T[i].second.second << ") : "<< T[i].first;
        cout << endl;
    }
}

int main() {
    Graph g(6);
    g.AddWeightedEdge(0, 1, 4);g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(2, 3, 3);g.AddWeightedEdge(2, 5, 2);g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(5, 4, 3);

    g.kruskal();
    g.print();
    return 0;
}