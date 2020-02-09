#include<bits/stdc++.h>
using namespace std;
#define mx_node 101
#define pii pair<int,int>
vector<int>adj_nodes[mx_node];
vector<int>adj_nodes_cost[mx_node];
#define mx_value 1100000
int nodes,edges;
int dist[mx_node];
int dijkstra(int source)
{
    priority_queue<pair<int,int> >pq;
    dist[source]=0;
    pq.push(make_pair(0,source));
    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int u = top.second;
        int sz = adj_nodes[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj_nodes[u][i];
            if(dist[u]+adj_nodes_cost[u][i]<dist[v])
            {
                dist[v]=dist[u]+adj_nodes_cost[u][i];
                pq.push(make_pair(-dist[v],v));
            }
        }
    }
    return dist[nodes];
}
int main()
{
    int test,cs;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        cin>>nodes>>edges;
        int u,v,c;
        for(int i=1;i<=nodes;i++)
        {
            dist[i]=mx_value;
            adj_nodes[i].clear();
            adj_nodes_cost[i].clear();
        }
        for(int i=0;i<edges;i++)
        {
            cin>>u>>v>>c;
            adj_nodes[u].push_back(v);
            adj_nodes[v].push_back(u);
            adj_nodes_cost[u].push_back(c);
            adj_nodes_cost[v].push_back(c);
        }
        int value = dijkstra(1);
        if(value==mx_value)
            cout<<"Case "<<cs<<": "<<"Impossible"<<endl;
        else
            cout<<"Case "<<cs<<": "<<value<<endl;
    }
}
