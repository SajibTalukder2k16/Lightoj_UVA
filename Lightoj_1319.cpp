#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 1000005
int main()
{
    //fileRead
    //fileWrite
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        int n;
        cin>>n;
        int div[n],rem[n];
        vector<pair<int,int> >vec;
        for(int i=0;i<n;i++)
        {
            cin>>div[i]>>rem[i];
            vec.push_back(mp(-rem[i],div[i]));
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++)
        {
            vec[i].first=vec[i].first*(-1);
        }
        ll ans=vec[0].first;
        ll dv=vec[0].second;
        for(int i=1;i<n;i++)
        {
            ll limit=vec[i].second;
            ll remainder=vec[i].first;
            ll val=-1;
            for(int j=0;j<=limit;j++)
            {
                if(((j*dv+ans)%limit)==remainder)
                {
                    val=j;
                    break;
                }
            }
            ans=dv*val+ans;
            dv=dv*limit;
        }
        cout<<"Case "<<cs<<": "<<ans<<endl;
    }
}
