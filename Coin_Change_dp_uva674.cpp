#include<bits/stdc++.h>
using namespace std;
#define ll long long

///Coin Change dp
int coin[]={1,5,10,25,50};
int main()
{
    ll n;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(cin>>n)
    {
        //cout<<"CS: "<<n<<endl;
        ll dp[n+1]={0};
        dp[0]=1;
        for(int i=0;i<5;i++)
        {
            for(int j=coin[i],k=0;j<=n;j++,k++)
            {
                dp[j]=dp[j]+dp[k];
            }
        }
        cout<<dp[n]<<endl;
    }
}
