#include<bits/stdc++.h>
using namespace std;
enum Color{white,gray,black};
class Graph{
    public: 
    int V;
    list<int >*adj;
    Graph(int v)
    {
        V=v;
        adj=new list<int>[V];
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
    }
};
bool DFS(Graph g,int u,int color[])
{
    color[u]=gray;
    for(auto it=g.adj[u].begin();it!=g.adj[u].end();it++)
    {
        if(color[*it]==gray)
            return true;
        if(color[*it]==white and DFS(g,*it,color))
            return true;
    }
    color[u]=black;
    return false;
}
bool isCyclic(Graph g)
{
    int *color=new int[g.V];
    for(int i=0;i<g.V;i++)
        color[i]=white;
    for(int i=0;i<g.V;i++)
        if(color[i]==white and DFS(g,i,color))
            return true;
    return false;
}
int main()
{
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    if(isCyclic(g))
        cout<<"Graph contains cycle";
    else
        cout<<"Graph doesn't contain cycle";
    return 0;

}