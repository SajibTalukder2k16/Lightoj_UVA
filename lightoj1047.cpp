#include<bits/stdc++.h>
using namespace std;
#define ll long long
int store[21][4];
int obj;
struct color{
    int ara[3];
};
color color_price[21];
int knapsack(int i,int j)
{
    //cout<<"debug1"<<endl;
    if(i==obj)
        return 0;

    //cout<<"debug2"<<endl;
    if(store[i][j]!=-1)
        return store[i][j];
    //cout<<"debug3"<<endl;
    if(i==0)
    {
        int out1 = color_price[i].ara[0] + knapsack(i+1,0);
        int out2 = color_price[i].ara[1] + knapsack(i+1,1);
        int out3 = color_price[i].ara[2] + knapsack(i+1,2);
        store[i][j]=min(out1,min(out2,out3));
        //cout<<i<<" "<<store[i][j]<<endl;
    }
    else
    {
        int out = 0;
        if(j==0)
        {
            int out2 = color_price[i].ara[1] + knapsack(i+1,1);
            int out3 = color_price[i].ara[2] + knapsack(i+1,2);
            //cout<<"when j = 0 "<<color_price[i-1].ara[0]<<" "<<out2<<" "<<out3<<endl;
            out=min(out2,out3);
        }
        else if(j==1)
        {
            int out2 = color_price[i].ara[0] + knapsack(i+1,0);
            int out3 = color_price[i].ara[2] + knapsack(i+1,2);
            //cout<<"when j = 1 "<<color_price[i-1].ara[1]<<" "<<out2<<" "<<out3<<endl;
            out=min(out2,out3);
        }
        else if(j==2)
        {
            int out2 = color_price[i].ara[0] + knapsack(i+1,0);
            int out3 = color_price[i].ara[1] + knapsack(i+1,1);
            //cout<<"when j = 2 "<<color_price[i-1].ara[2]<<" "<<out2<<" "<<out3<<endl;
            out=min(out2,out3);
        }
        //cout<<i<<" "<<j<<" "<<out<<endl;
        store[i][j]=out;

    }
    //store[i][j]=min(min(knapsack(i+1,0)+color_price[i].ara[0],knapsack(i+1,1)+color_price[i].ara[1]),knapsack(i+1,2)+color_price[i].ara[2]);
    //cout<<i<<" "<<store[i]<<endl;
    return store[i][j];
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
            cin>>color_price[i].ara[0]>>color_price[i].ara[1]>>color_price[i].ara[2];
        }
        for(i=0;i<=20;i++)
            for(j=0;j<3;j++)
                store[i][j]=-1;
        cout<<"Case "<<cs<<": "<<knapsack(0,0)<<endl;
    }
}
