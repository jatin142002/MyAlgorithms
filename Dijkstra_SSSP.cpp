// Template created by Jatin Mehra --> Dijkstra's Algorithm for Single Source Shortest Path
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)
const int inf = 1e9 ;

int v,e;
vector<int> dist(100001,inf);
vector<vector<pair<int,int>>> adj(100001);  // child node , weight

void Dijkstra(int source)
{
    dist[source] = 0;
    set<pair<int,int>> s1; // weight , node
    s1.insert({0,source});

    while(!s1.empty())
    {
        auto x = *(s1.begin());
        s1.erase(x);

        for(auto it : adj[x.second])
        {
            if(dist[it.first] > dist[x.second] + it.second)
            {
                s1.erase({dist[it.first] , it.first});
                dist[it.first] = dist[x.second] + it.second;
                s1.insert({dist[it.first] , it.first});
            }
        }
    }
}

int32_t main()
{
    fastIO1;
    fastIO2;

    cin>>v>>e; // enter no. of vertices and edges

    for(int i=0 ; i<e ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[u].push_back({u,w}); // -------> in case of directed graph we can comment this out.
    }

    int source;
    cin>>source;

    Dijkstra(source);

    for(int i=1 ; i<=v ; i++)
    {
        if(dist[i]<inf)
        {
            cout<<"Node : "<<i<<" , "<<"Dist from source : "<<dist[i]<<endl;
        }
        else
        {
            cout<<"Node : "<<i<<" , "<<"Not eachable from source"<<endl;
        }
    }

    return 0;
}