#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mx 100009
int main()
{
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        int n,h,ta,td;
        cin>>n>>h>>ta>>td;
        int ara[n];
        for(int i=0;i<n;i++)
            cin>>ara[i];
        if(ta*2<=td)
        {
            cout<<"Case "<<cs<<": "<<ta*n<<endl;
            continue;
        }
        sort(ara,ara+n);
        int cnt=0;
        for(int i=0,j=n-1;i<j;i++)
        {
            if(ara[i]+ara[j]<h && i<j)
            {
                cnt++;
                j--;
            }
            else
            {
                while(ara[i]+ara[j]>=h && i<j)
                    j--;
                if(ara[i]+ara[j]<h && i<j)
                {
                    cnt++;
                    j--;
                }
            }
        }
        cout<<"Case "<<cs<<": "<<cnt*td+(n-2*cnt)*ta<<endl;
    }
}
