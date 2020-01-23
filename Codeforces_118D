#include<bits/stdc++.h>
using namespace std;
int dp[101][101][11][11];
int cnt=0;
int x,y;
int foo(int footman,int horseman,int maxfoot,int maxhorse)
{
    if(dp[footman][horseman][maxfoot][maxhorse]!=-1)
        return dp[footman][horseman][maxfoot][maxhorse];
    //cout<<footman<<" "<<horseman<<" "<<maxfoot<<" "<<maxhorse<<endl;
    if(footman==0 && horseman==0)
        return 1;
    int ans1=0,ans2=0;
    if(footman>0 && maxfoot>0)
    {
        if(dp[footman-1][horseman][maxfoot-1][y]!=-1)
        {
            ans1=dp[footman-1][horseman][maxfoot-1][y]%100000000;
        }
        else
        {
            dp[footman-1][horseman][maxfoot-1][y]=foo(footman-1,horseman,maxfoot-1,y);
            ans1=dp[footman-1][horseman][maxfoot-1][y]%100000000;
        }
    }
    if(horseman>0 && maxhorse>0)
    {
        if(dp[footman][horseman-1][x][maxhorse-1]!=-1)
        {
            ans2=dp[footman][horseman-1][x][maxhorse-1]%100000000;;
        }
        else
        {
            dp[footman][horseman-1][x][maxhorse-1]=foo(footman,horseman-1,x,maxhorse-1);
            ans2=dp[footman][horseman-1][x][maxhorse-1]%100000000;
        }
    }
    //cout<<ans1<<" "<<ans2<<endl;
    dp[footman][horseman][maxfoot][maxhorse] = (ans1+ans2)%100000000;
    return dp[footman][horseman][maxfoot][maxhorse];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int footman,horseman,maxfoot,maxhorse;
    cin>>footman>>horseman>>maxfoot>>maxhorse;
    x=maxfoot;
    y=maxhorse;
    memset(dp,-1,sizeof dp);
    cout<<foo(footman,horseman,maxfoot,maxhorse)<<endl;;
    //cout<<cnt<<endl;
}
