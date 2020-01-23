#include<bits/stdc++.h>
using namespace std;
int row,col;

int grid[201][201];
int dp[201][201];
int foo(int i,int j)
{
    if(i>=1 && i<=row && j>=1 && j<=col)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        //cout<<i<<" "<<j<<endl;
        ///in this case,there are there ways to go from a point
        int ret = 0;
        ret = max(ret,foo(i+1,j)+grid[i][j]);
        ret = max(ret,foo(i+1,j+1)+grid[i][j]);
        ret = max(ret,foo(i+1,j-1)+grid[i][j]);
        dp[i][j]=ret;
        return dp[i][j];
    }
    else
        return 0;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int cs,test;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        memset(dp,-1,sizeof dp);
        cin>>row>>col;
        int i,j;
        int cntrow=1;
        for(i=1;i<=row;i++)
        {
            for(j=1;j<=col;j++)
            {
                cin>>grid[i][j];
            }
        }
        cout<<"Case "<<cs<<": "<<foo(1,1)<<endl;
    }
}
