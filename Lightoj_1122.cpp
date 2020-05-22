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
///lightoj 1122
int m,n;
int ara[11];
int dp[11][11]={0};
int foo(int previous_value,int sz)
{
    if(dp[previous_value][sz]!=-1)
        return dp[previous_value][sz];
    if(sz==n)
        return 1;
    int ans1=0,ans2=0;;
    int ret = 0;
    for(int i=0;i<m;i++)
    {
        if(sz==0)
        {
            ans2=foo(ara[i],sz+1);
            ret+=ans2;
        }
        else if(sz<n && abs(ara[i]-previous_value)<=2)
        {
            ans1=foo(ara[i],sz+1);
            ret+=ans1;
        }
    }
    dp[previous_value][sz]=ret;
    return dp[previous_value][sz];
}
int main()
{
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        cin>>m>>n;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<m;i++)
            cin>>ara[i];
        lightoj_output<<foo(0,0)<<endl;
    }
}
