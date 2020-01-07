#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int w;
    int c;
};
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
        cin>>c>>w;
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

///space optimized knapsack
/*int main()
{
    int items,cap;
    cin>>cap>>items;
    int i,j;
    int cost[items];
    int weight[items];
    for(int i=0;i<items;i++)
        cin>>cost[i]>>weight[i];
    ll dp[2][cap+1];
    for(i=0;i<=cap;i++)
        dp[0][i]=0;
    for(i=0;i<items;i++)
    {
        for(j=1;j<=cap;j++)
        {
            if(weight[i]<=j)
            {
                dp[1][j]=max(dp[0][j],dp[0][j-weight[i]]+cost[i]);
            }
            else
            {
                dp[1][j]=dp[0][j];
            }
        }
//        for(j=1;j<=cap;j++)
//            cout<<dp[0][j]<<" ";
//        cout<<endl;
//        for(j=1;j<=cap;j++)
//            cout<<dp[1][j]<<" ";
//        cout<<endl;
        for(j=1;j<=cap;j++)
            dp[0][j]=dp[1][j];
    }
    cout<<dp[1][cap]<<endl;
}*/
///sample 0 1 knapsack using dp
/*
int store[1001][3001];
int weight[1001];
int cost[1001];
int cap;
int obj;
int knapsack(int i,int w)
{
    if(i==obj)
        return 0;
    int out1=0;
    if(store[i][w]!=-1)
        return store[i][w];
    if(weight[i]+w<=cap)
    {
        out1= cost[i]+knapsack(i+1,weight[i]+w);
    }
    int out2 = knapsack(i+1,w);
    store[i][w]=max(out1,out2);
    return max(out1,out2);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tests;
    cin>>tests;
    int cs;
    for(cs=1;cs<=tests;cs++)
    {
        cin>>obj;
        int i,j;
        for(i=0;i<obj;i++)
        {
            cin>>cost[i]>>weight[i];
        }
        int m;
        cin>>m;
        cap=0;
        int w;
        int ressum =0;
        for(int p=0;p<m;p++)
        {
            cin>>cap;
            for(i=0;i<=obj;i++)
            {
                for(j=0;j<=cap;j++)
                    store[i][j]=-1;
            }
            ressum+=knapsack(0,0);
        }
        cout<<ressum<<endl;
    }
}*/
