// Template created by Jatin Mehra --> Cycle Detection using Disjoint Set 
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)

const int INF = 1e9;

int32_t main()
{
    fastIO1;
    fastIO2;

    int n,m ; // vertices and edges
    cin>>n>>m;

    vector<vector<int>> edges;
    for(int i=0 ; i<m ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    int src;
    cin>>src;

    vector<int> dist(n,INF);
    dist[src] = 0;

    for(int it = 0 ; it<n-1 ; it++)
    {
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            dist[v] = min(dist[v] , dist[u]+w); // Relaxation if possible
        }
    }

    for(auto i : dist) // shortest distance of all the vertices from source
    {
        cout<<i<<endl;
    }

    return 0;
}