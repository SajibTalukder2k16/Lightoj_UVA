#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int w;
    int c;
};
int main()
{
    int items,cap;
    cin>>cap>>items;
    int i,j;
    node n[items];
    int cost[items];
    int weight[items];
    pair<int,int>pr;
    vector<pair<int,int> >vec;
    int c,w;
    for(int i=0;i<items;i++)
    {
        cin>>c>>w;
        vec.push_back(make_pair(w,c));
    }
    sort(vec.begin(),vec.end());
    vector<ll>dp(cap+1);
    for(int i=0;i<items;i++)
    {
        for(j=cap;j>=vec[i].first;j--)
            dp[j]=max(dp[j],dp[j-vec[i].first]+vec[i].second);
    }
    cout<<dp[cap]<<endl;

}

///space optimized knapsack
/*int main()
{
    int items,cap;
    cin>>cap>>items;
    int i,j;
    int cost[items];
    int weight[items];
    for(int i=0;i<items;i++)
        cin>>cost[i]>>weight[i];
    ll dp[2][cap+1];
    for(i=0;i<=cap;i++)
        dp[0][i]=0;
    for(i=0;i<items;i++)
    {
        for(j=1;j<=cap;j++)
        {
            if(weight[i]<=j)
            {
                dp[1][j]=max(dp[0][j],dp[0][j-weight[i]]+cost[i]);
            }
            else
            {
                dp[1][j]=dp[0][j];
            }
        }
//        for(j=1;j<=cap;j++)
//            cout<<dp[0][j]<<" ";
//        cout<<endl;
//        for(j=1;j<=cap;j++)
//            cout<<dp[1][j]<<" ";
//        cout<<endl;
        for(j=1;j<=cap;j++)
            dp[0][j]=dp[1][j];
    }
    cout<<dp[1][cap]<<endl;
}*/

/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
int store[1001][3001];
int weight[1001];
int cost[1001];
int cap;
int obj;




int knapsack(int i,int w)
{
    if(i==obj)
        return 0;
    int out1=0;
    if(store[i][w]!=-1)
        return store[i][w];
    if(weight[i]+w<=cap)
    {
        out1= cost[i]+knapsack(i+1,weight[i]+w);
    }
    int out2 = knapsack(i+1,w);
    store[i][w]=max(out1,out2);
    return max(out1,out2);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tests;
    cin>>tests;
    int cs;
    for(cs=1;cs<=tests;cs++)
    {
        cin>>obj;
        int i,j;
        for(i=0;i<obj;i++)
        {
            cin>>cost[i]>>weight[i];
        }
        int m;
        cin>>m;
        cap=0;
        int w;
        int ressum =0;
        for(int p=0;p<m;p++)
        {
            cin>>cap;
            for(i=0;i<=obj;i++)
            {
                for(j=0;j<=cap;j++)
                    store[i][j]=-1;
            }
            ressum+=knapsack(0,0);
        }
        cout<<ressum<<endl;
    }
}*/
//lightoj 1067
/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000003
#define p 1000000007
#define i64 long long
i64 F(i64 N,i64 P)
{
	if(P==0) return 1;
	if(P%2==0)
	{
		i64 ret=F(N,P/2);
		return ((ret%mod)*(ret%mod))%mod;
	}
	else return ((N%mod)*(F(N,P-1)%mod))%mod;

}
ll bigmod(ll a,ll b)
{
    if(b==0)
        return 1%mod;
    ll x = bigmod(a,b/2);
    x = (x*x)%mod;
    if(b%2==1)
        x = (x*a)%mod;
    return x;
}
ll nCr(ll n,ll r)
{
    ll mx,mn;
    if(n-r>r)
    {
        mx = n-r;
        mn = r;
    }
    else
    {
        mx = r;
        mn = n-r;
    }
    mx++;
    ll tempmx = 1;
    ll tempmn = 1;
    while(mx!=n)
    {
       tempmx = ((tempmx%mod)*(mx%mod)%mod);
       mx++;

////        tempmx=((tempmx%mod)*(mx%mod))%mod;
////        tempmn=((tempmn%mod)*(mn%mod));
////        ll inversemod = bigmod(tempmn,p-2);
//        tempmx*=mx;
//        //tempmx=((tempmx%mod)*(mx%mod))%mod;
//        //cout<<inversemod<<endl;
//        tempmn*=mn;
//        //tempmn=((tempmn%mod)*(mn%mod))%mod;
//        mn--;
//        mx++;
////        cout<<tempmx<<" "<<tempmn<<endl;
//        ll gcd = __gcd(tempmx,tempmn);
//        ll inversemod = bigmod(gcd,p-2);
//        //ll temp1 = F(gcd,p-2);
//        //cout<<inversemod<<" "<<temp1<<endl;
//        tempmx = ((tempmx%mod)*(inversemod%mod))%mod;
//        //tempmx/=gcd;
//        //tempmn/=gcd;
//        tempmn = ((tempmn%mod)*(inversemod%mod))%mod;
    }
    while(mn--)
    {
        tempmn = ((tempmn%mod)*(mn%mod)%mod);
    }
    cout<<tempmx<<" "<<tempmn<<endl;
    //tempmn = bigmod(tempmn,p-2);

    return tempmx/tempmn;


    //return tempmx;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tests,cs;
    cin>>tests;
    for(cs=1;cs<=tests;cs++)
    {
        ll n,r;
        cin>>n>>r;
        cout<<"Case "<<cs<<": "<<nCr(n,r)<<endl;
    }
}
/*#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
#define ll long long
#define M 100000000
int marked[M/64 + 2];
#define mod 4294967296
#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n) {
  for (int i = 3; i * i < n; i += 2) {
    if (!on(i)) {
      for (int j = i * i; j <= n; j += i + i) {
        mark(j);
      }
    }
  }
}

bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}
ll bigmod(ll a,ll b)
{
    if(b==0)
        return 1%mod;
    ll x = bigmod(a,b/2);
    x = (x*x)%M;
    if(b%2==1)
        x = (x*a)%mod;
    return x;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve(M);
    vector<int>vec_primes;
    vector<ll>primes_value;
    primes_value.push_back(1);
    vec_primes.push_back(2);
    for(int i=3;i<=M;i+=2)
        if(isPrime(i))
            {
                vec_primes.push_back(i);
                primes_value.push_back(1);
            }
        int n;
        cin>>n;
        vector<pair<int,int> >vec;
        ll ans[n];
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            ans[i]=1;
            vec.push_back(make_pair(num,i));
        }
        sort(vec.begin(),vec.end());
        ll temp= 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;vec_primes[j]<=vec[i].first && j<vec_primes.size();j++)
            {
                while(true)
                {

                    if(primes_value[j]*vec_primes[j]<=vec[i].first)
                        primes_value[j]=(primes_value[j]%mod)*vec_primes[j];
                    else
                        break;
                }
                ans[vec[i].second]=((ans[vec[i].second]%mod)*(primes_value[j]%mod))%mod;;
            }
        }
        for(int i=0;i<n;i++)
            cout<<"Case "<<i+1<<": "<<ans[i]<<endl;

}*/
/*
ll n;
        cin>>n;
        ll sum =1;
        for(int i=0;vec_primes[i]<=n;i++)
        {
            ll temp = 1;
            ll value = 1;
            //int cnt
            while(temp<=n)
            {
                value = temp;
                temp*=(ll)vec_primes[i];
            }
            sum = ((sum%mod)*(value%mod))% mod;
            //ump[vec[i]]=value;
        }
        cout<<"Case "<<cs<<": "<<sum<<endl;
*/

