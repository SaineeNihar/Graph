#include<bits/stdc++.h>
using namespace std;
#define V 5
int minkey(int key[],bool mst[])
{
    int min=INT_MAX,index;
    for(int i=0;i<V;i++)
    {
        if(key[i]<min and mst[i]==false)
            min=key[i],index=i;
    }   
    return index;
}
void printMST(int graph[V][V],int par[])
{
    cout<<"MST is\n";
    for(int i=1;i<V;i++)
        cout<<par[i]<<" "<<i<<" : "<<graph[par[i]][i]<<endl;    

}
void primMST(int graph[V][V])
{
    int key[V],par[V];
    bool mst[V];
    for(int i=0;i<V;i++)
        key[i]=INT_MAX,mst[i]=false,par[i]=-1;
    key[0]=0;
    for(int count=0;count<V-1;count++)
    {
        int u=minkey(key,mst);
        mst[u]=true;
        for(int i=0;i<V;i++)
        {
            if(graph[u][i] and !mst[i] and graph[u][i]<key[i])
                par[i]=u,key[i]=graph[u][i];
        }
    }
    printMST(graph,par);
}
int main() 
{ 
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
 
    primMST(graph); 
 
    return 0; 
} 
 