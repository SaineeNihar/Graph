#include<bits/stdc++.h>
using namespace std;
class Graph
{
	public:
	int V;
	list<int>* adj;
	Graph(int v) {
		V = v;
		adj = new list<int>[V];
	}
	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};
void APUtil(Graph g, int u, bool vis[], int par[], int disc[], bool ap[], int low[])
{
	vis[u] = true;
	static int time = 0;
	disc[u] = low[u] = ++time;
	int children = 0;
	for (auto i = g.adj[u].begin(); i != g.adj[u].end(); i++)
	{
		int v = *i;
		if (!vis[v])
		{
			children++;
			par[v] = u;
			APUtil(g, v, vis, par, disc, ap, low);
			low[u] = min(low[u], low[v]);
			if (par[u] == -1 and children > 1)
				ap[u] = true;
			if (par[u] != -1 && low[v] >= disc[u])
				ap[u] = true;
		}
		else if (v != par[u])
			low[u] = min(low[u], disc[v]);
	}
}
void findAP(Graph g) {
	bool vis[g.V]; memset(vis, false, g.V);
	int par[g.V];  memset(par, -1, g.V);
	int disc[g.V];
	bool ap[g.V];  memset(ap, false, g.V);
	int low[g.V];
	for (int i = 0; i < g.V; i++)
	{
		if (!vis[i])
			APUtil(g, i, vis, par, disc, ap, low);
	}
	for (int i = 0; i < g.V; i++)
		if (ap[i])
			cout << i << " is the articulation point\n";
}
int main()
{
	Graph g(7);
	g.addEdge(0, 1); g.addEdge(2, 6);
	g.addEdge(1, 2); g.addEdge(5, 4);
	g.addEdge(3, 2); g.addEdge(0, 3);
	g.addEdge(3, 5);
	g.addEdge(3, 4);
	findAP(g);
	return 0;
}