#include<bits/stdc++.h>
using namespace std;
class Edge      
{
    public:
    int src,dest,weight;
};
class Graph
{
    public:
    int V,E;
    Edge *e;
    Graph(int v,int ex)
    {
        V=v;
        E=ex;
        e=new Edge[E];;
    }
    void printGraph();
};
void Graph::printGraph()
{
    for(int i=0;i<V;i++)
    {
    }
}
void bellmanford(Graph g,int src)
{
    int dis[g.V];
    memset(dis,INT_MAX,g.V);
    dis[src]=0;
    int path[g.V];
    path[src]=-1;
    for(int i=1;i<=g.V-1;i++)
    {
        for(int j=0;j<g.E;j++)
        {
            int u=g.e[j].src;
            int v=g.e[j].dest;
            int weight=g.e[j].weight;
            if(dis[u]!=INT_MAX and dis[u]+weight<dis[v])
            {
                dis[v]=dis[u]+weight;
                path[v]=u;
            }
        }
    }
    for(int i=0;i<g.E;i++)
    {
            int u=g.e[i].src;
            int v=g.e[i].dest;
            int weight=g.e[i].weight;
            if(dis[u]!=INT_MAX and dis[u]+weight<dis[v])
            {
                cout<<"Negative cycle in the graph\n";
                return;
            }
    }
    cout<<"distance from "<<src<<"\n";
    for(int i=0;i<g.V;i++)
    {   
        cout<<"to "<<i<<"th node is: "<<dis[i]<<endl;
    }



}
int main()
{
    int v=5;
    int e=8;
    Graph graph(v,e);
    graph.e[0].src = 0; 
    graph.e[0].dest = 1; 
    graph.e[0].weight = -1; 

    graph.e[1].src = 0; 
    graph.e[1].dest = 2; 
    graph.e[1].weight = 4; 
  
    // add e 1-2 (or B-C in above figure) 
    graph.e[2].src = 1; 
    graph.e[2].dest = 2; 
    graph.e[2].weight = 3; 
  
    // add e 1-3 (or B-D in above figure) 
    graph.e[3].src = 1; 
    graph.e[3].dest = 3; 
    graph.e[3].weight = 2; 
  
    // add e 1-4 (or A-E in above figure) 
    graph.e[4].src= 1; 
    graph.e[4].dest = 4; 
    graph.e[4].weight=2; 
  
    // add e 3-2 (or D-C in above figure) 
    graph.e[5].src = 3; 
    graph.e[5].dest = 2; 
    graph.e[5].weight = 5; 
  
    // add e 3-1 (or D-B in above figure) 
    graph.e[6].src = 3; 
    graph.e[6].dest = 1; 
    graph.e[6].weight = 1; 
  
    // add e 4-3 (or E-D in above figure) 
    graph.e[7].src = 4; 
    graph.e[7].dest = 3; 
    graph.e[7].weight =-3; 
  
    bellmanford(graph, 0); 
    //g.printGraph();
    return 0;
}