#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tests;
    cin>>tests;
    int cs;
    for(cs=1;cs<=tests;cs++)
    {
        ll num;
        cin>>num;
        if(num%2==1)
        {
            cout<<"Case "<<cs<<": Impossible"<<endl;
        }
        else
        {
            for(int i=2;;i*=2)
            {
                if(num%i==0 && (num/i)%2==1)
                {
                    cout<<"Case "<<cs<<": "<<num/i<<" "<<i<<endl;
                    break;
                }

            }
        }
    }
}
