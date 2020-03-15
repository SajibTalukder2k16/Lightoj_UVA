#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{
    fastread
    int n;
    cin>>n;
    int p = pow(10,n/2)-1;
    int ara[p+1];
    ara[0]=0;
    map<int,int>mp;
    map<int,int>::iterator it;//mp;
    for(int i=0;i<=p;i++)
    {
        ara[i]=ara[i/10]+i%10;
        mp[ara[i]]++;
    }
    int sum = 0;
    if(n&1)
    {
        for(it=mp.begin();it!=mp.end();it++)
        {
            sum+=(it->second*it->second)*10;
        }
    }
    else
    {
        for(it=mp.begin();it!=mp.end();it++)
        {
            sum+=(it->second*it->second);
        }
    }
    cout<<sum<<endl;;
}
