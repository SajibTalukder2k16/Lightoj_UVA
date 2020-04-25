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
///UVA 280
vector<int>adj_node[101];
int visited[101]={0};
int cnt=0;
void dfs_visit(int u)
{
    int len = adj_node[u].size();
    for(int i=0;i<len;i++)
    {
        if(visited[adj_node[u][i]]==white)
        {
            cnt++;
            visited[adj_node[u][i]]=grey;
            dfs_visit(adj_node[u][i]);

        }
    }
}
int main()
{
    fastread
    //fileRead
    //fileWrite
    while(true)
    {
        int no_of_node;
        cin>>no_of_node;
        if(no_of_node==0)
            break;
        while(true)
        {
            int cur_node;
            cin>>cur_node;
            if(cur_node==0)
                break;
            int connected_node;
            while(true)
            {
                cin>>connected_node;
                if(connected_node==0)
                    break;
                adj_node[cur_node].pb(connected_node);
            }
        }
        int n;
        cin>>n;
        //cout<<"Here Ok"<<endl;
        while(n--)
        {
            int starting_node;
            cin>>starting_node;
            memset(visited,0,sizeof visited);
            dfs_visit(starting_node);
            cout<<no_of_node-cnt;//endl;
            cnt=0;
            for(int i=1;i<=no_of_node;i++)
                if(visited[i]==white)
                    cout<<" "<<i;
            cout<<endl;
        }
        for(int i=1;i<=no_of_node;i++)
            adj_node[i].clear();
    }
}
