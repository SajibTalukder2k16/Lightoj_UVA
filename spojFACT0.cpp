#include<bits/stdc++.h>
using namespace std;
#define M 32000000
#define ll long long
int marked[M/64 + 2];
#define on(x) (marked[x/64]&(1<<((x%64)/2)))
#define mark(x) (marked[x/64]|=(1<<((x%64)/2)))
vector<int>primes;
void sieve(int n)
{
    int i,j;
    for(i=3;i*i<=n;i+=2)
    {
        if(!on(i))
        {
            primes.push_back(i);
            for(j=i*i;j<=n;j+=2*i)
            {
               mark(j);
            }
        }
    }
    //cout<<i<<endl;
}

void factorize(ll num)
{
    ll sqrtn =sqrt(num);
    int i;
    for(i=0;primes[i]<=sqrtn&&i<primes.size();i++)
    {
        int p=primes[i];
        if(num%p==0)
        {
            int cnt=0;
            while(num%p==0)
            {
                num/=p;
                cnt++;
            }
            if(num==1)
            {
                cout<<p<<"^"<<cnt<<endl;;
            }
            else
            {
                cout<<p<<"^"<<cnt<<" ";;
            }
            sqrtn= sqrt(num);
        }
    }
    if(num!=1)
    {
        cout<<num<<"^"<<1<<endl;
    }
}
int main()
{
    primes.push_back(2);
    sieve(M);
    int i;
    for(i=5655;i<=M;i+=2)
        if(!on(i))
            primes.push_back(i);
    ll num;
    while(true)
    {
        cin>>num;
        if(num==0)
            break;
        else
            factorize(num);
    }
}
