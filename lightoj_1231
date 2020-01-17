#include<bits/stdc++.h>
using namespace std;
///coin change dp
int dp[51][21][5001];
int make;
int coin_number;
int coins[101];
int no_of_coins[101];
int foo(int coin_state,int no_of_coin_of_coinstate, int coin_amount)
{
    //cout<<"debug 1"<<endl;
    if(coin_state>=coin_number)
    {
        if(coin_amount==0)
            return 1;
        else
            return 0;
    }
    int ret1=0,ret2=0;
    //cout<<"Before: "<<"State: "<<coin_state<<" coin_no: "<<no_of_coin_of_coinstate<<" amount: "<<coin_amount<<" "<<dp[coin_state][no_of_coin_of_coinstate][coin_amount]<<endl;
    if(dp[coin_state][no_of_coin_of_coinstate][coin_amount]==-1)
    {
        //cout<<"debug2"<<endl;
        //cout<<no_of_coin_of_coinstate<<" "<<no_of_coins[coin_state]<<endl;
       if(coin_amount-coins[coin_state]>=0 && no_of_coins[coin_state]>no_of_coin_of_coinstate)
            ret1=foo(coin_state,no_of_coin_of_coinstate+1,coin_amount-coins[coin_state])%100000007;
       ret2=foo(coin_state+1,0,coin_amount)%100000007;
    }
    else
    {
        //out<<"After But Inside: "<<dp[coin_state][no_of_coin_of_coinstate][coin_amount]<<endl;
        return dp[coin_state][no_of_coin_of_coinstate][coin_amount];
    }
//    if(ret1!=0 || ret2!=0)
//    {
//        cout<<coin_state<<" "<<coin_amount<<endl;
//        cout<<ret1<<" "<<ret2<<endl;
//        cout<<endl;
//    }
    dp[coin_state][no_of_coin_of_coinstate][coin_amount] =ret1+ret2;
    //cout<<"After: "<<dp[coin_state][no_of_coin_of_coinstate][coin_amount]<<endl;
    return dp[coin_state][no_of_coin_of_coinstate][coin_amount]%100000007;

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cs,test,i;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        memset(dp,-1,sizeof dp);
        cin>>coin_number;
        cin>>make;
        for(i=0;i<coin_number;i++)
            cin>>coins[i];
        for(i=0;i<coin_number;i++)
            cin>>no_of_coins[i];
        cout<<"Case "<<cs<<": "<<foo(0,0,make)<<endl;
    }
//    cin>>coin_number;
//    int i;
//
//    cin>>make;
//    cout<<foo(0,0,make)<<endl;
}
