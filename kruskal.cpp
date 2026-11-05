#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define edge pair<int,int>
class Graph {
private:
    vector<pair<int, edge>> G; // граф (список ребер)
    vector<pair<int, edge>> T; // МКД
    int *parent;               // DSU
    int V;                     // кількість вершин
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int V) {
    this->V = V;
    parent = new int[V + 1];
    for (int i = 0; i <= V; i++)  // кожна вершина - окрема множина
        parent[i] = i;
    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
    if (i == parent[i])
        return i;
    return find_set(parent[i]);
}
void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}
void Graph::kruskal() {
    int uRep, vRep;
    sort(G.begin(), G.end()); // сортування за неспаданням ваги
    for (size_t i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {           // ребро не утворює цикл
            T.push_back(G[i]);        // додати до МКД
            union_set(uRep, vRep);
        }
        if ((int)T.size() == V - 1) break;
    }
}
void Graph::print() {
    int total = 0;
    cout << "Edge : Weight" << endl;
    for (size_t i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " - " << T[i].second.second << " :  "
             << T[i].first << endl;
        total += T[i].first;
    }
    cout << "Total weight: " << total << endl;
}
int main() {
    Graph g(8);   // варіант 22: вершини 1..8
    g.AddWeightedEdge(1, 3, 1);
    g.AddWeightedEdge(1, 2, 4);
    g.AddWeightedEdge(1, 4, 6);
    g.AddWeightedEdge(2, 4, 8);
    g.AddWeightedEdge(2, 6, 3);
    g.AddWeightedEdge(3, 8, 2);
    g.AddWeightedEdge(4, 5, 3);
    g.AddWeightedEdge(5, 6, 9);
    g.AddWeightedEdge(5, 7, 5);
    g.AddWeightedEdge(6, 7, 7);
    g.AddWeightedEdge(6, 8, 1);
    g.AddWeightedEdge(7, 8, 7);
    g.kruskal();
    g.print();
    return 0;
}
