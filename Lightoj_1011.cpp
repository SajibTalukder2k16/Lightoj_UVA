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
///lightoj 1011
int maze[17][17];
int dp[17][1<<17];
int n;
bool check[17]={false};
int turnOn(int x,int pos) {
    return x | (1<<pos-1);
}
bool isOn(int N,int pos) {
    return (bool)(N & (1<<pos-1));
}
int foo(int i,int mask)
{
    if(i>n)
        return 0;
    if(dp[i][mask]!=-1)
    {
        return dp[i][mask];
    }
    if (mask == (1<<n) -1) {
        return 0;
    }
    int ans=-1;
    for(int j=1;j<=n;j++)
    {
        if(isOn(mask,j)==false)
        {
            int res = foo(i+1,turnOn(mask,j)) + maze[i][j];
            ans=max(ans,res);
        }
    }
    dp[i][mask]=ans;
    return dp[i][mask];
}
int main()
{
    //fileRead
    //fileWrite
    int test;
    cin>>test;
    lightoj_test_case_loop(test)
    {
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cin>>maze[i][j];
        }
        lightoj_output<<foo(1,0)<<endl;;
    }
}
