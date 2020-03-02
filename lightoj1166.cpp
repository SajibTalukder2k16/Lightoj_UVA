#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        int n;
        cin>>n;
        int ara[n+1];
        for(int i=1;i<=n;i++)
            cin>>ara[i];
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(i!=ara[i])
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(ara[j]==i)
                    {
                        swap(ara[i],ara[j]);
                        cnt++;
                    }
                }
            }
        }
        cout<<"Case "<<cs<<": "<<cnt<<endl;
    }
}
