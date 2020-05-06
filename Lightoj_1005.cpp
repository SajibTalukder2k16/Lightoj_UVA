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
///lightoj 1005
ll dp[31][31]={0};
ll combination(int n,int r)
{
    if(r==1 || n-r==1)
        return n;
    if(n==r || r==0)
        return 1;
    if(dp[n][r]!=0)
        return dp[n][r];
    dp[n][r]=combination(n-1,r)+combination(n-1,r-1);
    return dp[n][r];
}
int main()
{
    int test;
    cin>>test;
    lightoj_test_case_loop(test)
    {
        int n,k;
        cin>>n>>k;
        if(k>n)
            lightoj_output<<0<<endl;
        else
        {
            ll ans = combination(n,k);
            while(k>0)
                ans*=n,k--,n--;
            lightoj_output<<ans<<endl;
        }
    }

}
