#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define M 5000002
int marked[M/64 + 2];
ll euler[M+2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n) {
  for (ll i = 3; i<=n; i += 2) {
    if (!on(i)) {
      for (ll j = i ; j <= n; j += i ) {
        if(j%2==1)
            mark(j);
        euler[j]=(euler[j]/i)*(i-1);
      }
    }
  }
}

bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(int i=1;i<M;i++)
    {
        euler[i]=i;
        if(i%2==0)
            euler[i]/=2;
    }
    sieve(M);
    euler[0]=0;
    for(int i=2;i<M;i++)
    {
        euler[i]=euler[i]*euler[i];
        euler[i]+=euler[i-1];
    }
    int test,cs;
    scanf("%d",&test);
    int a,b;
    for(cs=1;cs<=test;cs++)
    {
        scanf("%d%d",&a,&b);
        a--;
        //cout<<euler[b]<<" "<<euler[a]<<endl;
        //cout<<"Case "<<cs<<": "<<euler[b]-euler[a]<<endl;
        printf("Case %d: %llu\n",cs,euler[b]-euler[a]);
    }
    return 0;
}
