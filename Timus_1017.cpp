#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int cnt=0;
ll dp[501][501];
ll foo(int cur_size,int stair_size,int no_of_stairs)
{
    //cout<<cur_size<<endl;
    if(dp[cur_size][stair_size]!=-1)
        return dp[cur_size][stair_size];
    //cout<<"Debug1"<<endl;
    if(cur_size>n)
        return 0;
    if(cur_size==n && no_of_stairs!=1)
    {
        return 1;
    }
    //cout<<"Debug2"<<endl;
    ll ans=0;
    for(int i=stair_size+1;i<=n;i++)
    {
        if(cur_size+i<=n)
        {
            dp[cur_size+i][i]=foo(cur_size+i,i,no_of_stairs+1);
            ans+=dp[cur_size+i][i];
            //cout<<"Debug3: "<<ans<<endl;
        }
    }
    dp[cur_size][stair_size]=ans;
    return dp[cur_size][stair_size];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof dp);
    cin>>n;
    cout<<foo(0,0,0);;
}
