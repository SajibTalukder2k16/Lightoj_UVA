#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mod 1000000007
#define pi 3.141593
#define pb push_back
int main()
{
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        int n,num;
        cin>>n;
        map<int,int>mp;
        map<int,bool>last;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            if(mp[abs(num)]==0)
                vec.push_back(abs(num));
            mp[abs(num)]++;
            if(num<0)
                last[abs(num)]=1;
            else
                last[abs(num)]=0;
        }
        int sz=vec.size();
        ll sum=0;
        for(int i=0;i<sz;i++)
        {
            ll val=vec[i];
            if(last[val]==1)
                sum+=(-val);
            else
                sum+=val;
        }
        cout<<"Case "<<cs<<": "<<sum<<endl;
    }
}
