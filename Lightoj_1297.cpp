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
#define ii_pair pair<int,int>
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
///BigMod
/*
ll BigMod(ll base,ll power,ll mod)
{
    if(power==0)
        return 1;
    if(power%2==1)
        return (base%mod)*(BigMod(base,power-1,mod)%mod)%mod;
    else
    {
        ll res = (BigMod(base,power/2,mod)%mod);
        return (res*res)%mod;

    }
}
*/
///lightoj 1297
int main()
{
    //fileRead
    //fileWrite
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        double length,width;
        cin>>length>>width;
        ///using ax2+bx+c=0 equation
        double a = 12.0;
        double b = -4*(length+width);
        double c = length*width;
        double sqrt_b2_4ac=sqrt(b*b-4*a*c);
        double value1=(-b+sqrt_b2_4ac)/(2*a);
        double value2=(-b-sqrt_b2_4ac)/(2*a);
        double ans1=value1*(length-2*value1)*(width-2*value1);
        double ans2=value2*(length-2*value2)*(width-2*value2);
        printf("Case %d: %.10lf\n",cs,max(ans1,ans2));
    }
}
