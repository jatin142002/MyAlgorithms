// Template created by Jatin Mehra --> Kruskal's Algorithm (MST)
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)
const int N = 1e5+1;

vector<int> parent(N);
vector<int> size_set(N);

int find_parent(int x) // path compression
{
    if(x==parent[x])
    {
        return x;
    }
    return parent[x] = find_parent(parent[x]);
} 

void Union(int a , int b) // Union By Rank
{
    a = find_parent(a);
    b = find_parent(b);

    if(a!=b)
    {
        if(size_set[a] < size_set[b])
        {
            swap(a,b);
        }

        parent[b] = a;
        size_set[a]  += size_set[b];
    }
}

int32_t main()
{
    fastIO1;
    fastIO2;

    int v,e; // vertices , edges
    cin>>v>>e;

    vector<vector<int>> edges;

    for(int i=0 ; i<v ; i++)
    {
        parent[i] = i;
        size_set[i] = 1;
    }

    for(int i=0 ; i<e ; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back({w,a,b});
    }

    sort(edges.begin(),edges.end());

    int cost = 0;
    
    for(auto it : edges)
    {
        int w = it[0];
        int u = it[1];
        int v = it[2];
        int x = find_parent(u);
        int y = find_parent(v);

        if(x==y) // edge which will form cycle
        {
            continue; 
        }
        else
        {
            cout<<u<<" - "<<v<<endl;
            cost += w;
            Union(u,v);
        }
    }

    cout<<cost<<endl;
   
    return 0;
}