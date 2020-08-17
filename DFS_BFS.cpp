#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int V;
    list<int> *adj;
    Graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
    void BFS();
    void BFSUtil(int v, bool vis[]);
    void DFS();
    void DFSUtil(int v,bool vis[]);
    void addEdge(int u,int v);
    void printGraph();
};
void Graph::DFSUtil(int v, bool vis[])
{
    vis[v] = true;
    cout << v << " ";
    for (auto it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (vis[*it] == false)
            DFSUtil(*it, vis);
    }
}
void Graph::DFS()
{
    bool* vis=new bool[V];
    memset(vis, false, V);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == false)
            DFSUtil(i, vis);
    }
}
void Graph::BFS() {
    bool* vis = new bool[V];
    memset(vis, false, V);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            BFSUtil(i, vis);
    }
    cout<< "\n";
}
void Graph::BFSUtil(int v,bool vis[])
{
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while (!q.empty())
    {
        int s = q.front(); q.pop();
        cout << s << " ";
        for (auto i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!vis[*i])
            {
                vis[*i] = true;
                q.push(*i);
            }
        }
    }
}
void Graph::printGraph()
{
    for(int i=0;i<V;i++)
    {
        cout<<i<<" -> ";
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }
}
void Graph::addEdge(int u,int v){
    if (u >= V or v >= V)
    {
        cout << "Vertex doesn't exits, can not add edge"<<u<<" -> "<<v<<"\n";
        return;
    }
    adj[u].push_back(v);
}
int main()
{
    int v=4;
    Graph g(v);
    g.addEdge(0, 1); g.addEdge(0, 2);
    g.addEdge(2, 1); g.addEdge(2, 3); g.addEdge(2, 4);
    g.addEdge(3, 1); g.addEdge(7, 4);
    g.printGraph();
    g.DFS();
    cout << endl;
    g.BFS();
}