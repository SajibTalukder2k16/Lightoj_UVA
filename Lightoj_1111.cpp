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
vector<int>adj_node[1001];
int counter[1001]={0};
bool visited[1001]={false};
void dfs_visit(int u)
{
    visited[u]=true;
    counter[u]++;
    int len = adj_node[u].size();
    for(int i=0;i<len;i++)
    {
        if(visited[adj_node[u][i]]==false)
            dfs_visit(adj_node[u][i]);
    }
}
int main()
{
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        int people,cities,roads;
        cin>>people>>cities>>roads;
        int people_start_index[people];
        for(int i=0;i<people;i++)
            cin>>people_start_index[i];
        int n1,n2;
        for(int i=0;i<roads;i++)
        {
            cin>>n1>>n2;
            adj_node[n1].pb(n2);
        }
        for(int i=0;i<people;i++)
        {
            //cout<<"value: "<<people_start_index[i]<<endl;
            dfs_visit(people_start_index[i]);
            memset(visited,false,sizeof visited);
        }
        int cnt = 0;
        for(int i=1;i<=cities;i++)
            if(counter[i]==people)
                cnt++;
        cout<<"Case "<<cs<<": "<<cnt<<endl;
        memset(counter,0,sizeof counter);
        for(int i=1;i<=cities;i++)
            adj_node[i].clear();
            //cout<<counter[i]<<endl;
    }
}
