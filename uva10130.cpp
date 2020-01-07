#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
}
