#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s){
    bool *visited = new bool[V];
    for (int i = 0; i < V;i++){
        visited[i] = false;
    }
    list<int> queue;

    // start vertex
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end();i++){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main(){
    int n,edge_num,v1,v2,s;
    cout << "input the number of vertex and edge\n";
    cin >> n >> edge_num;
    Graph g(n);
    cout << "input the edges\n";
    for (int i = 0; i < edge_num;i++){
        cin >> v1 >> v2;
        g.addEdge(v1, v2);
    }
    cout << "which vertex is the starting vertex\n";
    cin >> s;
    cout << "the search result : \n";
    g.BFS(s);
    return 0;
}