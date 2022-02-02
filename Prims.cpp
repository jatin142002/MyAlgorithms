// Template created by jatin mehra --> Prims Algorithm
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)

int visit_Prim[10001] = {0}; // to mark visit_Prim of each node

vector<pair<int,int>> adj[10001]; // weight of child node , child node itself

priority_queue <pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > q1; // weight of edge , curr node , par node

void Prims(pair<int,pair<int,int>> p1)
{
   int w = p1.first; // weight
   int b = p1.second.first; // curr node
   int a = p1.second.second; // par node
   
   q1.push({w,{b,a}});
   
   while(!q1.empty())
   {
       pair<int,pair<int,int>> temp = q1.top();
       q1.pop();
       
       int g = temp.first; // weight
       int x = temp.second.first; // curr node
       int y = temp.second.second; // par node
       
       if(visit_Prim[x]==1)
       {
           continue;
       }
       
       visit_Prim[x] = 1;
       if(y != -1)
       {
           cout<<"Curr_node : "<<x<<" , "<<"Par_Node : "<<y<<" , "<<"Weight : "<<g<<endl;
       }
       
       for(int i=0 ; i<adj[x].size() ; i++)
       {
           if(visit_Prim[adj[x][i].second] == 0)
           {
               q1.push({adj[x][i].first, {adj[x][i].second , x} } );
           }
       }
   }
}

int32_t main()
{
    fastIO1;
    fastIO2;
    
    int v,e; // v = total verices , e = total edges
    cin>>v>>e;
    
    for(int i=1 ; i<=e ; i++)
    {
        int a; // first node
        int b; // second node
        int w; // weight of the edge
        cin>>a>>b>>w;
        
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    
    Prims({ 0 , {0 , -1} });

   return 0;
}

//     0------3------4           0-3 : 40    2-3 : 10    4-6 : 8
//     |      |      |\          0-1 : 10    3-4 : 2     5-6 : 3
//     |      |      | \         1-2 : 10    4-5 : 3
//     1------2      5--6

//     0      3------4           
//     |      |      |           
//     |      |      |           
//     1------2      5--6

//    INPUT :                         
//    6 8
//    0 3 40
//    0 1 10
//    1 2 10
//    2 3 10
//    3 4 2
//    4 5 3
//    4 6 8
//    5 6 3

//    OUTPUT :
//    Curr_node : 1 , Par_Node : 0 , Weight : 10
//    Curr_node : 2 , Par_Node : 1 , Weight : 10
//    Curr_node : 3 , Par_Node : 2 , Weight : 10
//    Curr_node : 4 , Par_Node : 3 , Weight : 2
//    Curr_node : 5 , Par_Node : 4 , Weight : 3
//    Curr_node : 6 , Par_Node : 5 , Weight : 3

/*
https://leetcode.com/problems/min-cost-to-connect-all-points/  --> Disjoint Set is used for implementing Prims  

map <pair<int,int>,int> m1;
vector<pair<int,int>> adj[10001];
vector<int>parent;

int Parent(int node) 
{
    if(parent[node]!= node)
    {
        parent[node] = Parent(parent[node]);
    }
    return parent[node];
}
    
int minCostConnectPoints(vector<vector<int>>& points) {
    
    vector<pair<int,pair<int,int>>>dp;
   
    for(int i=0 ; i<points.size() ; i++)
    {
        m1[{points[i][0],points[i][1]}] = i;
    }
    
    for(int i=0 ; i<points.size() ; i++)
    {
          for(int j=i+1 ; j<points.size() ; j++)
          {
              
              int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
              dp.push_back({dist,{m1[{points[i][0],points[i][1]}],m1[{points[j][0],points[j][1]}]}});
          }
    }
    
    sort(dp.begin(),dp.end());
    int ans=0;
                          
    
    
    parent.resize(points.size());
    
    for(int i=0;i<points.size();i++)
        parent[i] = i;
    
    
    for(auto x: dp)
    {
        int n1 = Parent(x.second.first);
        int n2 = Parent(x.second.second);
        int v = x.first;
        
        
        
        if(n1 == n2)
            continue;
        
        parent[n1] = n2;
        ans+= v;
        
        
    }
       
    
    return ans;   
}

*/