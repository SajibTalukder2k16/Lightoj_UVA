#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define lightoj_test_case_loop(test) for(int cs=1;cs<=test;cs++)
#define lightoj_output cout<<"Case "<<cs<<": "
#define pb push_back
#define mp make_pair
#define white 0
#define grey 1
#define black 2
#define ll long long
int fx[]={+1,-1,0,0};
int fy[]={0,0,+1,-1};
int turnOn(int x,int pos) {
    return x | (1<<pos-1);
}
bool isOn(int N,int pos) {
    return (bool)(N & (1<<pos-1));
}
///lcs using dp
/*
int lcs_dp[31][31]={0};
int longest_common_sub(int i,int j,string &a,string &b)
{
    if(i==a.length()||j==b.length())
        return 0;
    if(lcs_dp[i][j]!=-1)
        return lcs_dp[i][j];
    int ans=0;
    if(a[i]==b[j])
        ans=1+longest_common_sub(i+1,j+1,a,b);
    else
        ans=max(longest_common_sub(i+1,j,a,b),longest_common_sub(i,j+1,a,b));
    return lcs_dp[i][j]=ans;

}
*/
///lightoj 1257
#define sz 30002
vector<int>adj_nodes[sz],adj_nodes_cost[sz];
//int current_time= 0;
int nodes;
//int discovery_time[30001]={0};
//int finishing_time[30001]={0};
bool visited[sz]={0};
int in[sz]={0};
int out[sz]={0};
///topological sort
/*
void dfs(int source)
{
    visited[source]=true;
    discovery_time[source]=++current_time;
    for(int i=0;i<adj_nodes[source].size();i++)
    {
        int v = adj_nodes[source][i];
        if(visited[v]==false)
            dfs(v);
    }
    finishing_time[source]=++current_time;
}
int topological_sort()
{
    for(int i=1;i<=nodes;i++)
    {
        if(visited[i]==false)
            dfs(i);
    }
    int max_value = -1;
    int first_node = -1;
    for(int i=1;i<=nodes;i++)
    {
        if(max_value<finishing_time[i])
            max_value=finishing_time[i],first_node=i;
    }
    //cout<<"Max finishing time: "<<max_value<<endl;
    current_time = 0;
    memset(discovery_time,0,sizeof discovery_time);
    memset(finishing_time,0,sizeof finishing_time);
    memset(visited,false,sizeof visited);
    return first_node;
}
*/
void dfs_highest_distance(int source)
{
    in[source]=0;
    visited[source]=true;
    int v;
    for(int i=0;i<adj_nodes[source].size();i++)
    {
        v=adj_nodes[source][i];
        int v_cost = adj_nodes_cost[source][i];
        if(visited[v]==false)
        {
            dfs_highest_distance(v);
            in[source]=max(in[source],in[v]+v_cost);
        }
    }
    return;
}
void out_distance(int u)
{
    int mx1,mx2,mx1cost,mx2cost;
    mx1=mx2=-1;
    mx1cost=mx2cost=-1;
    visited[u]=true;
    for(int i=0;i<adj_nodes[u].size();i++)
    {
        int v=adj_nodes[u][i];
        int v_cost=adj_nodes_cost[u][i];
        if(visited[v]==true)
            continue;
        if(in[v]+v_cost>mx1+mx1cost)
            mx2=mx1,mx1=in[v],mx2cost=mx1cost,mx1cost=v_cost;
        else if(in[v]+v_cost>mx2+mx2cost)
            mx2=in[v],mx2cost=v_cost;
    }
    for(int i=0;i<adj_nodes[u].size();i++)
    {
        int use=mx1;
        int use_cost = mx1cost;
        int v=adj_nodes[u][i];
        int v_cost = adj_nodes_cost[u][i];
        if(visited[v]==true)
            continue;
        if(mx1+mx1cost==in[v]+v_cost)
            use=mx2,use_cost=mx2cost;
        out[v]=max(out[u]+v_cost,use+v_cost+use_cost);
        out_distance(v);
    }
    return;
}
int main()
{
    int test_case;
    scanf("%d",&test_case);
    lightoj_test_case_loop(test_case)
    {
        scanf("%d",&nodes);
        int n1,n2,cost;
        for(int i=0;i<nodes-1;i++)
        {
            scanf("%d%d%d",&n1,&n2,&cost);
            n1++,n2++;
            adj_nodes[n1].pb(n2);
            adj_nodes[n2].pb(n1);
            adj_nodes_cost[n1].pb(cost);
            adj_nodes_cost[n2].pb(cost);
        }
        dfs_highest_distance(1);
        memset(visited,false,sizeof visited);
        out_distance(1);
        memset(visited,false,sizeof visited);
        printf("Case %d:\n",cs);
        for(int i=1;i<=nodes;i++)
        {
            printf("%d\n",max(in[i],out[i]));
            adj_nodes[i].clear();
            adj_nodes_cost[i].clear();
            in[i]=0;
            out[i]=0;
        }
    }
}
