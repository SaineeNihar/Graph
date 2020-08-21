#include<bits/stdc++.h>
using namespace std;
#define V 5
bool isSafe(bool graph[V][V],int path[],int pos,int i)
{
    if(graph[path[pos-1]][i]==0)
        return false;
    for(int v=0;v<pos;v++)
    {    if(path[v]==i)
            return false;
    }
    return true;
}
bool hamcycleUtil(bool graph[V][V],int path[], int pos)
{       
    if(pos==V)
    {
        if(graph[path[pos-1]][path[0]]==1)
            return true;
        else 
            return false;
    }
    for(int i=1;i<V;i++)
    {

        if(isSafe(graph,path,pos,i))
        {
            path[pos]=i;
            if(hamcycleUtil(graph,path,pos+1)==true)
                return true;
            path[pos]=-1;
        }
    }
    return false;
}
void printCycle(int path[])
{
    cout << "Solution Exists: Following is one Hamiltonian Cycle \n"; 
    for(int i=0;i<V;i++)
    {
        cout<<path[i]<<"-";
    }
    cout<<path[0]<<endl;
}

void hamcycle(bool graph[V][V])
{
    int  *path=new int[V];
    for (int i = 0; i < V; i++)  
        path[i] = -1;  
    path[0]=0;
    if(hamcycleUtil(graph,path,1)==false)
    {
        cout<<"No Ham Cycle exists";
        return;
    }
    printCycle(path);
}

int main()
{
    bool graph[V][V]=   {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}}; 
    hamcycle(graph); 
    bool graph2[V][V] = {{0, 1, 0, 1, 0},  
                         {1, 0, 1, 1, 1},  
                         {0, 1, 0, 0, 1},  
                         {1, 1, 0, 0, 0},  
                         {0, 1, 1, 0, 0}};  
  
    // Print the solution  
    hamcycle(graph2);
    return 0;
}