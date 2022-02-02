// Template created by Jatin Mehra --> Disjoint Set 

//(Naive Method)
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)

int parent[10001]; // this will store parent of each member initialize it with each memeber itself .

int find(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    return find(parent[v]);
}

void Union(int a , int b)
{
    a = find(a);
    b = find(b);
    if(a != b)
    {
        parent[b] = a;
    }
}

// Path Compression
int find1(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    parent[v] = find1(parent[v]);
    return parent[v];
}

// Union By Rank
int size1[10001]; // this will store size of each set intialize it with 1
void Union1(int a , int b)
{
    a = find1(a);
    b = find1(b);

    if(a==b)
    {
        return;
    }
    if(size1[a] < size1[b])
    {
        swap(a,b);
    }
    parent[b] = a;
    size1[a] += size1[b];
}

int32_t main()
{
    fastIO1;
    fastIO2;

    cout<<"Disjoint Set Concept !!"<<endl;

    return 0;
}