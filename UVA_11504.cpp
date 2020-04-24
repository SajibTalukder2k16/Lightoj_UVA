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
vector<int>adj_node[100001];
int visited[100001]={0};
int discovering_time[100001]={0};
int finishing_time[100001]={0};
int timing = 0;
void dfs_visit(int u)
{
    visited[u]=grey;
    int len = adj_node[u].size();
    discovering_time[u]=++timing;
    for(int i=0;i<len;i++)
    {

        if(visited[adj_node[u][i]]==white)
        {
            dfs_visit(adj_node[u][i]);
        }
    }
    visited[u]=black;
    finishing_time[u]=++timing;
}
int main()
{

    //fileRead
    //fileWrite
    fastread
    int test;
    cin>>test;
    while(test--)
    {
        timing=0;
        int n,m;
        cin>>n>>m;
        map<int,int>ii_map;
        while(m--)
        {
            int node1,node2;
            cin>>node1>>node2;
            adj_node[node1].pb(node2);
        }
        memset(visited,0,sizeof visited);
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==white)
            {
                dfs_visit(i);
            }
        }
        vector<pair<int,int> >vec;
        for(int i=1;i<=n;i++)
            vec.pb(mp(-finishing_time[i],i));
        sort(vec.begin(),vec.end());
        memset(visited,0,sizeof visited);
        memset(discovering_time,0,sizeof discovering_time);
        memset(finishing_time,0,sizeof finishing_time);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[vec[i].second]==white)
            {
                dfs_visit(vec[i].second);
                cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<=n;i++)
            adj_node[i].clear();
    }
}
