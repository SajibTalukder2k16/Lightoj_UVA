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
    int cs=1;
    while(test--)
    {
        int n;
        cin>>n;
        int ara[n];
        for(int i=0;i<n;i++)
            cin>>ara[i];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(ara[i]&1)
            {
                int val=0;
                while(ara[i])
                {
                    if(ara[i]%2==0)
                    {
                        val=ara[i]/2;
                        break;
                    }
                    ara[i]/=2;
                }
                ans^=val;
            }
            else
                ans^=(ara[i]/2);
        }
        cout<<"Case "<<cs++<<": ";
        if(ans>0)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;

    }
}
