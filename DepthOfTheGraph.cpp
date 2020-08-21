#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
	int V;
	list<int> *adj;
	int *in;
	Graph(int v)
	{
		V = v; 
		adj = new list<int>[V]; in = new int[V];
	}
	void addEdge(int u, int v);
	int depthOfGraph();
};
int Graph::depthOfGraph()
{	
	queue<int> q;
	int count = 0;
	q.push(-1);
	for (int i = 0; i < V; i++)
		if (in[i] == 0)
			q.push(i);
	cout << "qsize  ";
	cout << q.size() << endl;
	//q.push(-1);
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		if (v == -1)
		{
			count++;
			if (!q.empty())
				q.push(-1);
		}
		else 
		{
			for (auto it = adj[v].begin(); it != adj[v].end(); it++)
				if (--in[*it] == 0)
					q.push(*it);
		}
	}
	return count;
}
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	in[v]++;
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

	cout<<"Depth of the graph is"<<g.depthOfGraph()<<endl;
	cout << "hahaha";
	return 0;
}