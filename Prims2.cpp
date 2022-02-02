// Template created by jatin mehra -----> PRIM'S ALGORITHM FOR MST
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)

int v,e; // vertices , edges
const int N = 1e5+3;
vector<vector<int>> g[N]; // adjacencey list storing : child node , weight of edge
int cost = 0; // min cost
vector<int> dist(N) , parent(N);
vector<bool> visit_prim2(N);
const int INF = 1e9;

void PrimsMST(int source)
{
    for(int i=1 ; i<=v ; i++)
    {
        dist[i] = INF;
    }

    set<vector<int>> s; // storing  {weight , node}
    dist[source] = 0;
    s.insert({0,source});

    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);

        visit_prim2[x[1]] = true;
        int u = x[1]; // child node
        int w = x[0]; // weight of edge
        int v = parent[x[1]]; // parent node

        if(v != u)
        {
            cout<<"Child : "<<u<<" , "<<"Parent : "<<v<<" , "<<"Weight : "<<w<<endl;
        }

        cost += w;

        for(auto it : g[u])
        {
            if(visit_prim2[it[0]])
            {
                continue;
            }

            if(dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]] , it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]] , it[0]});
                parent[it[0]] = u;
            }
        }

    }
}

int32_t main()
{
    fastIO1;
    fastIO2;

    cin>>v>>e;

    for(int i=0 ; i<e ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    PrimsMST(0);

    cout<<"Cost : "<<cost<<endl;

    return 0;
}    