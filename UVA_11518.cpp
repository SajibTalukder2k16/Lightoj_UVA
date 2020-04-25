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
///UVA 11518
vector<int>adj_node[10001];
int visited[10001]={0};
int timing = 0;
void dfs_visit(int u)
{
    //cout<<"Visited: "<<u<<endl;
    visited[u]=grey;
    int len = adj_node[u].size();
    timing+=2;
    for(int i=0;i<len;i++)
    {
        if(visited[adj_node[u][i]]==white)
        {
            dfs_visit(adj_node[u][i]);
        }
    }
    visited[u]=black;
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
        int n,m,l;
        cin>>n>>m>>l;
        while(m--)
        {
            int node1,node2;
            cin>>node1>>node2;
            adj_node[node1].pb(node2);
        }
        int z;
        memset(visited,0,sizeof visited);
        while(l--)
        {
            cin>>z;
            if(visited[z]==white)
                dfs_visit(z);
        }
        int cnt = 0;
        for(int i=1;i<=n;i++)
            adj_node[i].clear();
        cout<<timing/2<<endl;
    }
}
