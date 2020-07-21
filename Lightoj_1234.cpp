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
/// int x = bigmod( a, m - 2, m ); // (ax)%m = 1 when m is prime

///lightoj 1234
const int M = 1e8+5;
const int N = 1e6+5;
double Harmonic[N];
void foo()
{
    double sum = 0;
    for(int i=1;i<=M;i++)
    {
        sum+=1.0/i;
        if(i%100==0)
        {
            //cout<<i/100<<" "<<sum<<endl;
            Harmonic[i/100]=sum;
        }
    }
    return;
}
int main()
{
    //fileRead
    //fileWrite
    foo();
    int test;
    cin>>test;
    lightoj_test_case_loop(test)
    {
        int n;
        cin>>n;
        int x = n/100;
        double res = Harmonic[x];
        //cout<<res<<endl;
        for(int i=(x*100)+1;i<=n;i++)
        {
            res+=1.0/i;
        }
        lightoj_output;
        printf("%.9lf\n",res);
        //<<res<<endl;
    }
}
