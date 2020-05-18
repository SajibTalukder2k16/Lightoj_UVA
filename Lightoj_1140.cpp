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
///lightoj 1140 trying using digit dp
ll dp[12][12][2][2];
ll zeroCount(int idx,vector<int>&vec,bool check_either_restricted,bool check_first_zero,int no_of_zeros)
{
    if(idx==vec.size())
        return no_of_zeros;
    if(dp[idx][no_of_zeros][check_either_restricted][check_first_zero]!=-1)
    {
        return dp[idx][no_of_zeros][check_either_restricted][check_first_zero];
    }
    int k;
    if(check_either_restricted)
        k=vec[idx];
    else
        k=9;
    ll ret=0;
    if(check_first_zero)
    {
        for(int i=1;i<=k;i++)
        {
            bool temp_restricted;
            if(check_either_restricted && i==vec[idx])
                temp_restricted=true;
            else
                temp_restricted=false;
            ll temp_ans = zeroCount(idx+1,vec,temp_restricted,0,no_of_zeros);
            ret+=temp_ans;
        }
        ret+=zeroCount(idx+1,vec,0,1,0);
    }
    else
    {
        for(int i=0;i<=k;i++)
        {
            bool temp_restricted,temp_first_zero;
            if(check_either_restricted && i==vec[idx])
                temp_restricted=true;
            else
                temp_restricted=false;
            int temp_zeros = no_of_zeros;
            if(i==0)
                temp_zeros++;
            ll temp_ans = zeroCount(idx+1,vec,temp_restricted,0,temp_zeros);
            ret+=temp_ans;
        }
    }
    dp[idx][no_of_zeros][check_either_restricted][check_first_zero]=ret;
    return ret;
}
ll numberTodigits(ll num)
{
    vector<int>vec;
    if(num<0)
        return 0;
    if(num<=9)
        return 1;
    while(num)
    {
        vec.pb(num%10);
        num/=10;
    }
    reverse(vec.begin(),vec.end());
    memset(dp,-1,sizeof dp);
    ll ans = zeroCount(0,vec,1,1,0)+1;
    //cout<<ans<<endl;

    return ans;
}
int main()
{
    //fileRead
    //fileWrite
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        ll n,m;
        cin>>n>>m;
        ll ans1=numberTodigits(n-1);
        ll ans2=numberTodigits(m);
        ll ans = ans2-ans1;
        lightoj_output<<ans<<endl;
        //cout<<<<endl;;
    }
}
