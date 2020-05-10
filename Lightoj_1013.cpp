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
int dp[31][31]={0};
int longest_common_sub(int i,int j,string &a,string &b)
{
    //cout<<a.length()<<" "<<b.length()<<endl;
    if(i==a.length()||j==b.length())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=0;
    if(a[i]==b[j])
        ans=1+longest_common_sub(i+1,j+1,a,b);
    else
        ans=max(longest_common_sub(i+1,j,a,b),longest_common_sub(i,j+1,a,b));
    return dp[i][j]=ans;

}
ll dp2[62][31][31]={0};
ll foo(int l,int i,int j,string &a,string &b)
{
    if(l==0 && i==0 && j==0)
        return 1;
    if(l==0 && (i!=0||j!=0))
        return 0;
    if(dp2[l][i][j]!=-1)
        return dp2[l][i][j];
    ll ans=0;
    if(a[a.length()-i]==b[b.length()-j])
    {
        ans=foo(l-1,i-1,j-1,a,b);
    }
    else
    {
        ll ans1=0,ans2=0;
        if(i!=0)
            ans1=foo(l-1,i-1,j,a,b);
        if(j!=0)
            ans2=foo(l-1,i,j-1,a,b);
        ans=ans1+ans2;
    }
    dp2[l][i][j]=ans;
    return ans;
}
///lightoj 1013
int main()
{
    //fileRead
    //fileWrite
    int test;
    cin>>test;
    lightoj_test_case_loop(test)
    {
        memset(dp,-1,sizeof dp);
        memset(dp2,-1,sizeof dp2);
        string s,w;
        cin>>s>>w;
        int lcs=longest_common_sub(0,0,s,w);
        int n=s.length();
        int m=w.length();
        int res=n+m-lcs;
        //cout<<lcs<<endl;
        ll no_of_unique_str=foo(res,n,m,s,w);//<<endl;
        lightoj_output<<res<<" "<<no_of_unique_str<<endl;

    }
}
