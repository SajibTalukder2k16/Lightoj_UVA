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
///BigMod
/*
ll BigMod(ll base,ll power,ll mod)
{
    if(power==0)
        return 1;
    if(power%2==1)
        return (base%mod)*(BigMod(base,power-1,mod)%mod)%mod;
    else
    {
        ll res = (BigMod(base,power/2,mod)%mod);
        return (res*res)%mod;

    }
}
*/
#define sz 1001
vector<int>adj_node[sz];
int no_of_node;
int dp[sz][2]={0};
int minimum_vertex_cover(int cur_node,bool guard,int par)
{
    if(dp[cur_node][guard]!=-1)
        return dp[cur_node][guard];
    int ans = guard;
    for(int i=0;i<adj_node[cur_node].size();i++)
    {
        int v=adj_node[cur_node][i];
        if(v!=par)
        {
            if(guard==false)
            {
                ans+=minimum_vertex_cover(v,true,cur_node);
            }
            else
            {
                ans+=min(minimum_vertex_cover(v,true,cur_node),minimum_vertex_cover(v,false,cur_node));
            }
        }
    }
    dp[cur_node][guard]=ans;
    return dp[cur_node][guard];

}
int main()
{
    while(true)
    {
        cin>>no_of_node;
        if(no_of_node==0)
            break;
        memset(dp,-1,sizeof dp);
        int start_point = 1;
        for(int i=1;i<=no_of_node;i++)
        {
            int n,node;
            cin>>n;
            for(int j=0;j<n;j++)
            {
                cin>>node;
                adj_node[i].pb(node);
            }
        }
        if(no_of_node==1)
        {
            cout<<1<<endl;
            continue;
        }
        int res = min(minimum_vertex_cover(start_point,true,start_point),minimum_vertex_cover(start_point,false,start_point));
        cout<<res<<endl;
        for(int i=1;i<=no_of_node;i++)
            adj_node[i].clear();

    }
}
