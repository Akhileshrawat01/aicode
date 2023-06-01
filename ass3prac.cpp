#include <bits/stdc++.h>
using namespace std;

// void bubsort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - (i + 1); j++)
//         {
//             if (arr[j] > arr[j + 1])
//                 swap(arr[j], arr[j + 1]);
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }


void selection_sort(){
   cout<<"Enter size of Array : ";
   int n;cin>>n;
   cout<<endl;
   cout<<"Enter the Elements of Array : ";
   vector<int> v(n);
   for(auto &x:v) cin>>x;
   for(int i=0;i<n-1;i++){
      int mx=i;
      for(int j=i;j<n;j++){
         if(v[j]<v[mx]) mx=j;
      }
      swap(v[i],v[mx]);
   }
   cout<<endl;
   cout<<"Array after Sorting is : "<<endl;
   for(auto &x:v) cout<<x<<" ";
   cout<<endl;
}

void prims(int V, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src = 0; // Taking vertex 0 as source
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u] == true)
            continue;
        inMST[u] = true; // Include vertex in MST
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

class DisjointSets
{
    int *parent, *rank;
    public:
    DisjointSets(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            rank[i] = 1;
            parent[i] = -1;
        }
    }
  
   int find(int i){
      if(parent[i]==-1)
         return i;
      return parent[i] = find(parent[i]);
   }
   void unite(int x, int y){
      int s1=find(x);
      int s2=find(y);
      if(s1!=s2){
         if(rank[s1]<rank[s2]){
            parent[s1]=s2;
         }
         else if(rank[s1]>rank[s2]){
            parent[s2]=s1;
         }
         else{
            parent[s2]=s1;
            rank[s1]+=1;
         }
      }
   }
};


void kruskal(int V, vector<vector<int>>&kgraph){
    sort(kgraph.begin(),kgraph.end());
    DisjointSets ss(V);
    int ans=0;
    for(auto edge:kgraph){
        int w=edge[0];
        int x=edge[1];
        int y=edge[2];
        if(ss.find(x)!=ss.find(y)){
            ss.unite(x,y);
            ans+=w;
            cout<<x<<"=="<<y<<"--"<<w<<endl;
        }
    }
    cout<<"mst "<<ans<<endl;

}


void dijikstra(int V, vector<pair<int, int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     vector<int> dist(V, INT_MAX);
    pq.push(make_pair(0, 0));
    dist[0] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v]>dist[u]+ weight)
            {
                dist[v]=dist[u]+ weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
     printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);


}

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    vector<pair<int, int>> adj[n];
    vector<vector<int>>kgraph;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        kgraph.push_back({w,u,v});
    }
    cout<<"after prims"<<endl;
    prims(n, adj);
    cout<<"after kruskal"<<endl;
    kruskal(n,kgraph);
    cout<<"after dijkstra"<<endl;
    dijikstra(n,adj);
    cout<<endl;
    selection_sort();
}