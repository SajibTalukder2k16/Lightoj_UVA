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
#define sz 10001
int nodes;
int dependency[sz]={0};
vector<int>adj_nodes[sz];
bool visited[sz];
void dfs(int source,int parent)
{
    visited[source]=true;
    for(int i=0;i<adj_nodes[source].size();i++)
    {
        int v = adj_nodes[source][i];
        if(v!=parent)
            --dependency[v];
    }
    for(int i=0;i<adj_nodes[source].size();i++)
    {
        int v = adj_nodes[source][i];
        if(visited[v]==false)
            dfs(v,source);
    }
}
vector<int>zero_dependency;
int main()
{
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        int lines;
        cin>>lines;
        string a,b;
        map<string,int>mp;
        nodes=0;
        memset(visited,false,sizeof visited);
        memset(dependency,0,sizeof dependency);
        for(int i=0;i<lines;i++)
        {
            cin>>a>>b;
            if(mp[a]==0)
                mp[a]=++nodes;
            if(mp[b]==0)
                mp[b]=++nodes;
            dependency[mp[b]]++;
            adj_nodes[mp[a]].pb(mp[b]);
        }
        for(int i=1;i<=nodes;i++)
            if(dependency[i]==0)
                zero_dependency.pb(i);
        //cout<<"Size of zero dependency: "<<zero_dependency.size()<<endl;
        for(int i=0;i<zero_dependency.size();i++)
            dfs(zero_dependency[i],zero_dependency[i]);
        bool res=true;
        for(int i=1;i<=nodes;i++)
            if(dependency[i]!=0)
            {
                //cout<<i<<" "<<dependency[i]<<endl;
                res=false;
                break;
            }
        zero_dependency.clear();
        if(res)
            lightoj_output<<"Yes"<<endl;
        else
            lightoj_output<<"No"<<endl;
        for(int i=1;i<=nodes;i++)
            adj_nodes[i].clear();
    }
}
