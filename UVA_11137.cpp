#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cube_coins[22];
ll dp[10001][22];
int n;
ll foo(int cur_value,int cur_coin_index)
{
    //cout<<"Debug1"<<endl;
    //cout<<cur_value<<" "<<cur_coin_index<<endl;
    if(dp[cur_value][cur_coin_index]!=-1)
        return dp[cur_value][cur_coin_index];
    //cout<<"Debug1"<<endl;
    if(cur_value==0)
        return 1;
    if(cur_value<0 || cur_coin_index>21)
        return 0;
    ll ans1=0,ans2=0;
    if(cur_value-cube_coins[cur_coin_index]>=0)
    {
        //cout<<"Debug2: "<<c
        ll temp1=foo(cur_value-cube_coins[cur_coin_index],cur_coin_index);
        ll temp2=foo(cur_value-cube_coins[cur_coin_index],cur_coin_index+1);
        ans1=max(temp1,temp2);
    }
    ans2=foo(cur_value,cur_coin_index+1);
    dp[cur_value][cur_coin_index]=ans1+ans2;;
    //cout<<dp[cur_value][cur_coin_index]<<endl;
    return dp[cur_value][cur_coin_index];

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=21;i++)
        cube_coins[i]=i*i*i;
    while(cin>>n)
    {
        cout<<foo(n,1)<<endl;;
    }
}
