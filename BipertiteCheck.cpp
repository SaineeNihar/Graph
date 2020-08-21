#include<bits/stdc++.h>
using namespace std;
#define V 4
bool isBipartite(int g[V][V],int u)
{
    vector<int> color(V,-1);
    color[u]=1;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();q.pop();

        if(g[u][u]==1)
            return false;
        for(int v=0;v<V;v++)
        {
            if(g[u][v] and color[v]==-1)
            {
                color[v]=1-color[u];
                q.push(v);
            }
            else if(g[u][v] and color[u]==color[v])
            return false;
        }
    }
    return true;
}

int main() 
{ 
    int G[][V] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
  
    isBipartite(G, 0) ? cout << "Yes" : cout << "No"; 
    return 0; 
} 