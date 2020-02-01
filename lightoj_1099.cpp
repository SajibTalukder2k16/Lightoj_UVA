#include<bits/stdc++.h>
using namespace std;
#define mx 5001
vector<int>adj[mx];
vector<int>edge_costs[mx];
int dist[mx];
int second_best[mx];
int Dijkstra(int source)
{
    priority_queue<pair<int,int> >dij_pr_queue;
    dist[source]=0;
    dij_pr_queue.push(make_pair(-dist[source],source));
    int mn=15000;
    for(int i=0;i<adj[source].size();i++)
    {
        if(mn>2*edge_costs[source][i])
            mn=2*edge_costs[source][i];
    }
    second_best[source]=mn;
    while(!dij_pr_queue.empty())
    {
        pair<int,int>pr_u,pr_v;
        pr_u=dij_pr_queue.top();
        dij_pr_queue.pop();
        int u=pr_u.second;
        int v,cost;
        for(int i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            cost = edge_costs[u][i];
            if(dist[u]+cost<dist[v])
            {
                second_best[v]=min(second_best[v],dist[v]);
                dist[v] = dist[u]+cost;
                second_best[v]=min(second_best[v],dist[u]+3*cost);
                second_best[v]=min(second_best[v],second_best[u]+cost);
                dij_pr_queue.push(make_pair(-dist[v],v));
            }
            else if(dist[u]+cost>dist[v])
            {
                second_best[v]=min(second_best[v],cost+dist[u]);
                second_best[v]=min(second_best[v],second_best[u]+cost);
            }

        }

    }

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int test,cs;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        int nodes,edges;
        cin>>nodes>>edges;
        for(int i=1;i<=nodes;i++)
        {
            adj[i].clear();
            edge_costs[i].clear();
            dist[i]=INT_MAX;
            second_best[i]=INT_MAX;
        }
        int u,v,cost;
        for(int i=1;i<=edges;i++)
        {
            cin>>u>>v>>cost;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edge_costs[u].push_back(cost);
            edge_costs[v].push_back(cost);
        }
        Dijkstra(1);
        //cout<<"Best: "<<dist[nodes]<<endl;
        cout<<"Case "<<cs<<": "<<second_best[nodes]<<endl;
    }
}
