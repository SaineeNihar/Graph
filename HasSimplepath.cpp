#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int V,E;
    list<int> *adj;
    Graph(int v)
    {
        V=v;
        adj=new list<int>[V];
    }   
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
bool dfs(Graph g,int s, int d,bool vis[])
{
    if(s==d)
        return true;
    vis[s]=true;
    for(auto i=g.adj[s].begin();i!=g.adj[s].end();i++)
    {
        if(!vis[*i] and dfs(g,*i,d,vis))
            return true;
    }
    return 0;
}
void findPath(Graph g,int s,int d)
{
    bool vis[g.V];
    memset(vis,false,g.V);
    if(dfs(g,s,d,vis))
        cout<<"Simple path exists\n";
    else
        cout<<"Simple path doesn't exists\n";
}

int main(){
    Graph g(7);
    g.addEdge(0,1); g.addEdge(2,6);
    g.addEdge(1,2); g.addEdge(5,4);
    g.addEdge(3,2); g.addEdge(0,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    findPath(g,5,6);
}