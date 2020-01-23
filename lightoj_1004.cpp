#include<bits/stdc++.h>
using namespace std;
int row;
int grid[201][201];
int dp[201][201];
int foo(int i,int j)
{
    if(i>=1 && i<=(row*2-1) && j>=1 && j<=(row-abs(i-row)))
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        //cout<<i<<" "<<j<<endl;
        int ret = 0;
        if(i<row)
        {
            ret = max(ret,foo(i+1,j)+grid[i][j]);
            ret = max(ret,foo(i+1,j+1)+grid[i][j]);
        }
        else
        {
            ret = max(ret,foo(i+1,j-1)+grid[i][j]);
            ret = max(ret,foo(i+1,j)+grid[i][j]);
        }
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
        cin>>row;
        int i,j;
        int cntrow=1;
        for(i=1;i<=(row*2-1);i++)
        {
            for(j=1;j<=cntrow;j++)
            {
                cin>>grid[i][j];
            }
            if(i<row)
                cntrow++;
            else
                cntrow--;
        }
        cout<<"Case "<<cs<<": "<<foo(1,1)<<endl;
//        cntrow=1;
//        for(i=1;i<=(row*2);i++)
//        {
//            for(j=1;j<=cntrow;j++)
//            {
//                cout<<grid[i][j]<<" ";
//            }
//            cout<<endl;
//            if(i<row)
//                cntrow++;
//            else
//                cntrow--;
//        }
    }
}
