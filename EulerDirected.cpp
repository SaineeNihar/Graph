#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int V,E;
    list<int> *adj;
    int *in;
    Graph(int v)
    {
        V=v;
        adj=new list<int>[V];
        in=new int[V];
    }   
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        in[v]++;
    }
};
Graph getTranspose(Graph g)
{
    Graph gt(g.V);
    for(int i=0;i<g.V;i++)
    {
        for(auto it=g.adj[i].begin();it!=g.adj[i].end();it++)
        {
            gt.addEdge(*it,i);
        }
    }
    return gt;
}
void dfs(Graph g,int s,bool vis[])
{
    vis[s]=true;
    for(auto i=g.adj[s].begin();i!=g.adj[s].end();i++)
    {
        if(!vis[*i])
            dfs(g,*i,vis);
    }
}
bool checkStronglyConnected(Graph g)
{
    bool vis[g.V];
    memset(vis,false,g.V);
    int i=0;
    for(i=0;i<g.V;i++)
        if(g.adj[i].size()!=0)
            break;
    if(i==g.V)
        return true;
    int source = i;
    dfs(g,source,vis);
    for(i=0; i<g.V; i++)
        if(!vis[i] and g.adj[i].size()>0)
            return false;
    Graph gt = getTranspose(g);
    memset(vis,false,g.V);
    dfs(gt,source,vis);
    for(i=0; i<gt.V; i++)
        if(!vis[i] and gt.adj[i].size()>0)
            return false;
    return true;
}
int checkEuler(Graph g)
{
    if(!checkStronglyConnected(g))
        return 0;
    for(int i=0;i<g.V;i++)
        if(g.adj[i].size()!=g.in[i])
            return 0;
    return 1;
}
int main(){  
    Graph g(5); 
    g.addEdge(1, 0); 
    //g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 0);
    if(checkEuler(g))
        cout<<"A eular graph";
    else
        cout<<"Not a eular graph";
    return 0;
}