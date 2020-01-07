#include<bits/stdc++.h>
using namespace std;
#define ll long long
///time optimized 0 1 knapsack
int main()
{
    int items,cap;
    cin>>cap>>items;
    int i,j;
    node n[items];
    int cost[items];
    int weight[items];
    pair<int,int>pr;
    vector<pair<int,int> >vec;
    int c,w;
    for(int i=0;i<items;i++)
    {
        cin>>w>>c;
        vec.push_back(make_pair(w,c));
    }
    sort(vec.begin(),vec.end());
    vector<ll>dp(cap+1);
    for(int i=0;i<items;i++)
    {
        for(j=cap;j>=vec[i].first;j--)
            dp[j]=max(dp[j],dp[j-vec[i].first]+vec[i].second);
    }
    cout<<dp[cap]<<endl;

}
