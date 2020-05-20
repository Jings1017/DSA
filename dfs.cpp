#include <iostream>
#include <vector>
using namespace std;

enum color
{
    WHITE,
    GRAY,
    BLACK
};

class Graph{
    int v;
    int e;
    int time;
    int *d;
    int *f;
    int *color;
    vector<int> *adj;
public:
    Graph(int v, int e);
    void addEdge(int v, int w);
    void DFS(int s);
    void DFS_visit(int u);
    void print();
};

Graph::Graph(int v, int e){
    this->v = v;
    this->e = e;
    color = new int[v];
    d = new int[v];
    f = new int[v];
    adj = new vector<int>[v];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    cout << v << ": ";
    for (int i = 0; i < adj[v].size();i++){
        cout << adj[v][i] << " ";
    }
    cout << endl;
}

void Graph:: DFS_visit(int u){
    color[u] = GRAY;
    time++;
    d[u] = time;
    cout << u << " ";
    for (int i = 0; i < adj[u].size();i++){
        if(color[adj[u][i]]==WHITE){
           
            DFS_visit(adj[u][i]);
        }
    }
    color[u] = BLACK;
    time++;
    f[u] = time;
}

void Graph::DFS(int s){
    for (int i = 0; i < 4;i++){
        color[i] = WHITE;
        d[i] = 0;
        f[i] = 0;
    }
    time = 0;
    for (int i = 0; i < 4;i++){
        if(color[i]==WHITE){
            DFS_visit(i);
        }
    }
}

void Graph::print(){
    cout << endl;
    for (int i = 0; i < 4;i++){
        cout << "d[" << i << "]= " << d[i] ;
        cout << " , f[" << i << "]= " << f[i] << endl;
    }
}

int main(){
    int s , e, v1, v2, start;
    cout << "input the number of vertex and edge in graph\n";
    cin >> s >>e;
    Graph g(s,e);
    cout << "input the edge\n";
    for (int i = 0; i < e;i++){
        cin >> v1 >> v2;
        g.addEdge(v1, v2);
    }
    cout << "input the sart vertex\n";
    cin >> start;
    g.DFS(start);
    g.print();
}