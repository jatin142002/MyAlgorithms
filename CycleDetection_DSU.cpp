// Template created by Jatin Mehra --> Cycle Detection using Disjoint Set 
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
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }

    bool cycle = false;
    
    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int x = find_parent(u);
        int y = find_parent(v);

        if(x==y)
        {
            cycle = true;
            break;
        }
        else
        {
            Union(u,v);
        }
    }

    if(cycle)
    {
        cout<<"Cycle is present !!"<<endl;
    }
    else
    {
        cout<<"Cycle is not present !!"<<endl;
    }

    return 0;
}