#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int>adj[], int V,int source)
{
    queue<int> q;
    q.push(source);
    int vis[V]={0};
    vis[source] = 1;
    vector<int>v;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        v.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    for(int i = 0; i < v.size();i++)
    cout<<v[i] <<" ";
}

bool dls(vector<int>adj[],vector<int>&vis,int source,int target,int level,int maxlevel){
    vis[source]=1;
    if(source==target and level<=maxlevel)
        return true;
    for(auto it:adj[source]){
        if(!vis[it] and level<=maxlevel){
            if(dls(adj,vis,it,target,level+1,maxlevel))
                return true;
        }
    }
}


void dfs(vector<int>adj[],vector<int>&vis,int source,vector<int>&vec){
    vis[source]=1;
    vec.push_back(source);
    for(auto it:adj[source]){
        if(!vis[it]){
            dfs(adj,vis,it,vec);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"BFS Traversal is: "<<endl;
    bfs(adj,n,4);
    cout<<endl;
    vector<int>vis(n,0);
    vector<int>vec;
    dfs(adj,vis,0,vec);
    cout<<"DFS Traversal is: "<<endl;
    for(auto it:vec){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int>vis1(n,0);
    cout<<"Target reached or not"<<endl;
    if(dls(adj,vis1,0,3,0,4))
    cout<<"true";
    else
    cout<<"false";
}