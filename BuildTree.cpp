#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
    public:
    char data;
    TreeNode *lc=nullptr;
    TreeNode *rc=nullptr;
    TreeNode(char d)
    {
        data=d;
    }
};
void levelorder(TreeNode *root)
{
    TreeNode *tmp;
    queue<TreeNode*> q;
    if(!root)
    return;
    q.push(root);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        cout<<tmp->data<<" ";
        if(tmp->lc)
        q.push(tmp->lc);
        if(tmp->rc)
        q.push(tmp->rc);

    }
    cout<<endl;
}
int find(vector<char> v,int i,int j,char data)
{
    for(int t=i;t<j;t++)
    {
        if(v[t]==data)
            return t;
    }
}
TreeNode *buildTree(vector<char>in,vector<char> pre,int i,int j)
{
    int pi=0;
    TreeNode *tmp;
    if(i>j)
        return nullptr;
    tmp=new TreeNode(pre[pi]);
    pi++;
    if(i==j)
        return tmp;
    int ini=find(in,i,j,tmp->data);
    tmp->lc=buildTree(in,pre,i,ini-1);
    tmp->rc=buildTree(in,pre,ini+1,j);
    return tmp;
    
}

int main()
{
    vector<char> in{'D','B','E','A','F','C'};
    vector<char> pre{'A','B','D','E','C','F'};
    TreeNode *root=buildTree(in,pre,0,in.size()-1);
    levelorder(root);
    return 0;
}