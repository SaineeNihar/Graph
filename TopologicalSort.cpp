#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int V;
    list<int> *adj;
    queue<int> q;
    Graph(int v)
    {
        V=v;
        adj=new list<int>[V];
    }
    void addEdge(int u,int v);
    void printGraph();
    vector<int> indegree();
    void topsort();
};
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
vector<int> Graph::indegree()
{
    vector<int> v(V,0);
    for(int i=0;i<this->V;i++)
    {
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            v[*it]++;
        }
    }
    cout<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<"indegree of vertex"<<i<<" is: "<<v[i]<<endl;
          if(v[i]==0)
            q.push(i);
    }
    return v;
}
void Graph::topsort()
{
    vector<int> deg=indegree();
    vector<int> ts;
    int node;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        ts.push_back(node);
        for(auto it=adj[node].begin();it!=adj[node].end();it++)
        {
            deg[*it]--;
            if(deg[*it]==0)
                q.push(*it);
        }
    }
    cout<<"Topological sort of given graph is: ";
    for(auto i=ts.begin();i!=ts.end();i++)
        cout<<*i<<" ";
    cout<<endl;
}
int main()
{
    int v=8;
    Graph g(v);
    g.addEdge(0, 3); g.addEdge(0, 4);
    g.addEdge(1, 3); 
    g.addEdge(2, 4); g.addEdge(2, 7);
    g.addEdge(3, 5); g.addEdge(3, 6); g.addEdge(3, 7);
    g.addEdge(4, 6); 
    g.printGraph();
    g.topsort();
    return 0;
}