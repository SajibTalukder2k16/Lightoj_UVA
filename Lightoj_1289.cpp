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
#define M 100000000
int marked[M/64 + 2];
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
/// int x = bigmod( a, m - 2, m ); // (ax)%m = 1 when m is prime
const int sz = 5761460;
int primes[sz];
unsigned int store[sz];
unsigned int multipleOfPrimesPower(int n)
{
    int sqrt_n = sqrt(n);
    unsigned int ans =1;
    for(int i=0;primes[i]<=sqrt_n;i++)
    {
        unsigned int temp=n;
        temp/=primes[i];
        while(temp>=primes[i])
        {
            temp/=primes[i];
            ans*=primes[i];
        }
    }
    return ans;
}
int main()
{
    sieve(M);
    primes[0]=2;
    store[0]=2;
    int store_pos = 0;
    for(int i=3;i<=M;i+=2)
    {
        if(isPrime(i))
        {
            primes[++store_pos]=i;
            store[store_pos]=store[store_pos-1]*i;
        }
    }
    store_pos++;
    int test;
    cin>>test;
    lightoj_test_case_loop(test)
    {
        int n;
        cin>>n;
        int pos = lower_bound(primes,primes+store_pos,n)-primes;
        if(isPrime(n)==false)
            pos--;
        unsigned int ans = store[pos];
        unsigned int get_Multiple_of_primes_power=multipleOfPrimesPower(n);
        ans*=get_Multiple_of_primes_power;
        lightoj_output<<ans<<endl;
    }
}
