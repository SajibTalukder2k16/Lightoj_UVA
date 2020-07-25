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
///Sieve and Prime Factorization
/*
#define M 46345
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
*/
/*
int eulerPhi(int n)
{
    int sqrt_n=sqrt(n);
    int res = n;
    for(int i=0;i<primes.size() && primes[i]<=sqrt_n;i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
            {
                n/=primes[i];
            }
            res/=primes[i];
            res*=(primes[i]-1);
            sqrt_n=sqrt(n);
        }
    }
    if(n!=1)
    {
        res/=n;
        res*=(n-1);
    }
    return res;
}
*/
/// int x = bigmod( a, m - 2, m ); // (ax)%m = 1 when m is prime
///Lightoj 1007
#define M 1000009
int euler[M];
void eulerSieve(int n)
{
    for(int i=1;i<=n;i++)
        euler[i]=i;
    for(int i=2;i<=n;i++)
    {
        if(euler[i]==i)
        {
            for(int j=i;j<=n;j+=i)
            {
                euler[j]-=euler[j]/i;
            }
        }
    }

}
int main()
{
    eulerSieve(M);
    int test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        n--;
        ll sum;
        if(n%2==0)
            sum=(n/2)*(n+1);
        else
            sum=((n+1)/2)*n;
        ll res;
        if(n+1==2)
            res=1;
        else
        {
            res=euler[n+1]/2;
            res*=(n+1);
        }
        sum-=res;
        cout<<sum<<endl;
    }
}
