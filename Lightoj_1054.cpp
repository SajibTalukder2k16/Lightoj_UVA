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
/// int x = bigmod( a, m - 2, m ); // (ax)%m = 1 when m is prime
///lightoj 1054
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
#define M 46345
#define mod_value 1000000007
bool check[M]={false};
vector<int>primes;
void sieve(int n)
{
    int sqrt_n = sqrt(n);
    for(int i=3;i<=sqrt_n;i+=2)
    {
        if(check[i]==false)
        {
            for(int j=i*i;j<=M;j+=2*i)
            {
                check[j]=true;
            }
        }
    }
}
vector<int>factors,factor_count;
void factorization(int num)
{
    int sqrt_n = sqrt(num);
    for(int i=0;i<primes.size() && primes[i]<=sqrt_n;i++)
    {
        //cout<<num<<endl;
        if(num==1)
            break;
        if(num==2)
        {
            factors.pb(num);
            factor_count.pb(1);
            break;
        }
        if(num<M)
        if(num%2==1 && check[num]==false)
        {
            factors.pb(num);
            factor_count.pb(1);
            num=1;
            break;
        }
        if(num%primes[i]==0)
        {
            int cnt=0;
            factors.pb(primes[i]);
            while(num%primes[i]==0)
            {
                num/=primes[i];
                cnt++;
            }
            factor_count.pb(cnt);
            sqrt_n=sqrt(num);
        }
    }
    if(num!=1)
    {
        factors.pb(num);
        factor_count.pb(1);
    }
}
int main()
{
    //fileWrite
    //fileRead
    sieve(M);
    primes.pb(2);
    for(int i=3;i<=M;i+=2)
        if(check[i]==false)
            primes.pb(i);
    int test;
    cin>>test;
    lightoj_test_case_loop(test)
    {
        ll n,m;
        cin>>n>>m;
        factors.clear();
        factor_count.clear();
        factorization(n);
        ll answer = 1;
        for(int i=0;i<factors.size();i++)
        {
            //cout<<factors[i]<<" "<<factor_count[i]<<endl;
            ll power = (ll)factor_count[i]*m;
            ll up = (BigMod(factors[i],power+1,mod_value)-1)%mod_value ;
            ll down = BigMod(factors[i]%mod_value-1,mod_value-2,mod_value);
            //cout<<up<<" "<<down<<endl;
            ll res = ((up%mod_value)*(down%mod_value))%mod_value;
            //cout<<res<<endl;
            answer=((answer%mod_value)*(res%mod_value))%mod_value;
        }
        lightoj_output<<answer<<endl;
    }
}
