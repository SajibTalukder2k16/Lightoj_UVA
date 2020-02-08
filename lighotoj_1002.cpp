#include<bits/stdc++.h>
using namespace std;
struct edge_pro{
    int cost;
    int from;
    int to;
};
class compare
{
public:
    bool operator()(const edge_pro &p,const edge_pro &q)
    {
        return q.cost<p.cost;
    }
};
#define pii pair<int,int>
#define mx 501
int nodes,edges;
vector<int>adj_nodes[mx];
vector<int>adj_nodes_cost[mx];
int counting=0;
bool visited[mx]={false};
int parent[mx];
int mx_edge[mx]={0};
priority_queue<edge_pro,vector<edge_pro>,compare> pq;
int sum = 0 ;
void prims_mst(int source)
{
    //cout<<"Here: "<<counting<<" "<<source<<endl;
    visited[source]=true;
    int len=adj_nodes[source].size();
    for(int i=0;i<len;i++)
    {
        edge_pro temp;
        temp.from=source;
        int t1=adj_nodes[source][i];
        temp.to=t1;
        if(visited[t1]==false)
        {
            int t2=adj_nodes_cost[source][i];
            temp.cost=t2;
            pq.push(temp);
            //pq.push(make_pair(-t2,t1));
        }
    }
    //showpq();
    while(!pq.empty())
    {
        if(counting==nodes)
            return;
         edge_pro top_edge = pq.top();
         //cout<<-top_pair.first<<endl;
         int top_node = top_edge.to;
         if(visited[top_node]==false)
         {
             pq.pop();
             counting++;
             parent[top_node]=top_edge.from;
             //cout<<"Node: "<<top_node<<endl;
             //cout<<"Parent: "<<top_edge.from<<" cost: "<<top_edge.cost<<endl;
             mx_edge[top_node]=max(mx_edge[parent[top_node]],top_edge.cost);
             //cout<<top_node<<" "<<mx_edge[top_node]<<endl;
             sum+=top_edge.cost;
             prims_mst(top_node);
         }
         else
            pq.pop();
    }
}
int main()
{
    int test,cs;
    scanf("%d",&test);
    for(cs=1;cs<=test;cs++)
    {
        pq = priority_queue<edge_pro,vector<edge_pro>,compare >();
        scanf("%d%d",&nodes,&edges);
        for(int i=1;i<=nodes;i++)
        {
            visited[i]=false;
            mx_edge[i]=INT_MIN;
            parent[i]=i;
            adj_nodes[i].clear();
            adj_nodes_cost[i].clear();
        }
        int n1,n2,cost;
        for(int i=0;i<edges;i++)
        {
            //cin>>n1>>n2>>cost;
            scanf("%d%d%d",&n1,&n2,&cost);
            n1++,n2++;
            adj_nodes[n1].push_back(n2);
            adj_nodes[n2].push_back(n1);
            adj_nodes_cost[n1].push_back(cost);
            adj_nodes_cost[n2].push_back(cost);
        }
        int source;
        scanf("%d",&source);
        source++;
        counting++;
        sum=0;
        mx_edge[source]=0;
        prims_mst(source);
        printf("Case %d:\n",cs);
        //cout<<"Case "<<cs<<":"<<endl;
        for(int i=1;i<=nodes;i++)
        {
            if(mx_edge[i]==INT_MIN)
                printf("Impossible\n");
            else
                printf("%d\n",mx_edge[i]);
        }
        //cout<<sum<<endl;
        //cin>>sor
    }
}
