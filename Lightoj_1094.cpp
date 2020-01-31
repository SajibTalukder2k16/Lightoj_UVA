#include<bits/stdc++.h>
using namespace std;
#define mx 30001
vector<int>adj[mx];
vector<int>edge_costs[mx];
int dist[mx];
int Dijkstra(int source)
{
    priority_queue<pair<int,int> >dij_pr_queue;
    dist[source]=0;
    dij_pr_queue.push(make_pair(-dist[source],source));
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
                dist[v] = dist[u]+cost;
                dij_pr_queue.push(make_pair(-dist[v],v));
            }
        }

    }

}
int main()
{
    int test,cs;
    scanf("%d",&test);
    for(cs=1;cs<=test;cs++)
    {
        int node;
        scanf("%d",&node);
        for(int i=0;i<=node;i++)
            dist[i]=INT_MAX;
        for(int i=0;i<=node;i++)
        {
            adj[i].clear();
            edge_costs[i].clear();
        }
        int u,v,cost;
        for(int i=0;i<node-1;i++)
        {
            //cin>>u>>v>>cost;
            scanf("%d%d%d",&u,&v,&cost);
            adj[u].push_back(v);
            adj[v].push_back(u);
            edge_costs[u].push_back(cost);
            edge_costs[v].push_back(cost);
        }
        Dijkstra(u);
        int mxdist=0,mxdistindex=u;
        for(int i=0;i<node;i++)
        {
            if(dist[i]>mxdist)
            {
                mxdist=dist[i];
                mxdistindex=i;
            }
        }
        for(int i=0;i<=node;i++)
            dist[i]=INT_MAX;
        Dijkstra(mxdistindex);

        mxdist=0,mxdistindex=u;
        for(int i=0;i<node;i++)
        {
            if(dist[i]>mxdist)
            {
                mxdist=dist[i];
                mxdistindex=i;
            }
        }
        cout<<"Case "<<cs<<": "<<mxdist<<endl;
    }

}
