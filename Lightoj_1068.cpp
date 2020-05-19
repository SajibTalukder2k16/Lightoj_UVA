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
///lightoj 1068
int divisor;
ll dp[12][91][91][2];
ll countDivisible(vector<int>&vec,int idx,int remainder,int sumOfdigits,bool check_either_restricted)
{
    //cout<<sumOfdigits<<" output "<<remainder<<endl;
    if(idx==vec.size())
    {
        if(remainder%divisor==0 && sumOfdigits%divisor==0)
            return 1;
        else
            return 0;
    }
    if(dp[idx][remainder][sumOfdigits][check_either_restricted]!=-1)
    {
        return dp[idx][remainder][sumOfdigits][check_either_restricted];
    }
    int k;
    if(check_either_restricted)
        k=vec[idx];
    else
        k=9;
    ll ret=0;
    for(int i=0;i<=k;i++)
    {
        bool temp_restricted;
        if(check_either_restricted && i==vec[idx])
            temp_restricted=true;
        else
            temp_restricted=false;
        int temp_remainder = (remainder*10+i)%divisor;
        int temp_sumOfdigits = (sumOfdigits+i)%divisor;
        ret+=countDivisible(vec,idx+1,temp_remainder,temp_sumOfdigits,temp_restricted);
        ///ret+=zeroCount(idx+1,vec,temp_restricted,temp_first_zero,temp_zeros);
    }
    dp[idx][remainder][sumOfdigits][check_either_restricted] = ret;
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
    ll ans = countDivisible(vec,0,0,0,1);
    return ans;
}   
int main()
{
//    fileRead;
//    fileWrite
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        ll a,b;
        cin>>a>>b>>divisor;
        if(divisor>82)
        {
            lightoj_output<<0<<endl;
            continue;
        }
        if(divisor==1)
        {
            lightoj_output<<b-a+1<<endl;
            continue;
        }
        ll ans1=numberTodigits(a-1);
        ll ans2=numberTodigits(b);
        lightoj_output<<ans2-ans1<<endl;
        //cout<<numberTodigits(b)<<endl;;
    }
    return 0;
}
