/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<int>ar[100];
int in[101];
int low[101];
int vis[101];
int timer;
void dfs(int node, int par)
{
    vis[node]=1;
    in[node]=timer;
    low[node]=timer;
    timer++;
    bool fDFSLeaf = true;
    int minBack = INT_MAX;
    int minLow = INT_MAX;
    for(int child : ar[node])
    {
        if(child==par)
        {
            continue;
        }
        if(vis[child]==1)
        {
            //edge node - child is a back edge
            minBack = min(minBack,in[child]);
        }
        else
        {
            fDFSLeaf = false;
            //edge node - child is a forward edge
            dfs(child,node);
            minLow = min(minLow, low[child]);
        }
    }
    if (fDFSLeaf){
        low[node] = min(in[node], minBack);
    }
    else{
        low[node] = min(min(in[node], minBack), minLow);
    }
    if(low[node] == in[node] and par != -1)
    {
        cout<<par<<"-"<<node<<" is a bridge\n";
    }
    out[node]=timer++;
}

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        ar[x].push_back(y);
        ar[y].push_back(x);
    }
    dfs(0,-1);

    return 0;
}
