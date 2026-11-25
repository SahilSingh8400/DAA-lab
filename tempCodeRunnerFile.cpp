#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v, w;
};
bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}
int findParent(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent, parent[x]);
}
void unionSet(vector<int> &parent, vector<int> &rnk, int a, int b)
{
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (rnk[a] < rnk[b])
        swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b])
        rnk[a]++;
}
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(V), rnk(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int totalCost = 0;
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < E; i++)
    {
        int a = findParent(parent, edges[i].u);
        int b = findParent(parent, edges[i].v);
        if (a != b)
        {
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            totalCost += edges[i].w;
            unionSet(parent, rnk, a, b);
        }
    }
    cout << "Minimum cost of spanning tree: " << totalCost << endl;
    cout << "This program is executed by Sahil Singh (Roll No: 2400320100951)" << endl;
    return 0;
}