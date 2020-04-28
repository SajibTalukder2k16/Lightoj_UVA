#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define white 0
#define grey 1
#define black 2
///lightoj 1049
map<int,bool>outdegree_check;
vector<int>adj_node[101];
vector<int>out_degree[101];
vector<int>out_cost[101];
int root_node=-1;
bool visited[101];
int cost;
void dfs_visit(int cur_node,int par_node)
{
    visited[cur_node]=true;
    if(cur_node==root_node)
        return;
    int len = adj_node[cur_node].size();
    if(len==0 || (len==1 && visited[adj_node[cur_node][0]]==true))
    {
        int l = out_degree[cur_node].size();
        for(int i=0;i<l;i++)
        {
            int node = out_degree[cur_node][i];
            if(visited[node]==false && node!=par_node)
            {
                cost+=out_cost[cur_node][i];
                dfs_visit(node,cur_node);
            }
        }
    }
    else
        for(int i=0;i<len;i++)
        {
            int node = adj_node[cur_node][i];
            if(visited[node]==false)
            {
                dfs_visit(node,cur_node);
            }
        }
}
int main()
{
    //fileRead
    //fileWrite
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        int no_of_node;
        cin>>no_of_node;
        int temp_node = no_of_node;
        int a,b,c;
        while(temp_node--)
        {
            cin>>a>>b>>c;
            adj_node[a].pb(b);
            if(outdegree_check[a])
                root_node=a;
            outdegree_check[a]=true;
            out_degree[b].pb(a);
            out_cost[b].pb(c);
        }
        int min_cost = INT_MAX;
        if(root_node==-1)
        {
            min_cost=0;
        }
        else
            for(int i=0;i<adj_node[root_node].size();i++)
            {
                dfs_visit(adj_node[root_node][i],root_node);
                min_cost=min(cost,min_cost);
                cost=0;
                memset(visited,0,sizeof visited);
            }
        cout<<"Case "<<cs<<": "<<min_cost<<endl;
        for(int i=1;i<=no_of_node;i++)
        {
            adj_node[i].clear();
            out_degree[i].clear();
            out_cost[i].clear();
        }
        outdegree_check.clear();
    }
}
