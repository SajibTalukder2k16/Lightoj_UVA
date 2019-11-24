#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void factors(int num,ll divisors[])
{
    for(int i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            divisors[i]++;
            if(i!=num/i)
            {
                divisors[num/i]++;
            }
        }
    }
}
ll nC4(ll n)
{
    return n*(n-1)*(n-2)*(n-3)/24;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tests;
    cin>>tests;
    for(int cs=1;cs<=tests;cs++)
    {
        int n;
        cin>>n;
        int i,j,num;
        ll divisors[10001]={0};
        for(i=0;i<n;i++)
        {
            cin>>num;
            factors(num,divisors);
        }
        ll ans[10001]={0};
        for(i=10000;i>=1;i--)
        {
            ans[i]=nC4(divisors[i]);
            //cout<<divisors[i]<<" "<<ans[i]<<endl;
            for(j=i+i;j<=10000;j+=i)
            {
                ans[i]-=ans[j];
            }

        }
        cout<<"Case "<<cs<<": "<<ans[1]<<endl;
       // memset(divisors,0,10001*sizeof(divisors[0]));
    }
}
