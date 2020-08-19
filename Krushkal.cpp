#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
	int u, v, w;
};
int find(int par[], int x)
{
	while (x != par[x])
		x = par[x];
	return x;
}
void Union(int par[], int  rank[], int r, int s)
{
	r = find(par,r);
	s = find(par,s);
	if (rank[r] > rank[s])
		par[s] = r;
	else
		par[r] = s;
	if (rank[r] == rank[s])
		rank[s] = rank[s] + 1;
}
void krushkal(Graph g[],int E,int v)
{  
	int par[v],rank[v];
	for (int i = 0; i < v; i++)
	{
		par[i] = i;
		rank[i] = 0;
	}
	vector<Graph>mst;
	for (int i = 0; i < E; i++)
	{
		cout << g[i].u << "--" << g[i].v << " = " << g[i].w << endl;
		if (find(par, g[i].u) == find(par, g[i].v))
		{
			cout << "skip\n\n";
			continue;
		}
		else
		{
			cout << "taken\n";	
			mst.push_back(g[i]);
			Union(par, rank, g[i].u,g[i].v);
		}
	}
	cout << "\nMST\n";
	for (auto it = mst.begin(); it != mst.end(); it++)
		cout << it->u << "-" << it->v << " = " << it->w << endl;
}
bool comp(Graph g1, Graph g2)
{
	return g1.w < g2.w;
}
int main()
{
	int E = 11;
	Graph g[E];
	int V = 7;
	{	g[0].u = 0;
	g[0].v = 2;
	g[0].w = 7;

	g[1].u = 0;
	g[1].v = 3;
	g[1].w = 5;

	g[2].u = 1;
	g[2].v = 2;
	g[2].w = 8;

	g[3].u = 1;
	g[3].v = 4;
	g[3].w = 5;

	g[4].u = 2;
	g[4].v = 4;
	g[4].w = 7;

	g[5].u = 2;
	g[5].v = 3;
	g[5].w = 9;

	g[6].u = 3;
	g[6].v = 4;
	g[6].w = 15;

	g[7].u = 3;
	g[7].v = 5;
	g[7].w = 6;

	g[8].u = 4;
	g[8].v = 5;
	g[8].w = 8;

	g[9].u = 6;
	g[9].v = 5;
	g[9].w = 11;

	g[10].u = 4;
	g[10].v = 6;
	g[10].w = 9;
}
	sort(g,g+ E, comp);
	for (int i = 0; i < E; i++)
		cout << g[i].u << "--" << g[i].v << " = " << g[i].w<<endl;
	cout << endl;
	krushkal(g, E, V);	
	return 0;
}
