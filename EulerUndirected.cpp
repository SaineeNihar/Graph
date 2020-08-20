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
void dfs(Graph g,int s,bool vis[])
{
    vis[s]=true;
    for(auto i=g.adj[s].begin();i!=g.adj[s].end();i++)
    {
        if(!vis[*i])
            dfs(g,*i,vis);
    }
}
bool checkConnected(Graph g)
{
    bool vis[g.V];
    memset(vis,false,g.V);
    int i=0;
    for(i=0;i<g.V;i++)
        if(g.adj[i].size()!=0)
            break;
    if(i==g.V)
        return true;
    dfs(g,i,vis);
    for(int i=0;i<g.V;i++)
        if(!vis[i] and g.adj[i].size()>0)
            return false;
    return true;
}
int checkEuler(Graph g)
{
    if(!checkConnected(g))
        return 0;
    int odd=0;
    for(int i=0;i<g.V;i++)
        if(g.adj[i].size()&1)
            odd++;
    if(odd>2)
        return 0;
    return(odd)?1:2;
}
int main(){  
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(2,6);
    g.addEdge(1,2);
    g.addEdge(5,4);
    g.addEdge(3,2);
    g.addEdge(0,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    int res=checkEuler(g);
    if(res==0)
        cout<<"Not a eular graph";
    else if(res==1)
        cout<<"Graph has eular path";
    else
        cout<<"Graph has eular Circuit";
    
    return 0;
}